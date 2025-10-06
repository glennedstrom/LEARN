#include <numeric>
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
vector<vector<pair<int,int>>> al;
vector<vector<pair<int,int>>> al_trans; // transposed adjacency list for in-degrees
vector<tuple<int,int,int>> el;
vector<pair<int,int>> itoal;//edge index to address in adjacency list?
vector<pair<int,int>> itoal_trans;
vector<vector<int>> am; //  graph matrix modified

int vertices,edges,queries; 

vector<ll> dist;
vector<bool> visited;
vector<int> parent;
priority_queue<pair<ll,int>,vector<pair<ll,int>>, greater<pair<ll,int>>> pq;


void print_shortest_path(int v){
    stack<int> s; 
    while(v != -1){ s.push(v); v = parent[v]; } 
    while(!s.empty()){ cout << s.top() << "(" << dist[s.top()] << ") "; s.pop(); } cout << endl;
}

vector<ll> dist2;
vector<bool> visited2;
vector<int> parent2;

void verify_path(){

    dist2.assign(vertices+1,1e18);
    visited2.assign(vertices+1,false);
    parent2.assign(vertices+1,-1);

    pq.push({0,1}); // 0 dist to reach node 1
    dist2[1] = 0;

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        visited2[u] = true;

        for(auto& [v,wv] : al[u]) if(!visited2[v] && dist2[u] + wv < dist2[v]){
            dist2[v] = dist2[u] + wv;
            parent2[v] = u;
            pq.push({dist2[v], v});
        }
    }

    // check if they are the same.
    bool correct = true;
    for(int i = 1; i < vertices+1; i++){
        if(dist2[i] != dist[i] || parent2[i] != parent[i]){
            cout << "CHECKING NODE " << i << endl;
            if(dist2[i] != dist[i])
                cout << "DIST WRONG! ANS:" << dist2[i]  << ", YOURS: " << dist[i] << endl;
            if(parent2[i] != parent[i])
                cout << "PARENT WRONG! ANS:" << parent2[i] << ", YOURS:" << parent[i] << endl;
            correct = false;
        }
    }
    if(correct){
        cout << "ALL CORRECT" << endl;
    }

}

int dijkstra(int target){


    pq.push({0,1}); // 0 dist to reach node 1
    dist[1] = 0;

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;

        for(auto& [v,wv] : al[u]) if(!visited[v] && dist[u] + wv < dist[v]){
            dist[v] = dist[u] + wv;
            parent[v] = u;
            pq.push({dist[v], v});
        }
    }

    // WARN: THIS PRINTS THE SHORTEST PATH
    //print_shortest_path(vertices);
    return dist[target];
}

// NOTE: Main issue right now is that I'm not propagating the shortest path back down.

// NOTE: YOU NEED SOME KIND OF PRIORITY QUEUE TO PROCEED UPWARDS TOO.
// MAJOR ALGORITHM CHANGE
// This is because we need to handle shortest paths first to avoid reaching the root too early. I think technically it would be trying to do shortest last?
// This is almost like reverse-dijkstra.
//
// WARN: Instead of recursive calls going left and right, just do dijkstra in reverse order. Start from your node and if nothing changed, go to your parent, if something did change, push neighbors to the priority queue?
// Cases:
// 1. dist[parent[v]] + wv == dist[v] (If the best path hasn't changed)
// :::::- Push the parent node to the queue
// 2. Else: Best path may have changed: Push all nodes in IF some condition. They need to have a shorter path than your current distance, otherwise you are getting further away!
// ::
// What order does the PQ need to go in?? Maximum because we want to not greedily take the minimum all the way to the parent right?
// or minimum to find the best paths (because other than normal dijkstra uses min to minimize the path)
// 3RD OPTION: 
// :: Whenever you split, keep moving until they merge while similar path lengths
// NO NO NO NO NO NO NO NO
// NO NO NO NO NO NO NO NO
// NO NO NO NO NO NO NO NO
// You need to do NORMAL dijkstra, then IF the path has changed, explore the path.!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! KEY KEY KEY
// int rec(int target){
//     //cout << "TARGET: " << target << endl;
//     int v = target;
//     if(parent[v] == -1 && v != 1) return -1; // No valid path: No parent, and we aren't the root node.
//     while(parent[v] != -1){ // until we are the root
//         int u = parent[v];
//         int wv = am[u][v];
//         //cout << "V: dist[v] :: " << v << " : " << dist[v] << endl;
//         visited[v] = true; // not going back to the source
// 
//         if(visited[1] && visited[v]){ // WARN: WRONG CONDITION HERE!!!!! We need all paths to finish before resting.
//             //cout << "FILLING IN NODE " << v << endl;
//             //cout << "u,v == " << u << ',' << v << endl;
//             //cout << dist[v] << " :: " << dist[u] + wv << endl;
//             //cout << "wv == " << wv << endl;
//             //cout << "dist[u] == " << dist[u] << endl;
//             dist[v] = dist[u] + wv;
//             //cout << dist[v] << " :: " << dist[u] + wv << endl;
//             for(auto& [a, aw] : al[v]){
//                 // push dist[v] forwards and recursive call
//                 rec(a);
//             }
//             break;
//         }
// 
//         if(dist[u] + wv != dist[v]){ // dist[u] + wv != dist[v] means the edge increased (KEEP AM UPDATED)
//             dist[v] = 1e18; // SET TO INFINITY BECAUSE WE NEED TO COMPUTE THE NEW SHORTEST PATH
//             // check all in-degrees by recursively calling on them.
//             for(auto& [a, aw] : al_trans[v]) { // WARN: what if all of these are visited? we need to update v with something!
//                 if(!visited[a]){
//                     dist[a] = rec(a);
//                     if(dist[a] + aw < dist[v]){ // NOTE: dist[v] is the PREVIOUS shortest path BUT it is GROWING because of the additions. (I reset the shortest path for this)
//                         dist[v] = dist[a] + aw;
//                         parent[v] = a;
//                     }
//                 }
//                 else{
//                     // UPDATE WITH BEST DIST POSSIBLE; IT ALREADY HAS BEEN REC CALLED ON
//                     if(dist[a] + aw < dist[v]){
//                         dist[v] = dist[a] + aw;
//                         parent[v] = a;
//                     }
//                 }
//             }
//         }
//         else{
//             v = parent[v]; // proceed up the shortest path; already good.
//         }
//     }
//     if(v == 1){ visited[v] = true; }
// 
// 
//     return dist[target];
// }
// NOTE: Once we have a correct distance, we need to "push" the changes back down the shortest path tree to all affected (ALL CHILDREN whose parent[child] == your node)

void solve() {
    cin >> vertices >> edges >> queries;


    am.assign(vertices+1, vector<int>(vertices+1, -1));
    al.assign(vertices+1, vector<pair<int,int>>());
    al_trans.assign(vertices+1, vector<pair<int,int>>());

    el.assign(edges, {0,0,0});
    itoal.resize(edges);
    itoal_trans.resize(edges);

    for(int i = 0; i < edges; i++){
        int u,v,w; cin >> u >> v >> w;
        al[u].push_back({v,w});
        al_trans[v].push_back({u,w});
        am[u][v] = w;
        el[i] = {u,v,w};
        itoal[i] = {u,al[u].size()-1};//(&(al[u][al[u].size()-1])-&al[u][0]);
        itoal_trans[i] = {v,al_trans[v].size()-1};//(&(al_trans[v][al_trans[v].size()-1]) - &al_trans[u][0]);
    }


    while(queries--){
        int type; cin >> type;
        if(type == 1){
            int v; cin >> v;
            visited.assign(vertices+1, false);
            dist.assign(vertices+1,1e18);
            parent.assign(vertices+1,-1);
            cout << dijkstra(v) << endl;//" == OUTPUT DISTANCE" << endl;
            //print_shortest_path(v);
            //verify_path();
            //cout << "SHORTEST PATH 1 to " << v << ": ";
            //print_shortest_path(v);
            //cout << endl << endl;
        }
        else{
            int c; cin >> c;
            vector<int> idxs(c); for(auto& i : idxs){cin >> i;i--;} // input and go from 1->0 indexed
            // increment the weights of all the edges
            for(auto& i : idxs){
                auto& [u,v,wx] = el[i]; // not updated weight
                auto& [v2,w2] = al[itoal[i].first][itoal[i].second];
                auto& [v3,w3] = al_trans[itoal_trans[i].first][itoal_trans[i].second];
                am[u][v]++; // increment our modified matrix
                w2++;
                w3++;
            }
        }
    }
    // INFO: The parent map shows the shortest path from your node to the root node 1
    //
    /* INFO: Solution: 
        *
        *
        * 1. Loop up the parent tree to check if your shortest path has changed (RECURSIVELY)
        *
        * visited.assign(vertices+1, 0);
        * v := target node
        * while(v != -1){
        *    visited[v] = true; // not going back to the source
        *    if(dist[parent[v]] + wv != dist[v]){ // dist[u] + wv != dist[v] means the edge increased
        *       dist[v] = 1e18; // SET TO INFINITY BECAUSE WE NEED TO COMPUTE THE NEW SHORTEST PATH
        *       // check all in-degrees by recursively calling on them.
        *       for(auto& [a, aw] : al_trans[v]) { // WARN: what if all of these are visited? we need to update v with something!
        *           if(!visited[a]){
        *               dist[a] = rec();
        *               if(dist[a] + aw < dist[v]){ // NOTE: dist[v] is the PREVIOUS shortest path BUT it is GROWING because of the additions. (I reset the shortest path for this)
        *                   dist[v] = dist[a] + aw;
        *                   parent[v] = a;
        *               }
        *           }
        *           else{
        *               // UPDATE WITH BEST DIST POSSIBLE; IT ALREADY HAS BEEN REC CALLED ON
        *               if(dist[a] + aw < dist[v]){
        *                   dist[v] = dist[a] + aw;
        *                   parent[v] = a;
        *               }
        *           }
        *       }
        *    }
        *    else{
        *       v = parent[v]; // proceed up the shortest path
        *    }
        * }
        * 
        *
        * NOTE: You need to keep both the AL, and the al_trans updated always.
        * The distance array is what will 'lag behind' to detect differences, then the AL(s) are what will be the source of truth for updates
        *
        *
        *
        *
        * if()
        * dp(i) = dp()
        *
        * 2. If your shortest path changed on the edge from u to v, loop over all in-degrees for v (generate a graph initially for this);
        *
        * 3. Check if their path has changed (RECURSIVELY). 
        *
        * 4. You can have a 'checked' array/memo for paths have already been computed to the root (already visited node reached from another path)
        *
        * possibly could do dp array instead, but that's the jist of it.
        *
        * if(dist[u] + wv != dist[v]){ 
        *     This edge got incremented, Check all in-degrees of v recursively for shortest paths 
        * }
        * * for the recursive calls: YOU DON'T KNOW IF IN-DEGREE EDGES CHANGED HERE BECAUSE: this wasn't a shortest path in the first place. COMPARE THIS: (Final Edge Dist) + rec(find_shortest_path_dist); where the rec is the recursive call traversing up the parent tree checking for changes.
        *
    */


}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
