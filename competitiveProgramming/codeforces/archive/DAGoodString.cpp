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

string s;

int dac(int l, int r, char c){ // target char, l, r
    if(l == r)return 1; // empty list case

    int mid = (r-l)/2+l;

    int lhs = dac(l,mid,c+1);
    int rhs = dac(mid,r,c+1);

    return 1;
}

void solve() {
    int n; cin >> n;
    cin >> s;

    cout << dac(0,n,'a') << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
