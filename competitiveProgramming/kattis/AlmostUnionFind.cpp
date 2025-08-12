#include <bits/stdc++.h>
using namespace std;

class UnionFind {
private:
    vector<vector<int>> unions;
    vector<int> p, rank, setSize;
    int numSets;
public:
    UnionFind(int N) {
        p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
        rank.assign(N, 0);
        setSize.assign(N, 1);
        numSets = N;
        unions = vector<vector<int>>(N);
        for(int i = 0; i < N; i++){
            unions[i] = {i};
        }
    }

    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

    int numDisjointSets() { return numSets; }
    int sizeOfSet(int i) { return setSize[findSet(i)]; }

    void moveToSet(int i, int j){
        //first somehow figure out how to make sure this element has no children
        //then move
        p[i] = findSet(j);
        //move then rebuild if in the wrong set based on... (I hate this problem, I give up...!)
    }

    void unionSet(int i, int j) {
        if (isSameSet(i, j)) return;
        int x = findSet(i), y = findSet(j);
        if (rank[x] > rank[y]) swap(x, y);
        p[x] = y;
        if (rank[x] == rank[y]) ++rank[y];
        setSize[y] += setSize[x];
        --numSets;
    }
};

int main()
{
    int n,m; cin >> n >> m;
    int c, p, q;

    UnionFind UF(n);

    for(int i = 0; i < m; i++){
        cin >> c >> p;
        if(c == 1 || c == 2){ cin >> q; }

        switch (c) {
            case 1:
                UF.unionSet(p, q);
            break;
            case 2:
                //move p to set q
            break;
            case 3:
                // print number of elements
                cout << UF.sizeOfSet(p) << " ";
                // print sum of elements
                cout << 0 << endl; // not sure
            break;
        }

    }
}
