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
    vector<int> nums(n); for(auto& i : nums){cin >> i;}

    // dp starting from the end jumping off the end then building backwards to the beginning.
    
    vector<int> dp(n);
    dp[n-1] = nums[n-1];
    for(int i = n-2; i >= 0; i--){
        dp[i] = nums[i] + (i + nums[i] < n ? dp[i+nums[i]] : 0);
    }
    int o = INT32_MIN;
    for(auto& i : dp){
        o = max(o,i);
    }
    cout << o << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
