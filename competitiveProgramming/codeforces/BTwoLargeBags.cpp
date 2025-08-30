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

// sort it and start with the smallest numbers. if you have 3 or more, you can increase it to 4 or you can leave it at 3. NOTE: you must end with an even number. if a parent requests a larger one, we could give it
//
// dp where you push forward the extra numbers you can use

vector<int> nums;

// Bottom-up DP
int dp_bu(int n) {
    vector<int> dp(n+1);
    // IF EVEN: why not push it up (doesn't hurt)
    // IF ODD: MUST push it up because we need to be even.
    //
    //dp[i] += max(dp[i-1]-2,0) // push forward

    // Initialize base cases
    // Initialize here
    // count all numbers and put it in dp. then move through it and push forward extras?
    for(int i = 0; i < nums.size(); i++){
        dp[nums[i]]++; // count each
    }


    // Fill the table
    for (int i = 1; i <= n; i++) {
        dp[i] += max(dp[i-1] - 2, 0);
        if(dp[i] == 1){ return -1; } // impossible to move on
    }

    return dp[n];
}

void solve() {
    int n;cin >> n;
    nums.assign(n,0);
    for(int i = 0; i < n; i++){ cin >> nums[i]; }
    sort(nums.begin(),nums.end());

    if(dp_bu(n) == -1){
        NO;
    }
    else YES;
}

int main(){int t;cin>>t;while(t--){solve();}ios_base::sync_with_stdio(false);cin.tie(NULL);}//{solve();ios_base::sync_with_stdio(false);cin.tie(NULL);}
