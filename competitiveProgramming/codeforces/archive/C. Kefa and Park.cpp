#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<bool> hasCat, visited;
int vertices, edges, catLimit;

int dfs(int u, int catsFound){
    if(catsFound > catLimit)return 0;
    visited[u] = true;
    if(g[u].size() == 1 && u != 1)return 1; // edge node and not his house

    int restaurantCount = 0;
    for(auto& v : g[u]) if(!visited[v]){
        restaurantCount += dfs(v, hasCat[v] ? catsFound + 1 : 0);
    }

    return restaurantCount;
}

int main()
{
    cin >> vertices >> catLimit;
    edges=vertices-1;

    hasCat.assign(vertices+1, false);
    visited.assign(vertices+1, false);
    g.assign(vertices+1, vector<int>());

    int temp;
    for(int i = 1; i < vertices+1; i++) {cin >> temp; hasCat[i] = temp;}

    for(int i = 0; i < edges; i++){
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    cout << dfs(1, hasCat[1]) << endl;

}
