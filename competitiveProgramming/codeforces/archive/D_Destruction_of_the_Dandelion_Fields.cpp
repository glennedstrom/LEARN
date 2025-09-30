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

    ll dandes_cut = 0;
    int oddcount = 0;
    vector<int> dandelions(n); for (auto& i : dandelions){cin >> i; oddcount += i % 2;}
    if(oddcount == 0){ cout << 0 << endl; return; }

    sort(dandelions.rbegin(),dandelions.rend());

    int odd_cut = oddcount/2 + oddcount % 2;

    for (auto& i : dandelions){
        if(i % 2 == 0){
            dandes_cut += i;
        }
        else if(odd_cut > 0){
            dandes_cut += i;
            odd_cut--;
        }
    }
    cout << dandes_cut << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
