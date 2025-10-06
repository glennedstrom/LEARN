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
    int n; cin >> n;
    vector<int> v(n); for(auto& i : v)cin >> i; v.insert(v.begin(),0);
    vector<int> dp(n+1);

    dp[1] = 1; // one way to make the first one

    // maybe dp[i][j] where i is the index through v and j is 
    for(int i = 2; i <= n; i++){
        int uniqueness = 0;
        dp[i] = dp[i-1] + uniqueness;
    }

    // vector<int> L; // subsequences in order from their side
    // vector<int> R;
    // vector<int> Lt; // subsequences in order from their side
    // vector<int> Rt;
    // int prev = 0;
    // for(int i = 0; i < n; i++){
    //     if(v[i] >= prev){
    //         Lt.push_back(v[i]);
    //     }
    //     if(v[i] > prev){
    //         prev = v[i];
    //         L.push_back(v[i]);
    //     }

    // }
    // prev = 0;
    // for(int i = n-1; i >= 0; i--){
    //     if(v[i] >= prev){
    //         Rt.push_back(v[i]);
    //     }
    //     if(v[i] > prev){
    //         prev = v[i];
    //         R.push_back(v[i]);
    //     }
    // }
    // for(auto& i : Lt){
    //     cout << i << ' ';
    // }
    // cout << endl;
    // for(auto& i : Rt){
    //     cout << i << ' ';
    // }
    // cout << endl;
    // cout << endl;


}

/*
*
*
4 4 8 3
*
*
*
*
*
*
*
*/

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
