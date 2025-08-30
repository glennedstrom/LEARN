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
    int n,k; cin >> n >> k;
    string s; cin >> s;

    int burles = 0;
    unordered_map<char,int> count;
    for(char& c : s){ count[c]++; }
    //all characters counted now.
    int ops = 0;
    for(char i = 'a'; i <= 'z'; i++){ 
        //for each character, check the diff
        int diff = abs(count[i] - count[i-('a'-'A')]);
        ops += min(k-ops,diff/2);
        burles += min(count[i], count[i-('a'-'A')]);
    }
    cout << ops + burles << endl;
}

int main(){int t;cin>>t;while(t--){solve();}ios_base::sync_with_stdio(false);cin.tie(NULL);}//{solve();ios_base::sync_with_stdio(false);cin.tie(NULL);}
