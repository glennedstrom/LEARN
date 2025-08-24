#include <bits/stdc++.h>
using namespace std;

int main()
{
    int vertices, edges; cin >>vertices>>edges;

    vector<vector<int>> g(vertices+1);
    vector<bool> visited(vertices+1, false);
    // DUPLICATE EDGES IS WHERE I FAIL

    for(int i = 0; i < edges; ++i){
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int cycleCount = 0;
    for(int node = 1; node < g.size(); node++) if(!visited[node]){

        stack<int> s;

        s.push(node);

        int nodeCount = 1;
        visited[node] = true;
        bool loops = true;
        int cur;

        while(!s.empty()){
            cur = s.top();
            s.pop();
            if(g[cur].size() != 2){ loops = false; break; } // impossible to be a loop, too many branches
            for(auto& neigh : g[cur]){
                if(cur == neigh){loops = false; break;} // no self loops in cycles; just in case they try to close off an end? NOTE: DID NOT HELP! NOTHING HELPS!!!
                if(visited[neigh] == false){
                    nodeCount++;
                    visited[cur] = true;
                    s.push(neigh);
                }
            }
        }
        if(nodeCount >= 3 && loops && find(g[cur].begin(), g[cur].end(),node) != g[cur].end()){ // valid loop and ends back where we started
            cycleCount++;
        }
    }

    cout << cycleCount << endl;
    return 0;
}

