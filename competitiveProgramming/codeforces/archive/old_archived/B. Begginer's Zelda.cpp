#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> dist, parent;
vector<bool> visited;


// dfs to find the furthest away node
// dfs again to find the furthest away node which finds the full path. Fill the parent array here to generate your path
//
// Then traverse the parent map to find all nodes not on your path that you need to set parented to the new parent. Pick the start node as our new node everything will be parented to
// remove old edges and set new ones with this one
// If you find the longest path

// NOT FURTHEST AWAY NODE. WRONG! it is the path with the most branches on it possible.
// 
// Solve for: most unused edges along the path:
// max(unvisited_edges-1, 0); // where unvisited_edges is computed once for each node when you reach it.

int furthest(int u, int depth=0){
    visited[u] = true;
    int maxDepth = depth;
    dist[u] = depth;
    for(auto& v : g[u]) if(!visited[v]){
        maxDepth = max(maxDepth,furthest(v, depth+1));
    }
    return maxDepth;
}
void furthest2(int u, int depth=0){
    visited[u] = true;
    dist[u] = depth;
    for(auto& v : g[u]) if(!visited[v]){
        furthest2(v, depth+1);
    }
}

int dfs(int u, int depth=0){
    visited[u] = true;
    int best = 0;
    for(auto& v : g[u]) if(!visited[v]){
        best = max(best, dfs(v, depth+1));
    }
    return max(best + (int)g[u].size()-2, 0);
}

void solve() {
    int vertices; cin >> vertices;

    g.assign(vertices+1,vector<int>()); for(int i = 0; i < vertices-1; i++){ int u,v; cin >> u >> v; g[u].push_back(v); g[v].push_back(u); }

    // get the furthest away node first
    visited.assign(vertices+1, false);
    dist.assign(vertices+1, 0);
    furthest2(1);
    //int furthest_dist = furthest(1);
    int furthest_dist = *max_element(dist.begin(),dist.end());
    int furthest_node = max_element(dist.begin(),dist.end()) - dist.begin();
    //cout << "dist: " << furthest_dist << " at node: " << furthest_node << endl;
    //
    // then do the most side edges starting from the furthest node
    visited.assign(vertices+1, false);
    dist.assign(vertices+1, 0);
    furthest2(furthest_node);
    int distance = *max_element(dist.begin(),dist.end());
    int furthest_node2 = max_element(dist.begin(),dist.end()) - dist.begin();
    // int distance = furthest(furthest_node);
    // int furthest_node2 = find(dist.begin(),dist.end(),distance) - dist.begin();
    //cout << dfs(furthest_node) << endl;
    cout << "longest path: " << furthest_node << " to " << furthest_node2 << "; Distance: " << distance << endl;
}

int main() { int testcases; cin >> testcases; for(int testcase = 0; testcase < testcases; testcase++){ solve(); } }// {solve();}



// vesa"

