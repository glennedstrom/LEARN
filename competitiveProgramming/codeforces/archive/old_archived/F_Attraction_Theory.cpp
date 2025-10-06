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
    vector<int> nums(n); for(auto& i : nums) cin >> i;

    int tot = (n*(n+1)*(n+2)/6 /2+1) * nums[0];
    cout << tot << ' ';

    for(int i = 1; i < n-1; i++){
        tot = (tot + n*(n+1)*(n+2)/6 * nums[i])%998224353 ; // for all but ends
        cout << tot << ' ';
    }
    tot += (n*(n+1)*(n+2)/6 /2+1) * nums[n-1];
    cout << tot << ' ';
    cout << endl;
    // 3*4/2 == 6; 6 * avg_len == 6 * (n+2)/3

    cout << tot % 998224353 << endl;
}

// 1 2 3 4 5
// 1 for the original
// n-1 for the first slot
// n-2 for the second slot
// n-3 for the third slot
// n-4 for the fourth slot
//
// BUT for each of these, you can do a different order
//
// total combos:
// 1 2 3 4 5
// 1 1 2 3 4
// 1 1 1 2 3
// 1 1 1 1 2
// 1 1 1 1 1
//
// and other direction too
//
// 1 1 1
// 1 1 2
// 1 2 2
// 1 2 3
// 2 2 2
// 2 2 3
// 2 3 3
// 3 3 3
//
// endcaps: 3*(3+1)/2 * nums[1]
//
// FOR 1: 0c0 + 1 c 1 + 2 c 2
// 3*1 + 2*1 + 1*2
// 
//
// 3*4/2 == 6; 6 * avg_len == 6 * (n+2)/3

// 1 in each spot three times
// 2 in each spot twice
// 3 in each spot once
//
// (3 + 2*2 + 1*3) * nums[2]
// 
// count for ones:
// 1 (all 3, no option) then 1 (only two goes there) then 2 (one two then two for third)

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
