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
    ll n,k,x; cin >> n >> k >> x;

    ll smallsum = 0;

    vector<ll> v(n);
    for(auto& i : v){cin >> i; smallsum += i;}

    ll tot = x/smallsum*smallsum; // sum of x so far
    ll l = (n*k)-(x/smallsum*n);
    while(tot < x){ // if it is at least x, stop
        l--; //move to the next one to remove
        tot += v[(l)%n];
    }

    cout << max(l+1, 0ll) << endl; // +1 for 0-indexing to get real count
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
