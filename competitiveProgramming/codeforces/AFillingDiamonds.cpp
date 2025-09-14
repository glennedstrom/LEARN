#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
// EPS for doubles; do 1e-6 for floats
#define EPS 1e-9
#define INF 1e9

void solve() {
    unsigned long long n; cin >> n;
    cout << n << endl;return; // is there a shit pattern I can't see?
    if(n < 3){cout << n << endl;return;}

    unsigned long long i = 3;
    unsigned long long dp0 = 1;
    unsigned long long dp1 = 2;
    unsigned long long dp2 = 3;
    unsigned long long cur;

    for(; i < n; i++){
        cur = dp2 + dp1;

        //cout << cur << endl;

        dp0=dp1; dp1=dp2; dp2=cur;
    }
    cout << dp2 << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}



