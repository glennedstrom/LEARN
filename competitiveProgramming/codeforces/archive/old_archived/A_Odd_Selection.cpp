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
    int n,x; cin >> n >> x;
    int oddcount = 0;
    vector<int>v(n); for(auto& i : v){cin >> i; oddcount += i % 2;}
    int evencount = n - oddcount;

    int remaining = max(x-evencount,0); // need this many odds, or this many + 1 if the odds are even

    if(remaining % 2 == 0 && oddcount >= remaining + 1 && evencount >= 1 || remaining % 2 == 1 && oddcount >= remaining){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
