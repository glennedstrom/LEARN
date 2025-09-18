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

    vector<int> a(n); for(auto& i : a)cin >> i;
    vector<int> b(m); for(auto& i : b)cin >> i;

    ll pairs = 0;
    ll cnt = 0; // intermediate count
    int j = 0;

    for (int i = 0; i < n; i++){
        if(i != 0 && a[i] == a[i-1]){
            pairs += cnt;
            continue;
        }

        cnt = 0;
        while(j < m && b[j] <= a[i]){ // count all in the range
            if(b[j] == a[i]){ cnt++; }
            j++;
        }
        pairs += cnt;
    }
    cout << pairs << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
