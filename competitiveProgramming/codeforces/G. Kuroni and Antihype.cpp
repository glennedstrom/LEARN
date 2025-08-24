#include <bits/stdc++.h>
using namespace std;

struct UnionFind{
    vector<int> parent;

    UnionFind(int n){
        for(int i = 0; i < n; i++){
            parent.push_back(i);
        }
    }

    int find(int n){
        if(parent[n] != n){
            return find(parent[n]);
        }
        return n;
    }

    void merge(int u, int v){
        u = find(u);
        v = find(v);
        parent[v] = u;
    }
};

int main()
{
    int n; cin >> n;
    n = 10;

    vector<int> age(n);
    for(int i = 0; i<n; ++i){cin >> age[i];}

    UnionFind UF(n+1);

    for(int i = 1; i <= n; i+=2){
        UF.merge(i,1);
    }
    for(int i = 2; i <= n; i+=2){
        UF.merge(i,2);
    }

    for(int i = 1; i <= n; i++){
        cout << i << ": " << UF.find(i) << endl;
    }


}
