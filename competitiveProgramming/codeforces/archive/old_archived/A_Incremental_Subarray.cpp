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

    vector<int> fav(m); for(auto& i : fav)cin >> i;

    // find first occurrance if consecutive, then every after from i to n has it. Otherwise it is 1 (guaranteed to have one, it is on a boundary condition)

    bool flag = true;
    int high = 0;
    for(int i = 1; i < fav.size(); i++){
        if(fav[i] != fav[i-1]+1){
            flag = false;
            break;
        }
    }

    if(!flag){
        cout << 1 << endl;
        return;
    }

    cout << (n-fav.back() + 1) << endl;


}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
