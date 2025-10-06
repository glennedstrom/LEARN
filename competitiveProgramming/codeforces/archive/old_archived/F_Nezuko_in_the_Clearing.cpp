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
    int h,d; cin >> h >> d;

    vector<int> dp(1e9);
    for(int i = 0; i < dp.size(); i++){
        dp[i] = i*i;
    }
    cout << "done" << endl;
    // simplify the movements
    // move n steps, costs n*(n+1)/2
    // or move n/2 steps twice:
    // (n/2*((n+1)/2))/2 * 2
    //
    // dp with binary search to figure out which location is best?


}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
