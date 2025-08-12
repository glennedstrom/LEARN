#include <bits/stdc++.h>
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long testcases; cin >> testcases;
    cout << testcases << endl;

    for(int testcase = 0; testcase < testcases; testcase++){
        int n; cin >> n; // pizzas on the menu
        cout << n << endl;
        //
        //
        vector<UnionFind> a(188888); // I AM STUCK, GIVING UP FOR NOW.

        for(int i = 0; i < n; i++){
            string name; cin >> name;
            cout << name << endl;

            int fn; cin >> fn; // foreign name
            cout << fn << endl;
            vector<string> fnvec(fn);
            for(int i = 0; i < fn; i++){ cin >> fnvec[i]; }

            int rn; cin >> rn; // real name
            cout << rn << endl;
            vector<string> rnvec(rn);
            for(int i = 0; i < rn; i++){ cin >> rnvec[i]; }

            //parsed the input now.

            e
        }
    }

    return 0;
}
