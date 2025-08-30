#include <bits/stdc++.h>
using namespace std;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

// cut most crowded intersections until you have just smooth paths.
// Then check each location when all paths are straight

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

enum { UNVISITED = -1, VISITED = -2 };

vi dfs_num;
vi dfs_num2;
vector<pair<int,int>> ops;
vector<vector<int>> g;

void dfs(int u) {
  dfs_num[u] = VISITED;
  ops.push_back({1,u});
  for (auto v : g[u])
    if (dfs_num[v] == UNVISITED)
      dfs(v);
}
int find_end_node(int u) {
  dfs_num2[u] = VISITED;
  for (auto v : g[u])
    if (dfs_num2[v] == UNVISITED)
      return find_end_node(v);
  return u;
}

void solve() {
    int n; cin >> n;

    g.assign(n+1,vector<int>());
    dfs_num.assign(n+1,UNVISITED);
    dfs_num2.assign(n+1,UNVISITED);
    ops.clear();

    for(int i = 0; i < n-1; i++){
        int u,v; cin >> u >> v;

        if(u == v)continue;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<pair<int,int>> s_n; // size and node.
    for(int i = 1; i <= n; i++){
        s_n.push_back({g[i].size(),i});
    }
    sort(s_n.rbegin(),s_n.rend());

    // if equal weights as neighbors, we don't have a secondary sorting fallback
    // if your neighbors have lots of neighbors (about 3 per neighbor or more) then it is good to kill you so you shrink the size down
    // NOTE: probably a DP problem or something else. Maybe there is something here, but the above cases seem hard to fix easily
    vector<int> neigh_cut(n+1);
    for(int i = 0; i < s_n.size(); i++){
        if(s_n[i].first + neigh_cut[i] <= 2)continue; // if it is a straight line, ignore it and continue to the next one
        for(auto& u : g[s_n[i].second]){ neigh_cut[u]--; } // reduce edge count of neighbors
        ops.push_back({2,s_n[i].second});                 // log operation
    }

    //dfs from the forest
    for(int v = 1; v <= n; v++){
        if (dfs_num[v] == UNVISITED){
            int end = find_end_node(v); // find the end to start the real dfs from the end to find herobrine
            dfs(end);
        }
    }

    cout << ops.size() << endl;
    for(auto& [a,b] : ops){ cout << a << " " << b << endl; }
}

int main(){ int testcase; cin >> testcase; while(testcase--){ solve(); } }//{solve();}
