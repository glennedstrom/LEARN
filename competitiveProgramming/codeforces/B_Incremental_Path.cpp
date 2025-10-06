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
    int n,m; cin >> n >> m;

    string s; cin >> s;

    set<int> black;
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        black.insert(x);
    }

    // O( (n+m)*log(m) )
    // because n iterations with inserting into black (log m) and the while loop does mlogm
    // it is monotonically increasing (i never decreases or resets) so it doesn't compound.

    int i = 1;
    for(auto& c : s){
        i++;
        if(c == 'B'){
            while(black.count(i)){ i++; }
        }
        black.insert(i);
        if(c == 'B'){
            while(black.count(i)){ i++; }
        }
    }

    cout << black.size() << endl;

    for(auto& b : black)cout << b << ' '; cout << endl;

}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
