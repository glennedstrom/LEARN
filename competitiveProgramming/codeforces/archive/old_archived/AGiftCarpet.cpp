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
    vector chars(m, vector<char>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> chars[j][i];
        }
    }

    string name = "vika";
    int k = 0;

    for(int i = 0; i < m; i++){
        auto& cur = chars[i];
        if(find(cur.begin(), cur.end(), name[k]) != cur.end()){
            k++;
        }
    }

    k == 4 ? YES : NO;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
