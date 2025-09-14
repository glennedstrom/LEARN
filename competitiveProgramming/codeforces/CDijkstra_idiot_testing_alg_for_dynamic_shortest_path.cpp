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


int vertices,edges; 

vector<ll> dist;
vector<bool> visited;
vector<int> parent;
priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;

void dijkstra(){
    int source = 1;

    dist.assign(vertices+1,1e18);
    visited.assign(vertices+1,false);
    parent.assign(vertices+1,-1);

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

    if(!visited[vertices]){
        cout << -1 << endl;
        return;
    }

    stack<int> s;
    int v = vertices;
    while(v != -1){
        s.push(v);
        v = parent[v];
    } 
    while(!s.empty()){
        cout << s.top() << ' ';
        s.pop();
    }
     cout << endl;
}

void solve() {
    cin >> vertices >> edges;

    al.assign(vertices+1, vector<pair<int,int>>());

    for(int i = 0; i < edges; i++){
        int u,v,w; cin >> u >> v >> w;
        al[u].push_back({v,w});
        al[v].push_back({u,w});
    }
    dijkstra();
}


















int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
