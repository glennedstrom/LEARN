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

// must do top down because the nums can be far apart? looping up to 1e9 is not feasible
vector<int> nums;

// Top-down DP with memoization
// int memo[1005][1005];

unordered_map<int,bool> memo;
bool dp(int amount) {
    // Base cases
    if (amount <= 0) return amount == 0;

    // Check memo
    if (memo.find(amount) != memo.end()) return 1;

    // Recursive cases

    bool ans = false;
    for(int i = 0; i < nums.size(); i++){
        ans = max(ans,dp(amount - nums[i]));
    }
    // Add transitions here

    return memo[amount] = ans;
}

void solve() {
    int n; cin >> n;
    nums = {11,111,1111,11111,111111,1111111,11111111,111111111,1111111111};
    nums.erase(remove_if(nums.begin(),nums.end(), [&](int a){return a > n;}),nums.end());
    sort(nums.rbegin(),nums.rend());
    //if exists and less than number then push further in a unordered_map

    //try to shrink n to 0 once you get to dp[n];


    if(dp(n))YES;
    else NO;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
