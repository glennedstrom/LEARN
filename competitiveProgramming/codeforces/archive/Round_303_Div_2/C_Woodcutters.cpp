#include <cstdint>
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
* URL:     https://codeforces.com/problemset/problem/545/C
* Date:    Sat Oct  4 20:37:09 2025
* Contest: Codeforces Round 303 (Div. 2):
* Problem: C. Woodcutters
* Limits:  1000ms, 256MB
*/

void precalc(){
    // optional
}

struct Node{
    ll x;
    ll height;
};
//1--2 ; d=3-0 ; i=3 ; 3 +- 2 = [1,5] 1 > 0 so good
//1---2 ; d=4-0 ; 4 - 2 - 1 > 0
void solve() {
    int n; cin >> n;

    vector<Node> t(n); // {x, height}already sorted
    for(int i = 0; i < n; i++){ int x,h; cin >> x >> h; t[i] = {x,h}; }
    if(n <= 2){ cout << n << endl; return; }
    t.push_back({INT64_MAX,0}); // append infinity so we can always fall to the right

    vector dp(n, vector<int>(2)); // 0 for fall left, 1 for fall right?
    dp[0][0] = 1; // the first tree can fall to the left
    dp[0][1] = (t[1].x-t[0].x) - t[0].height > 0; // the first tree can fall to the right
    for(int i = 1; i < n; i++){
        ll distL = t[i].x - t[i-1].x;
        //fall left
        dp[i][0] = max(dp[i-1][0] + (distL - t[i].height > 0), dp[i][0]); // the first tree can fall to the left
        dp[i][0] = max(dp[i-1][1] + (distL - t[i].height - t[i-1].height > 0), dp[i][0]); // the first tree can fall to the left

        ll distR = t[i+1].x - t[i].x;
        // fall right
        dp[i][1] = max(dp[i-1][0],dp[i-1][1]) + (distR > t[i].height); // the first tree can fall to the right
    }

    cout << dp[n-1][1] << endl; // last tree falls to the right
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);precalc();solve();}
