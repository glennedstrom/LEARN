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
    ll vertices, edges; cin >> vertices >> edges;

    vector<vector<pair<ll,ll>>> g(vertices+1);
    for(int i = 0; i < edges; i++){
        ll u,v,w; cin >> u >> v >> w;
        g[u].push_back({w,v});
        g[v].push_back({w,u});
    }

    // init datastructures
    vector<ll> dist(vertices+1,   1e18); // NOTE: Last issue was that the distances were exceeding my infinity (previously 1e9)
    vector<ll> parent(vertices+1,  -1);
    vector<bool> visited(vertices+1   );
    priority_queue<pair<ll,ll>> pq; // store negative weights here for reverse order because it's a max heap

    // base case
    dist[1] = 0;
    pq.push({0,1});

    // main loop
    while(!pq.empty()){
        ll u = pq.top().second;
        pq.pop();
        visited[u] = true;

        for(auto& [wv,v] : g[u]) if(!visited[v] && dist[u] + wv < dist[v]){
            parent[v] = u;
            dist[v] = dist[u] + wv;
            pq.push({-dist[v], v});
        }
    }

    //cout << dist[vertices] << endl;

    if(!visited[vertices]){ // NOTE: I also forgot to make the visited list, but everything else was good.
        cout << -1 << endl;
        return;
    }

    stack<ll> s;
    ll i = vertices;
    while(i != -1){
        s.push(i);
        i = parent[i];
    }
    while(!s.empty()){
        cout << s.top() << ' ';
        s.pop();
    }
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
