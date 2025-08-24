#include <bits/stdc++.h>
using namespace std;

class UnionFind{
private:
    vector<int> _parent, _rank, _setSize;
    int _numSets;
public:
    UnionFind(int n) : _parent(vector<int>(n)), _rank(vector<int>(n,1)), _setSize(vector<int>(n,1)), _numSets(n){ iota(_parent.begin(), _parent.end(), 0); }

    int size(){ return _parent.size(); }
    int setSize(int n){return _setSize[findSet(n)];}
    int numSets(){ return _numSets; }
    bool isSameSet(int u,int v){ return findSet(u) == findSet(v); }

    int findSet(int n){ return _parent.at(n) == n ? n : _parent[n] = findSet(_parent[n]); }

    void unionSet(int u, int v){
        u = findSet(u); v = findSet(v);
        if(u == v) return;

        if(_rank[u] < _rank[v]) swap(u,v);
        _parent[v] = u;

        if(_rank[u] == _rank[v]) _rank[u]++;
        _setSize[u] += _setSize[v];
        _numSets--;
    }
};

int main()
{
    int testcases; cin >> testcases;

    for(int testcase = 0; testcase < testcases; testcase++){
        // TODO:
    }

    return 0;
}
