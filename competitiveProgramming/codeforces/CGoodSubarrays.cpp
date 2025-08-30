#include <bits/stdc++.h>
using namespace std;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

void solve() {
    int n; cin >> n;
    vector<int> nums(n+1);
    string sa; cin >> sa;
    int idx = 1;
    for(auto& i : sa){ nums[idx++] = i - '0'; }

    vector<int> pfs(n+1);
    for(int i = 1; i <= n; i++){ pfs[i] = pfs[i-1] + nums[i]; }

    int j = 1;
    int sum = 0;
    int good = 0;
    // if sum is X, try jumping j to X to start.
    // if not, then increment i and try j all over again.
    //
    //
    for(int i = 1; i <= n && j <= n; i++){
        //cout << 1 << n << endl;
        int l = pfs[i-1];
        //rhs = pfs[i+rhs]-l != 0 ? (i + pfs[i+rhs] - l) : 1
        int prev = 0;
        for(int rhs = 0; pfs[i+rhs] - l <= n-i+1 && i+rhs <= n; (pfs[i+rhs] - l - prev == 0 ? rhs+= 1 : rhs = pfs[i+rhs] - l)){ // while our pfs is within a valid range
            int r = pfs[i+rhs];
            prev = r - l;
            if(r-l == rhs + 1){good++;};
        }
    }

    cout << good << endl;
}

int main(){ int testcase; cin >> testcase; while(testcase--){ solve(); } }//{solve();}



