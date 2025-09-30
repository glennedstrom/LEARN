#include <bits/stdc++.h>
using namespace std;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

void solve() {
    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++)cin >> nums[i];

    // prev_teeth / cur_teeth * prev_ratio = cur_ratio

    double prev_teeth = nums[0];
    double cur_teeth = nums[1];
    double prev_ratio = 1;
    double cur_ratio = 1;
    for(int i = 1; i < n; i++){
        cur_ratio = prev_teeth / cur_teeth * prev_ratio;



        prev_ratio = cur_ratio;
    }

    if(abs(cur_ratio - 1) <= 1e-6){
        YES
    }
    else NO
}

int main(){ int testcase; cin >> testcase; while(testcase--){ solve(); } }//{solve();}
