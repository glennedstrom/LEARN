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

    vector<int> nums(n); for(int i=0;i<n;i++){cin >> nums[i];}

    vector dp(n, vector<int>(3,1e9)); // 0 is rest, 1 is contest, 2 is gym or whatever the number order is
    // base cases
    // dp[0][1] = (nums[0] == 1 || nums[0] == 3) ? 0 : 1e9; // 0 or inf rest days (could prob put 1)
    // dp[0][2] = (nums[0] == 2 || nums[0] == 3) ? 0 : 1e9; // 0 or inf rest days
    dp[0][0] = 1; // always 1 rest day more than prev layer (0)
    dp[0][1] = !(nums[0] == 1 || nums[0] == 3); // if 1, put 0 rest days else (inf or current min)
    dp[0][2] = !(nums[0] == 2 || nums[0] == 3); // if 2, put 0 rest days
    for(int i = 1; i < n; i++){
        dp[i][0] = 1 + min(min(dp[i-1][0], dp[i-1][1]), dp[i-1][2]); // min layer
        
        if(nums[i] == 1){ dp[i][1] = min(dp[i-1][0], dp[i-1][2]); }
        if(nums[i] == 2){ dp[i][2] = min(dp[i-1][0], dp[i-1][1]); }
        if(nums[i] == 3){ dp[i][1] = min(dp[i-1][0], dp[i-1][2]); dp[i][2] = min(dp[i-1][0], dp[i-1][1]); }
    }

    int o = 1e9;
    int idx = 0;
    for(auto& i : dp[n-1]){ o = min(o,i); } // min of last row is the n - answer

    // for(auto& v : dp){
    //     cout << nums[idx++] << " : ";
    //     for(auto& i : v){
    //         cout << i << ' ';
    //     }
    //     cout << endl;
    // }
    cout << o << endl;

    return;
}

int main(){solve();}
