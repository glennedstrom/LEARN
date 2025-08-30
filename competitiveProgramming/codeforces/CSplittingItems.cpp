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
    int n, k; cin >> n >> k;
    vector<int> costs(n); for(int i = 0; i<n; i++){ cin >> costs[i]; }
    sort(costs.rbegin(),costs.rend());

    for(int i = 1; i < n; i+=2){
        int subk = min(costs[i-1] - costs[i], k);
        costs[i] +=  subk;
        k -= subk;
        // while(costs[i] < costs[i-1] && k){ // TLE METHOD
        //     costs[i]++;
        //     k--;
        // }
    }

    // Doesn't affect the game with the rest of the counts:
    // while(k >= 2){ costs[0]++; costs[1]++; }
    int tot = 0;
    for(int i = 0; i < n; i++){
        int mult = (i % 2 == 0)*2-1; // i % 2 == 0 for alice going first

        // cout << mult << " * " << costs[i] << " == ";
        // cout << mult*costs[i] << "; ";
        tot += mult*costs[i];
    }
    // cout << endl;
    cout << tot << endl;

}

int main(){int t;cin>>t;while(t--){solve();}ios_base::sync_with_stdio(false);cin.tie(NULL);}//{solve();ios_base::sync_with_stdio(false);cin.tie(NULL);}
