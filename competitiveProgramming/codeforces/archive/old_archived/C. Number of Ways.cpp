#include <bits/stdc++.h>
#include <cstdint>
using namespace std;

// only loop if you have the right value for ALL of them. Otherwise, keep adjusting until you get the proper sum again.
//
// Make the second loop start after the first loop ends to get the second sum.
//
// After you have a valid sum, you have 2 options: adjust the boundry of the first pointer, adjust the boundary of the second pointer
//
// OH! All you need is to count all locations the first location is valid and all the locations the second is valid.
//
// The first one can ONLY be valid if the second is valid
//
// This means you can check each one independantly and CALCULATE how many there are
//
// FORMULA: count1 * count2 = total count
//
// for the second count: you can count at any point where the first count is valid.
//
// NOTE: Issue with current algorithm: it doesn't consider cases where you have 0. if you have 0 then it can have 0 0 0 0 -1 1 -1 1 0 0 0 where the answers CAN overlap
// Handle zeros separately as a combinatorics problem?
// does it work fine for non-zero average sums?
// GOLDEN QUESTION:
// How to count how many there are for the targetSum==zero edge case...
//
// 0 0 0 0 0
//  | |
//  |   |
//  |     |
//    | |
//    |   |
//      | |
//
// n = zero_count - 2
// n*(n+1)/2
//
// 0 0 0 0 0 0
//  | |
//  |   |
//  |     |
//  |       |
//    | |
//    |   |
//    |     |
//      | |
//      |   |
//        | |
//
//
// WITH LATEST TEST CASE:
// check if the current algorithm has zeros nearby like 
// 1 2 3 -3 3 2 1
//
// every time you go back to zero in the second one, there is a "collision" between the first and the second
// 1 2 3 -3 3 2 1
// 1 3 6 3  6 8 9 ; 2 times made it separated by a 6
//     3 0 3 2 1
// FOR each 0 collision in the second group, keep track of how many could be in the first group
// 2nd group: 1st 3 has only 1 in the first group. second 3 has 2 in the first group.
// You need to do it like this:
//
// FIND FIRST 3 THEN BREAK; ONE 3 IN THE FIRST GROUP SO FAR; 
// *we hit 3 in the second group* ADD TO TOTAL COUNT: 1 (first group) * 1 (second group)
// KEEP GOING: 3-3 = 0; FOUND A ZERO! ADD ONE TO THE FIRST GROUP (first group = 2 now)
// FOUND ANOTHER 3: ADD 2 (first group) * 1 (second group)
//
// second group is always 1, you only need to add the first group count so far!
// NOTE: WORKING SOLUTION ABOVE, FIX IT BELOW
//
// 3 and -3 are zeros
// that lets us group the 3s like 1,2 or 1,2,3,-3
// this makes it harder

#define impossible cout << 0 << endl; return 0;


int main()
{

    long long n; cin >> n;
    vector<long long> nums(n);
    long long targetSum = 0;
    for(long long i = 0; i < n; i++){cin >> nums[i]; targetSum += nums[i];}

    if(targetSum == 0){
        //zero edge case
        long long zero_count = 0;
        long long run = 0;
        for(long long i = 0; i < n; i++){
            run += nums[i];
            if(run == 0){ zero_count++; }
        }
        //cout << "ZC:";
        long long n = zero_count-2;
        cout << n*(n+1)/2 << endl;
        return 0;
    }


    // cout << "TS: " << targetSum << endl;
    if(targetSum % 3 == 0) targetSum /= 3;
    else{ impossible;}





    long long count1=0, count2=0;
    long long sum1=0, sum2=0;
    long long sum2_start = INT64_MAX;

    for(long long i = 0; i < n; ++i){
        if(sum1 == targetSum) {
            ++count1;
            sum2_start = i; // get the first sum2_start; likely can grab the last for efficiency
            break; // grab the first one
            // cout << "valid: " << sum1  << " : " << targetSum << endl;
            // cout << "sum2_start: " << sum2_start << endl;
        }
        sum1 += nums[i];
    }

    // count from the right end and look at indices?
    for(long long i = sum2_start; i < n; ++i){
        sum2 += nums[i];
        if(sum2 == targetSum) {
            //cout << "valid: " << sum2  << " : " << targetSum << endl;
            count2 += count1; // add current count to our final count
        }
        if(sum2 == 0){
            ++count1; // found another that fits in the first group
        }
    }

    //cout << count1 << ' ' << count2 << endl;
    cout << count2 << endl;
}

//  for the first to be valid, the second one also must be valid; I don't believe it is possible for the highest 1st pointer and the lowest second pointer to overlap;
    //  WRONG!
//  I have no proof of this though.
//
// NOTE: WRONG

//  Proof: intermediate values between A and B are of values 0
//  For any intermediate values between that are not 0 then it would disrupt one of the sums.
//  All sums must be valid so therefore they cannot overlap
//  0000000000 00000000000 0000000




// possibly a complicated two pointers solution where you 
// NO, it has negative numbers and stuff
/*int main(){

    int n; cin >> n;
    vector<int> nums(n);
    int target = 0;
    for(int i = 0; i < n; i++){cin >> nums[i]; target += nums[i];}

    if(target % 3 != 0){
        cout << 0 << endl;
        return 0;
    }

    target /= 3;

    int l = 0, r = 0;

    int g[3] = {0,0,0}; // groups
    for(; l < n; l++){

        if(g[0] == target){

        }
    }
}*/
// TODO: find REPEATED subproblems or a different approach
/*int rec(vector<int>& nums, int target, vector<vector<int>>& memo, int start=0, int group=0){
    if(start >= nums.size()){return 0;}
    if(memo[group][start] != -1){ return memo[group][start]; cout << "memo: " << memo[group][start] << endl;}
    int tot = 0;
    if(group == 2){
        //compute to the end and return true or false
        //for(int i = start; i < nums.size(); i++){tot+=nums[i];}
        memo[group][start] = 1;//tot == target;
        return memo[group][start];
    }
    //otherwise, increase current group size to the end and recursive call if the sum is equal to target
    int solutions = 0;
    for(int i = start; i < nums.size(); i++){
        tot += nums[i];
        if(tot == target){
            solutions += rec(nums, target, memo, i+1, group+1);
        }
    }
    memo[group][start] = solutions;
    return memo[group][start];
}

int main()
{
    int n; cin >> n;
    vector<int> nums(n);
    int target = 0;
    for(int i = 0; i < n; i++){cin >> nums[i]; target += nums[i];}

    if(target % 3 != 0){
        cout << 0 << endl;
        return 0;
    }

    target /= 3;

    vector<vector<int>> memo(3, vector<int>(n, -1));

    cout << rec(nums, target, memo) << endl;
}*/
