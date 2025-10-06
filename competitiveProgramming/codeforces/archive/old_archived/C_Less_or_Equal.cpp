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
    int n,k; cin >> n >> k;
    k--;

    vector<int> v(n); for(auto& x : v){ cin >> x; }
    ranges::sort(v);
    if(k == -1){
        if(v[0] == 1) cout << -1 << endl;
        else cout << 1 << endl;
    }
    else if(k != n){
        cout << (v[k] == v[k+1] ? -1 : v[k]) << endl;
    }
    else{
        cout << v[k] << endl;
    }
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
