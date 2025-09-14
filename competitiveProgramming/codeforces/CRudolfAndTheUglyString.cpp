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

// WARN: God damnit, this was so ugly code. Just redo it or something, it's only a 900
// Then figure out what the real solution is.
// OR figure out now.

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int m=0,a=0,p=0;
    int p2=0,i2=0,e2=0;
    int tot = 0;
    bool pflag = false;

    int count = 0;
    int cur = 0;
    while((cur = s.find("mapie",cur)) != string::npos){ count++; s[cur+2] = '|';}
    cur = 0;
    while((cur = s.find("map",cur)) != string::npos){ count++; s[cur+1] = '|';}
    cur = 0;
    while((cur = s.find("pie",cur)) != string::npos){ count++; s[cur+1] = '|';}

    cout << count << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
