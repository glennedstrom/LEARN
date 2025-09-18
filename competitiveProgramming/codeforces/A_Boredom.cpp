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
    vector<int> v(n); for(auto& i : v)cin >> i;

    unordered_map<int,int> c;
    int maxn = 0;

    for(int i = 0; i < n; i++){
        c[v[i]]++; // count everything
        maxn = max(maxn,v[i]);
    }

    ll pp = 0; // previous previous
    ll p = 0; // previous
    for(ll i = 1; i <= maxn; i++){
        ll cur = max(p, pp + i*c[i]);
        pp = p;
        p = cur;
    }
    cout << p << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
