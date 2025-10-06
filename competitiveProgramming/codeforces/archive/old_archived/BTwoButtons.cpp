#include <ios>
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
    int n, m; cin >> n >> m;

    int h = max(n*2+1,m*2+1); // max(n*2+6, 2*m+6);  // added n*2+1 just to get it to work
    vector<int> dp(h, 1e9); // (m-1)*2+1
    dp[n] = 0;

    // INFO: For every value in this range; compute it.
    int r = n;
    int l = 1;
    while(l <= m){ // range still in bounds
        for(int i = r; i >= l; i--){
            dp[i-1] = min(dp[i-1], dp[i] + 1);
            if(i*2 < h)
                dp[i*2] = min(dp[i*2], dp[i] + 1);
        }

        // move to the next computation range
        l = r + 1;
        r *= 2;
    }

    // for(int i = 1; i < h; i++){ cout << (dp[i] == -1 ? "_" : to_string(dp[i])) << ' '; } cout << endl;
    cout << dp[m] << endl;
}

// do whatever transitions that are most natural

// Search problem solution:
void solve2() {
    int n, m; cin >> n >> m;

    int h = max(m*2+1,n*2+1); // max(n*2+6, 2*m+6);  // added n*2+1 just to get it to work
    vector<bool> visited(h+1); // (m-1)*2+1

    queue<pair<int,int>> q;
    q.push({n,0}); // start, cost

    while(!q.empty()){ // basically while(true)
        auto& [u, cost] = q.front();
        q.pop();
        if(visited[u]){ continue; }
        visited[u] = true;
        if(u == m){
            cout << cost << endl;
            return;
        }
        if(u-1 > 0)
            q.push({u-1, cost+1});
        if(u*2 < h)
            q.push({u*2, cost+1});
    }
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);solve2();}
