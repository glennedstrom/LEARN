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
vector<int> rots;

int rotate(int dial, int degrees){
    return (dial + degrees + 360) % 360;
}

bool dfs(int i, int degrees=0){
    if(i < 0)return degrees == 0;
    return dfs(i-1,rotate(degrees,rots[i])) || dfs(i-1,rotate(degrees,-rots[i]));
}
void solve() {
    int n; cin >> n;
    rots.resize(n); for(auto& i : rots)cin >> i;

    dfs(n-1) ? YES : NO;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
