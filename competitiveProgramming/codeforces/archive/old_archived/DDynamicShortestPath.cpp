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
//vector<vector<pair<int,int>>> al_trans; // transposed adjacency list for in-degrees
vector<tuple<int,int,int>> el;
vector<pair<int,int>> itoal;//edge index to address in adjacency list?
//vector<pair<int,int>> itoal_trans;
template <typename T>
inline void hash_combine(std::size_t& seed, const T& val) {
    seed ^= std::hash<T>()(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

struct pair_hash {
    template <typename T1, typename T2>
    std::size_t operator()(const std::pair<T1, T2>& p) const {
        std::size_t seed = 0;
        hash_combine(seed, p.first);
        hash_combine(seed, p.second);
        return seed;
    }
};

unordered_map<pair<int,int>,int,pair_hash> uvtovi; // map from {u,v} to vi; so you can do al[u][vi]; or al[u][map[{u,v}]];
int vertices,edges,queries; 

int output_line;
int UNVISITED = -1;
int VISITING = 0;
int VISITED = 1;
vector<ll> dist;
vector<int> visited;
vector<int> parent;
vector<int> child;


void print_shortest_path(int v){
    stack<int> s; 
    while(v != -1){ s.push(v); v = parent[v]; } 
    while(!s.empty()){ cout << s.top() << "(" << dist[s.top()] << ") "; s.pop(); } cout << endl;
}

vector<ll> dist2;
vector<bool> visited2;
vector<int> parent2;

void verify_path(int v){

    dist2.assign(vertices+1,1e18);
    visited2.assign(vertices+1,false);
    parent2.assign(vertices+1,-1);
    priority_queue<pair<ll,int>,vector<pair<ll,int>>, greater<pair<ll,int>>> pq;

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
    //bool correct = true;
    //for(int i = 1; i < vertices+1; i++){
    //    if(dist2[i] != dist[i] || parent2[i] != parent[i]){
    //        cout << "CHECKING NODE " << i << endl;
    //        if(dist2[i] != dist[i])
    //            cout << "DIST WRONG! ANS:" << dist2[i]  << ", YOURS: " << dist[i] << endl;
    //        if(parent2[i] != parent[i])
    //            cout << "PARENT WRONG! ANS:" << parent2[i] << ", YOURS:" << parent[i] << endl;
    //        correct = false;
    //    }
    //}
    //if(correct){
    //    cout << "ALL CORRECT" << endl;
    //}

    // stack<int> s; 
    // while(v != -1){ s.push(v); v = parent2[v]; } 
    // while(!s.empty()){ cout << s.top() << "(" << dist2[s.top()] << ") "; s.pop(); } cout << endl;
}

// NOTE: Dijkstra, but if the shortest path hasn't changed, take it. Otherwise, explore all paths trying to find a shorter one.
// ::
// ::
// IF PATH CHANGED: Diverge from the path with dijkstras until you find your path again. If you find your way back to your path, you can follow your path while updating it
// ::What about other paths that use this path?
// :: ANS: The paths can only INCREASE, so your path will still be the same. just REMEMBER to UPDATE the path every time because:
// :: If one path partially changed your shortest path weights, you can follow whatever updated parent map there is. AS you traverse the path, update distances
// :: You will need to update distances if you reach un-seen territory (part of your current shortest path isn't part of a previous one you already saw&updated.)
//


void dijkstra(int target){
    dist[1] = 0;
    if(target == 1)return;
    if(target != 0 && dist[target] == 1e18){ return; } // not the initializer and no solution

    priority_queue<pair<ll,int>,vector<pair<ll,int>>, greater<pair<ll,int>>> pq; // NOTE: Always make sure to have your priority queue reset (like put it defined before you use)
    pq.push({0,1}); // 0 dist to reach node 1

    visited.assign(vertices+1, UNVISITED);
    vector<bool> in_shortest_path(vertices+1); // if currently on a node where this it true; you can pop from shortest_path until you find the next one.
    
    vector<int> shortest_path;
    int cur = target;
    while(cur != -1 && dist[cur] != 1e18){ 
        shortest_path.push_back(cur); 
        in_shortest_path[cur] = true;
        cur = parent[cur];
        assert(shortest_path.size() <= vertices); 
    }

    // If there is wasn't a shortest path, Impossible (no new edges are added)
    if(!in_shortest_path[1] && shortest_path.size() == 1){
        return;
    }
    // ISSUE: 
    // This test case messes up the parent map
    // 2 19 82413 21751 2251 5751 95743 10751 14888 60537 2976 5851 22351 83177 40001 43351 18451 23051 63711 1701 67999
    // 1 18370
    // ::
    // This test case uses the wrong parent map to get the incorrect answer.
    // 2 16 76680 89422 3201 49161 33657 40706 15301 43601 12751 24351 70901 98152 4353 32601 40751 46301
    // 1 50000


    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(u == target){ break; } // found our node

        if(output_line == 17 && u == 93){ 
            cout << u << endl; 
        }

        // Fast-Forward to the node in the shortest path stack
        if(in_shortest_path[u] && visited[u] < VISITED){ // not visited because I am paranoid
            while(shortest_path.back() != u){
                in_shortest_path[shortest_path.back()] = false;
                shortest_path.pop_back();
            } // Set the top node equal to u; don't go past it so that we still have in_shortest_path we can use for the current node.
        }
        visited[u] = VISITED;

        // Move along shortest path
        if(in_shortest_path[u]){
            int v = shortest_path.size() >= 2 ? shortest_path[shortest_path.size()-2] : -1; // if still has an edge left
            //cout << u << " to " << v << " has a weight of: " << al[u][uvtovi[{u,v}]].second << endl;
            if(v != -1 && shortest_path.back() == u && dist[u] + al[u][uvtovi[{u,v}]].second == dist[v]){ 
                // are equal, move forwards
                pq.push({dist[v], v});
                visited[v] = VISITING;
                continue;
            }
        }
        // Normal Dijkstra to find the next shortest path because dist[u] + vw != dist[v]
        for(auto& [v,wv] : al[u]) {
            if(visited[v] < VISITED){
                if(visited[v] == UNVISITED || dist[u] + wv < dist[v]){ // make sure unvisited nodes get the full check
                    visited[v] = VISITING;
                    dist[v] = dist[u] + wv;
                    parent[v] = u;
                    pq.push({dist[v], v});
                    // pq.emplace(dist[v], v);

                }
            }
        }
    }
}

// You need to do NORMAL dijkstra, then IF the path has changed, explore the path.!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! KEY KEY KEY
// int rec(int target){

void solve() {
    cin >> vertices >> edges >> queries;


    al.assign(vertices+1, vector<pair<int,int>>());
    // al_trans.assign(vertices+1, vector<pair<int,int>>());

    el.assign(edges, {0,0,0});
    itoal.resize(edges);
    // itoal_trans.resize(edges);

    for(int i = 0; i < edges; i++){
        int u,v,w; cin >> u >> v >> w;
        al[u].push_back({v,w});
        // al_trans[v].push_back({u,w});
        el[i] = {u,v,w};
        itoal[i] = {u,al[u].size()-1};//(&(al[u][al[u].size()-1])-&al[u][0]);
        uvtovi[{u,v}] = al[u].size()-1;
        // itoal_trans[i] = {v,al_trans[v].size()-1};//(&(al_trans[v][al_trans[v].size()-1]) - &al_trans[u][0]);
    }

    dist.assign(vertices+1,1e18);
    parent.assign(vertices+1,-1);
    dijkstra(0); // precompute dijkstra so all nodes at least have something

    output_line = 1;
    int target_line = 17;
    while(queries--){
        int type; cin >> type;
        if(type == 1){
            int v; cin >> v;
            dijkstra(v);
            if(output_line == target_line){
                verify_path(v);
                cout << "CORRECT PATH #17: " << (dist2[v] == 1e18 ? -1 : dist2[v]) << endl;//" == OUTPUT DISTANCE" << endl;
                stack<int> s; 
                int vtemp = v;
                while(vtemp != -1){ s.push(vtemp); vtemp = parent2[vtemp]; } 
                cout << "Path: ";
                while(!s.empty()){ cout << s.top() << "(" << dist[s.top()] << ") "; s.pop(); } cout << endl;
                //while(!s.empty()){ cout << s.top() << " "; s.pop(); } cout << endl;
                cout << endl;
            }
            if(output_line == target_line){
                cout << endl;
                cout << "Output: ";
                cout << (dist[v] == 1e18 ? -1 : dist[v]) << endl;//" == OUTPUT DISTANCE" << endl;
                cout << (dist2[v] == 1e18 ? -1 : dist2[v]) << endl;//" == OUTPUT DISTANCE" << endl;
                stack<int> s; 
                int vtemp = v;
                while(vtemp != -1){ s.push(vtemp); vtemp = parent[vtemp]; } 
                cout << "Path: ";
                while(!s.empty()){ cout << s.top() << "(" << dist[s.top()] << ") "; s.pop(); } cout << endl;
                //while(!s.empty()){ cout << s.top() << " "; s.pop(); } cout << endl;
                cout << endl;

                cout << "FIXING THE PATH..." << endl; parent = vector<int>(parent2);
            }
            if(output_line == target_line){
                dijkstra(v);
                verify_path(v);
                cout << "CORRECT PATH #17: " << (dist2[v] == 1e18 ? -1 : dist2[v]) << endl;//" == OUTPUT DISTANCE" << endl;
                stack<int> s; 
                int vtemp = v;
                while(vtemp != -1){ s.push(vtemp); vtemp = parent2[vtemp]; } 
                cout << "Path: ";
                while(!s.empty()){ cout << s.top() << "(" << dist[s.top()] << ") "; s.pop(); } cout << endl;
                //while(!s.empty()){ cout << s.top() << " "; s.pop(); } cout << endl;
                cout << endl;
            }

            // verify_path(v);
            // cout << (dist2[v] == 1e18 ? -1 : dist2[v]) << endl;//" == OUTPUT DISTANCE" << endl;

            output_line++;
        }
        else{
            int c; cin >> c;
            vector<int> idxs(c); for(auto& i : idxs){cin >> i;i--;} // input and go from 1->0 indexed
            // increment the weights of all the edges
            for(auto& i : idxs){
                auto& [u,v,wx] = el[i]; // not updated weight
                auto& [v2,w2] = al[itoal[i].first][itoal[i].second];
                w2++;
            }
        }
    }
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
