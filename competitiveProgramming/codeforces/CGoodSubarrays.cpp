#include <bits/stdc++.h>
using namespace std;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

void solve() {
    int n; cin >> n;
    vector<int> nums(n); string sa; cin >> sa; for(int i = 0; i < n; i++){ nums[i] = sa[i] - '0'; }
    vector<int> pfs(n+1);
    for(int i = 1; i <= n; i++){ pfs[i] = pfs[i-1] + nums[i-1]; }

    // //below is a half-finished garbage. restart or use the previous submission
    // int l=1,r=1,count=0,zeros=0;
    // 
    // for(; l <= n; l++){
    //     if(r-l > 0 && pfs[r]-pfs[l-1] == r-l){ count++; cout << l << " " << r << endl; }
    //     while( <= r-l && r <= n){
    //         sum += nums[r++];
    //         if(nums[r] == 0)zeros++;
    //         if(sum == r-l && r-l > 0){ count++; cout << l << " " << r << endl; }
    //     }
    //     sum -= nums[l];
    //     if(nums[l] == 0)zeros--;
    // }
    // cout << count << endl;
    // return;

   // 0 0 0 2



//
// 120
// 113
// 11011
//
// 6000000000000053
    //       l    r
    //       in the range it is 5
    //       this is valid.
    //       increase the right by 3 then it is now 8
    //       this is only valid if using PFS, the range from l-3 to l is equal to zero
    //       OR you could just have your sum counter, and check if(range from right end back sum distance) then it is yes, else no.
    //       there is always one place you need to check and it is if the sum from the right back to the beginning is valid I think
    //       EXCEPT FOR ZEROS YOU IDIOT

// 120
//
// 1300
// 1113 // using dp[i] = dp[i-1] + count_added
// 1002 // using: count_added only
// count_added depends on how many zeros in your range
    // possible to have a number higher than 1 if: number before the left side is a 1 OR number before it is a zero, but there is some number like 2 behind that to make up for the 0
//
    //
// 10210
// 4


// 11200

// 000050000
    // answer: 5

// 10000500001
// 2000005000002
    // answer: 7

    // if on your border, you have a zero, you could possibly move further to find a digit that is big enough.

// 90511
    //
    //
    //
    //
    //
    // sum in reverse order to know how much you could move backwards? postfix sum?

// 10000500001
// 76666611111 // postfs
// 11111666667 // prefs

    //more useful when you use it for range queries. postfs[5] - postfs[0] == 0 so you know the length of the array can increase by 0 to 5 by including these
    //useless info

// array  ->120
// length 1 111
//     |  2  12
//     v  3   3
        
        












    // vector<int> pfs(n+1);
    // for(int i = 1; i <= n; i++){ pfs[i] = pfs[i-1] + nums[i]; }

    // int j = 1;
    // int sum = 0;
    // int good = 0;
    // // if sum is X, try jumping j to X to start.
    // // if not, then increment i and try j all over again.
    // //
    // //
    // for(int i = 1; i <= n && j <= n; i++){
    //     //cout << 1 << n << endl;
    //     int l = pfs[i-1];
    //     //rhs = pfs[i+rhs]-l != 0 ? (i + pfs[i+rhs] - l) : 1
    //     int prev = 0;
    //     for(int rhs = 0; pfs[i+rhs] - l <= n-i+1 && i+rhs <= n; (pfs[i+rhs] - l - prev == 0 ? rhs+= 1 : rhs = pfs[i+rhs] - l)){ // while our pfs is within a valid range
    //         int r = pfs[i+rhs];
    //         prev = r - l;
    //         if(r-l == rhs + 1){good++;};
    //     }
    // }

    // cout << good << endl;
}

int main(){ int testcase; cin >> testcase; while(testcase--){ solve(); } }//{solve();}



