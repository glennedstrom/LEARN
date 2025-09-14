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
    int n,q; cin >> n >> q;

    vector<ll> xheight(n); for(auto& i : xheight)cin >> i;
    xheight.insert(xheight.begin(),0);
    xheight.push_back(0);

    vector<ll> prefs(xheight);
    vector<ll> postfs(prefs);

    for(int i = 1; i <= n; i++){
        prefs[i] =  prefs[i-1] + max(xheight[i-1] - xheight[i], 0ll) ;
    }
    for(int i = n; i > 0; i--){
        postfs[i] =  postfs[i+1] + max(xheight[i+1] - xheight[i], 0ll) ;
    }

    while(q--){
        int a,b; cin >> a >> b;
        if(a > b){ // going left
            cout << postfs[b] - postfs[a] << endl;
        }
        else{ // going right
            cout << prefs[b] - prefs[a] << endl;
        }
    }
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
