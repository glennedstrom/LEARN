#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
* URL:     https://codeforces.com/problemset/problem/1195/C
* Date:    Thu Oct  2 03:29:52 2025
* Contest: Codeforces Round 574 (Div. 2):
* Problem: C. Basketball Exercise
* Limits:  2000ms, 256MB
*/

void precalc(){
    // optional
}

void solve() {
    int n; cin >> n;

    vector v(2, vector<int>(n)); for(auto& i : v[0])cin >> i; for(auto& i : v[1])cin >> i;

    vector dp(2, vector<ll>(n));
    dp[0][0] = v[0][0];
    dp[1][0] = v[1][0];
    for(int i = 1; i < n; i++){
        dp[0][i] = max(dp[0][i],dp[1][i-1] + v[0][i]); // previous from lane 0
        dp[1][i] = max(dp[1][i],dp[0][i-1] + v[1][i]); // previous from lane 1

        if(i >= 2){
            // two back straight
            dp[0][i] = max(dp[0][i], dp[0][i-2] + v[0][i]);
            dp[1][i] = max(dp[1][i], dp[1][i-2] + v[1][i]);

            // two back swap
            dp[0][i] = max(dp[0][i], dp[1][i-2] + v[0][i]);
            dp[1][i] = max(dp[1][i], dp[0][i-2] + v[1][i]);
        }
    }
    for(auto& row : v){
        for(auto& x : row){
            cout << x << ' ';
        }
        cout << endl;
    }
    cout << endl;
    for(auto& row : dp){
        for(auto& x : row){
            cout << x << ' ';
        }
        cout << endl;
    }
    cout << endl;
    cout << max(dp[0][n-1], dp[1][n-1]);
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);precalc();solve();}
