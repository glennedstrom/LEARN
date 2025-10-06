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
int n,jump_dist,max_swim;
string world;

// Bottom-up DP
int dp_bu(int n) {
    vector<int> dp(n+2, 0);

    // Initialize base cases
    dp[0] = max_swim+1;


    // Fill the table
    for (int i = 0; i <= n+1; i++) {
        if(dp[i] == 0)continue; // impossible to get here
        //cout << dp[i] << " " << world[i] << endl;
        switch (world[i]) {
            case 'L':
                for (int j = 1; j <= jump_dist && i+j <= n+1; j++){
                    //if in water, dp[i+j] = max(max_swim,dp[i+j])
                    if(world[i+j] == 'W'){
                        dp[i+j] = max(dp[i+j],dp[i]);
                    }
                    else if(world[i+j] == 'L'){
                        dp[i+j] = dp[i]; // just on land, it's fine.
                    }
                }
            break;
            case 'W':
                    dp[i+1] = max(dp[i]-1,dp[i+1]); // move forward if optimal
            break;
            case 'C':
                //dies, do nothing because you can't move from a croc
                dp[i] = 0;
            break;
        
        }
    }

    return dp[n+1]; // right bank is at n+1
}

void solve() {
    cin >>n>>jump_dist>>max_swim>>world;
    world = 'L' + world + 'L'; // make you start and finish on land

    if(dp_bu(n)){
        YES;
    }
    else{
        NO;
    }
}

int main(){int t;cin>>t;while(t--){solve();}ios_base::sync_with_stdio(false);cin.tie(NULL);}//{solve();ios_base::sync_with_stdio(false);cin.tie(NULL);}
