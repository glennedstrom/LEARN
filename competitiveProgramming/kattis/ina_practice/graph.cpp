
#include <bits/stdc++.h>
using namespace std;

void dfs_helper(){
}

void dfs(vector<vector<pair<int,int>>>& g){
}

void bfs(vector<vector<pair<int,int>>>& g){
    vector<bool> visited(g.size()); //unordered_map<int,bool> visited; // this is if it is sparse or if you have other datatypes
    queue<int> q;

    for(int i = 0; i < g.size(); i++){
        // do bfs starting here

        if(!visited[i]){
            q.push(i); // start at node 0; handle disjoint graphs too by trying all start values
            visited[i] = true;
        }

        while(!q.empty()){
            int cur = q.front(); //handle node
            q.pop();
            cout << cur << endl;

            for(auto& [w,v] : g[cur]){ // push all neighbors if not visited yet (or not in queue)
                if(!visited[v]){
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }
}

void dijkstra(vector<vector<pair<int,int>>>& g){
    vector<bool> visited(8); //unordered_map<int,bool> visited; // this is if it is sparse or if you have other datatypes
    priority_queue<pair<int,int>> q;
}

int main(){
    // vector<vector<int>> g2 = {};
    vector<vector<pair<int,int>>> g = {
        {{3,3}, {5,5}},
        {{1,3}, {2,4}, {1,6}},
        {{3,1}},
        {{5,0}, {5,1}},
        {{3,1}},
        {{6,6}},
        {{2,0}},
        {{1,2}}
    }; // graph <weight, node_num>

    //bfs
    bfs(g);



}








