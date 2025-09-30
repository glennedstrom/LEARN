#include <queue>
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
    int vertices, edges; cin >> vertices >> edges;

    vector<vector<pair<int,int>>> g(vertices+1);

    for(int i = 0; i < edges; i++){
        int u,v,w; cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    vector<ll> dist(vertices+1,1e18);
    vector<int> parent(vertices+1,-1);
    vector<bool> visited(vertices+1);
    priority_queue<pair<ll,int>> pq;

    pq.push({0,1});
    dist[1] = 0;

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;

        for(auto& [v, wv] : g[u]) if(!visited[v] && dist[u] + wv < dist[v]){
            dist[v] = dist[u] + wv;
            parent[v] = u;
            pq.push({-dist[v],v});
        }
    }

    if(!visited[vertices]){ cout << -1 << endl; return;}

    stack<int> s;
    int cur = vertices;
    while(cur != -1){
        s.push(cur);
        cur = parent[cur];
    }

    while(!s.empty()){
        cout << s.top() << ' ';
        s.pop();
    }


}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
