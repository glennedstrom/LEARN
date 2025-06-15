#include <bits/stdc++.h>
using namespace std;


void level_by_level_bfs(vector<vector<int>>& g){
    queue<int> q; // queue
    vector<bool> v(g.size()); // visited 

    int level = 0;
    for(int i = 0; i < g.size(); i++){
        if(!v[i]){
            q.push(i);
            v[i] = true;
        }


        while(!q.empty()){
            cout << "Level: " << level << endl;
            int s = q.size(); // number of nodes in the current level
            for(int j = 0; j < s; j++){
                int cur = q.front();
                q.pop();
                cout << cur << endl;

                for( int n : g[cur]){
                    if(!v[n]){
                        v[n] = true;
                        q.push(n);
                    }
                }
            }
            level++;
        }
    }
}

void bfs(vector<vector<int>>& g){
    queue<int> q; // queue
    vector<bool> v(g.size()); // visited 

    for(int i = 0; i < g.size(); i++){
        if(!v[i]){
            q.push(i);
            v[i] = true;
        }

        while(!q.empty()){
            int cur = q.front();
            q.pop();
            cout << cur << endl;

            for( int n : g[cur]){
                if(!v[n]){
                    v[n] = true;
                    q.push(n);
                }
            }
        }
    }
}

void ss_bfs(vector<vector<int>>& g, int s){
    queue<int> q; // queue
    vector<bool> v(g.size()); // visited 

    q.push(s);
    v[s] = true;

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << endl;

        for( int n : g[cur]){
            if(!v[n]){
                v[n] = true;
                q.push(n);
            }
        }
    }
}

void rdfs(vector<vector<int>>& g, vector<bool>& v, int n){
    cout << n << endl;
    for(auto& i : g[n]){
        if(!v[i]){
            v[i] = true;
            rdfs(g,v,i);
        }
    }
}

void dfs(vector<vector<int>>& g){
    vector<bool> v(g.size());
    int component = 0;
    for(int i = 0; i < g.size(); i++){
        if(!v[i]){
            cout << "Component " << component << ":" << endl; // optional to find which component
            v[i] = true;
            rdfs(g,v,i);
        }
    }
}

void prdfs(vector<vector<int>>& g, vector<bool>& v, vector<int>& p, int n){
    cout << n << endl;
    for(auto& i : g[n]){
        if(!v[i]){
            v[i] = true;
            p[i] = n;
            prdfs(g,v,p,i);
        }
    }
}

void pdfs(vector<vector<int>>& g, vector<int>& p){
    vector<bool> v(g.size());
    int component = 0;
    for(int i = 0; i < g.size(); i++){
        if(!v[i]){
            cout << "Component " << component << ":" << endl; // optional to find which component
            v[i] = true;
            // p[i] = -1; // already initialized as so
            prdfs(g,v,p,i);
        }
    }
}

int main(){
    vector<vector<int>> g = {
        {1,2,3},
        {0,3,5},
        {1,4},
        {1,2,5},
        {0,1},
        {2,4}
    };
    vector<vector<int>> chain = {
        {1},    // 0
        {0,2},  // 1
        {1,3},  // 2
        {2}     // 3
    };
    vector<vector<int>> cyclic = {
        {1,2},  // 0
        {0,2},  // 1
        {0,1}   // 2
    };
    vector<vector<int>> disconnected = {
        {1},    // 0
        {0},    // 1
        {3},    // 2
        {2}     // 3
    };
    vector<vector<int>> tree = {
        {1,2},    // 0
        {3,4},    // 1
        {5,6},    // 2
        {},       // 3
        {},       // 4
        {},       // 5
        {}        // 6
    };
    vector<vector<int>> complete = {
        {1,2,3},  // 0
        {0,2,3},  // 1
        {0,1,3},  // 2
        {0,1,2}   // 3
    };
    vector<vector<int>> directed = {
        {1},      // 0
        {2},      // 1
        {3},      // 2
        {}        // 3
    };
    vector<vector<int>> selfloop = {
        {0, 1},  // 0
        {0},     // 1
        {},      // 2 (isolated)
        {1}      // 3
    };

    cout << "ss: " << endl;
    ss_bfs(g, 0);
    cout << "everything: "<< endl;
    bfs(g);
    cout << "level_by_level: "<< endl;
    level_by_level_bfs(g);
    cout << "dfs" << endl;
    dfs(g);
    vector<int> p(g.size(), -1);
    pdfs(g,p);
    //then you can find the path back to the root:
    int i = 4;
    cout << "Path from " << i << " to the root: " << endl;
    while(i != -1){
        cout << i << endl;
        i = p[i];
    }

    return 0;
}
