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
    string hello = "hello";
    string s; cin >> s;

    int hi = 0;
    for(int i = 0; i < s.size(); i++){
        if(hi < hello.size() && hello[hi] == s[i]){
            hi++;
        }
    }
    if(hi == hello.size())YES;
    else NO;
}

int main(){solve();ios_base::sync_with_stdio(false);cin.tie(NULL);}
