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
    vector<int> a(n); for(auto& i : a)cin >> i;
    vector<int> b(n); for(auto& i : b)cin >> i;
    a.insert(a.begin(),0);
    b.insert(b.begin(),0);
    // one indexed now

    // flag all items not in the right order
    // vector<bool> af(n);
    // vector<bool> bf(n);
    // for(int i = 0; i < n; i++){
    // }
    //
    // if num in opposite array ge num i-1
    // GOOD
    int cnt = 0;
    int r  = 1;
    for (int l = 1; l <= n; l++){
        if(b[r] >= a[l-1]){ // COUNT, SWAPPABLE; previous always is l-1, but b is always r
            cnt++;
        }
        //while(r <= l){

        //}
    }
    cout << cnt << endl;



    // I need to re-think my approach
    //


}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
