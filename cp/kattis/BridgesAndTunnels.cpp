#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

typedef vector<int> vi;

class UnionFind {
private:
  vi p, rank, setSize;
  int numSets;
public:
  UnionFind(int N) {
    p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
    rank.assign(N, 0);
    setSize.assign(N, 1);
    numSets = N;
  }

  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }

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
    int n; cin >> n;
    unordered_map<string, int> m; // bridge name to index map for UF

    UnionFind UF(n*2); // at most 2*n if each bridge is between separate buildings that are all new

    for(int i = 0; i < n; i++){
        string s1, s2; cin >> s1 >> s2;

        if(m.find(s1) == m.end()){ m[s1] = m.size(); }
        if(m.find(s2) == m.end()){ m[s2] = m.size(); }

        UF.unionSet(m[s1], m[s2]); // union the two

        cout << UF.sizeOfSet(m[s1]) << endl;
    }
}
