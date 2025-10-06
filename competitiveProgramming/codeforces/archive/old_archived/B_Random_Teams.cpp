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
    ll n,m; cin >> n >> m;

    // minimum: evenly split as much as you can to all groups
    // maximum: n-m+1 in the first group and pair everyone; -1 pairs so just n-m

    ll x = n-m;
    ll h = x*(x+1)/2;

    ll people_per_group = (n / m); // -1 for how many pairs
    // first compute how many pairs in the lower group
    // then how many in the upper
    // sum total pair into l

    //number of groups with X+1 and X
    ll ap = n % m;
    ll bp = m - ap;

    // number of participants in each group
    ll a = (n/m);
    ll b = (n/m-1);

    // a and b must consist of just how many adjacent pairs; a is one higher than b
    ll l = a*(a+1)/2*ap + b*(b+1)/2*bp;
    cout << l << ' ' << h << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
