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
    long long a,b,c,d; cin >> a >> b>>c>>d;

    if(a - b <= 0){ cout << b << endl; return; }

    long long o = b;
    long long cur = a-b;

    if(c - d <= 0){ cout << -1 << endl; return; } // impossible

    o += c*(cur / (c-d) + (cur % (c-d) > 0));
    // while(cur > 0){
    //     cur -= c - d;
    //     o += c;
    // }
    cout << o << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
