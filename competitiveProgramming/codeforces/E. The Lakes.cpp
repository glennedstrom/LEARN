#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> waterLevel;

// NOTE: Make this pretty, then put this as a snippet to replace the book's
// Make sure to include all features the book's has
//

struct UnionFind{
private:
    vector<int> _parent;
    vector<int> _rank;
    vector<int> count; // set size
public:
    UnionFind(int n, int rowLen) : _parent(vector<int>(n)), _rank(vector<int>(n,1)), count(vector<int>(n,1)){ 
        for(int i = 0; i < n; ++i){
            _parent[i] = i;
            count[i] = waterLevel[i/rowLen][i % rowLen];
        }
    }


    int size(){ return _parent.size(); }
    int setSize(int n){return count.at(findSet(n));}

    int findSet(int n){
        if(_parent[n] != n){ return _parent[n] = findSet(_parent[n]); }
        return n;
    }
    bool isSameSet(int u,int v){ return findSet(u) == findSet(v); }

    void unionSet(int u, int v){
        u = findSet(u); v = findSet(v);
        if(u == v) return;

        if(_rank[u] < _rank[v]) swap(u,v);   // u is larger now
        if(_rank[u] == _rank[v]) _rank[u]++; // u == v means make u the parent and bigger
        _parent[v] = u;
        count[u] += count[v];
    }

};

int main()
{
    int testcases; cin >> testcases;

    for(int testcase = 0; testcase < testcases; testcase++){
        int n, m; cin  >> n >> m;
        waterLevel.assign(n,vector<int>(m));
        for(int i=0;i<n;++i){ for(int j=0;j<m;++j){ cin >> waterLevel[i][j]; } }

        UnionFind UF(n*m, m);

        // loop over all nodes and union with neighbors IF current and neighbor have water

        for(int i = 0; i < n; i++){
            for(int j=0;j<m;++j){
                if(waterLevel[i][j] == 0)continue;
                int iton = i*m + j;



                if(i > 0 && waterLevel[i-1][j] != 0)
                    UF.unionSet(iton, iton - m); // up
                if(i < n-1 && waterLevel[i+1][j] != 0)
                    UF.unionSet(iton, iton + m); // down
                if(j > 0 && waterLevel[i][j-1] != 0)
                    UF.unionSet(iton, iton - 1); // left
                if(j < m-1 && waterLevel[i][j+1] != 0)
                    UF.unionSet(iton, iton + 1); // right
            }
        }
        
        int maxSet = -1;
        int maxSetSize = -1;
        for(int i = 0; i < UF.size(); i++){
            if(UF.setSize(i) > maxSetSize){
                maxSetSize = UF.setSize(i);
                maxSet = UF.findSet(i);
            }

        }

        cout << maxSetSize << endl;
    }

    return 0;
}
