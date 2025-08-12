#include <bits/stdc++.h>
//#include <bits/extc++.h>
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

class Solution {
public:
    int cc(int n) {
        UnionFind u = UnionFind(n);
        for(int i = 0; i < n; i++){
            u.unionSet(i,i%2);
        }
        //TODO: everything; also maybe do scc instead of cc
        for(int i = 0; i < n; i++){
            cout << i << " is in set " << u.findSet(i) << endl;
        }
        return 5;
    }
};

int main()
{
    Solution s;
    int ans = s.cc(5);
    cout << "Answer: " << ans << endl;
    return 0;
}
