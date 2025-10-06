#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
#include <functional>
#include <queue>
#include <stack>
using namespace std;

// Straight-forward dijkstra problem
// NOTE: you can have multiple edges between vertices

int main() {
    int vertices, edges; cin >> vertices >> edges;

    vector<vector<pair<int,int>>> g(vertices+1);

    for(int i = 0; i < edges; i++){
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({w,v}); // weight then v for lexicographic order in pq
        g[v].push_back({w,u});
    }

    
    vector<int> parent(vertices+1, -1);
    vector<int> in_heap(vertices+1, false); // THEN READ LENGTH FROM OTHER LOCATIONS? IF READ EARLY, RE-QUEUE TO THE CORRECT LENGTH
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(vertices+1, INT32_MAX);
    parent[1] = -1;
    dist[1] = 0;
    in_heap[1] = true;
    pq.push({0,1});

    while(!pq.empty()){
        auto [wu, u] = pq.top();
        pq.pop();
        //doesn't work
        //if(wu != dist[u]){ pq.push({dist[u],u}); continue; } // Shuffle back in the list if it was updated
        //in_heap[1] = false;

        for(int i = 0; i < g[u].size(); i++){
            auto [wv, v] = g[u][i];

            if(dist[u] + wv < dist[v]){
                dist[v] = dist[u] + wv;
                parent[v] = u;
                //only push if it is not inside already. (otherwise the if statement will update it automatically)
                //if(!in_heap[v]){ // doesn't work
                    in_heap[v] = true;
                    pq.push({dist[v], v});
                //}
           }
        }
    }

    if(dist[vertices] == INT32_MAX){ cout << -1 << endl; return 0; }

    stack<int> s;
    int c = vertices;
    while(c != -1){
        s.push(c);
        c = parent[c];
    }

    while(!s.empty()){
        cout << s.top() << ' ';
        s.pop();
    }
}
