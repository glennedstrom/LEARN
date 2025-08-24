#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

vector<vector<int>> g;


//vector<vector<pair<int,int>>> g;


vector<bool> visited;
double chance;

void dfs(int n, int depth=0, double prob=1.0){
    visited[n] = true;
    if(g[n].size() == 1 && visited[g[n][0]]){ chance += prob * depth; } // this is an end, add it to chance
    for(int i = 0; i < g[n].size(); i++){
        if(visited[g[n][i]]){continue;}
        dfs(g[n][i], depth + 1, prob/(g[n].size() + (depth == 0 ? 0 : -1))); // dfs all neighbors; * 1 / valid neighbors
        // over g[n].size() ONLY WORKS IF all neighbors are visited (not true most of the time)
        // it is always g[n].size()-1 because it is a tree.
    }
}

int main()
{
    int n; cin >> n;

    g.resize(n+1);// 0 is discarded
    visited.assign(n+1,false);
    chance = 0;

    for(int i = 0; i < n-1; i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> zero_neighbors[0];
    


    dfs(1);

    cout << fixed << setprecision(15) << chance << endl;
}
