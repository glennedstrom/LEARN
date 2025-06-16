#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;

vi dijkstra(int V, vector<vii>& AL, int s) {
  vi dist(V, INF); dist[s] = 0;
  priority_queue<ii, vector<ii>, greater<ii>> pq;
  pq.push({0, s});
  
  while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    if (d > dist[u]) continue;
    for (auto &[v, w] : AL[u]) {
      if (dist[u]+w >= dist[v]) continue;
      dist[v] = dist[u]+w;
      pq.push({dist[v], v});
    }
  }
  return dist;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long testcases; cin >> testcases;

    for(int testcase = 0; testcase < testcases; testcase++){
        int n,m;
        cin >> n >> m;
        vector<vector<pair<int,int>>> g;


        for(int i = 0; i < m; i++){
            int u,v,w;
            cin >> u >> v >> w;
            g[u][v];
        }
    }

    return 0;
}
