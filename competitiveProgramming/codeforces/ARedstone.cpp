#include <bits/stdc++.h>
using namespace std;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

vector<int> nums;

// double gear_ratio(){
//     double prev_ratio = 1;
//     for(int i = 1; i < nums.size(); i++){
//         prev_ratio = nums[i-1] / nums[i] * prev_ratio;
//         
//     }
//     return prev_ratio;
// }
// as long as each high number has a low number that divides into it, it smoothens out to 1.
//
// take the high teeth then find divisors. If found, divide the bigger, set the smaller to 1


void solve() {
    int n; cin >> n;
    nums.resize(n);
    for(int i = 0; i < n; i++)cin >> nums[i];
    sort(nums.rbegin(),nums.rend());
    bool works = false;
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] == nums[i-1]){
            works = true;
            break;
        }
    }
    if(works){
        YES;
        return;
    }
    NO;
    return;

    for(auto& g : nums){ cout << g << " "; } cout << endl;
    //no matter what you put in the middle, it only works if the first and the last are the same.
    //basically all you need is a duplicate detector


    for(int i = 0; i < n; i++){ // biggest to smallest.
        cout << nums[i] << " : ";
        for(int j = n-1; j > i; j--){
            if(nums[i] % nums[j] == 0){
                cout << "(" << nums[i] << "," << nums[j] << ") ";
                nums[i] /= nums[j];
                nums[j] = 1;
            }
            if(nums[i] == 1)break;
        }
        cout << nums[i] << endl;
        if(nums[i] != 1) {NO; return;}
    }
    YES
}

int main(){ int testcase; cin >> testcase; while(testcase--){ solve(); } }//{solve();}
