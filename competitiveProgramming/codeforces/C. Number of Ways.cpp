#include <bits/stdc++.h>
using namespace std;

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
int rec(vector<int>& nums, int target, vector<vector<int>>& memo, int start=0, int group=0){
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
}
