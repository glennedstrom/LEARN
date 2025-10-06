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
    ll n, m; cin >> n >> m;

    vector<ll> a(n);  // trap, activated
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> b(n); for(auto& i : b) cin >> i;
    vector<bool> trapped(n);  // trap, activated

    auto activate_trap = [&](int move, int x){
        int i = move % n;
        trapped[i] = true;
    };
    auto is_trapped = [&](int x){
        for(int i = 0; i < n; i++){
            if(trapped[i] && x % a[i] == b[i]){ // if check all activated traps if it's this spot.
                return true;
            }
        }
        return false;
    };

    vector<int> dp(2*n+1);
    // first try to traverse, this will find the optimal setup?
    //
    // dp[move][x][]

    dp[1] = 

}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
