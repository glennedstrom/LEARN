#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
// EPS for doubles; do 1e-6 for floats
#define EPS 1e-9
#define INF 1e9

void solve() {
    string a; cin >> a;
    // string b = ""; // instead of trying b, try '1' and '0' for each and whichever maximizes the distance the most, take it.
    // for(auto& d : a){ b.push_back(d=='0' ? '1' : '0'); }


    vector dp(a.size() + 1, vector<int>(a.size() + 1, 0));
    for (int i = 1; i <= a.size(); i++) { dp[i][0] = i; }
    for (int i = 1; i <= a.size(); i++) { dp[0][i] = i; }

    for (int i = 1; i <= a.size(); i++) {
        for (int j = 1; j <= a.size(); j++) {
            int best = 0;
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else {
                int replace = dp[i - 1][j - 1] + 1;
                int insert = dp[i][j - 1] + 1;
                int del = dp[i - 1][j] + 1;
                dp[i][j] = min(replace, min(insert, del));
            }
        }
    }



    for(auto& v : dp){
        for(auto& i : v){
            cout << i << ' ';
        }
        cout << endl;
    }
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
