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

    for(int testcase = 0; testcase < testcases; testcase++){
        //union find looping through the cycle (while A & B not in the same union move) then loop through all elements to make sure they are unioned.
        // count how many are in a cycle then the LCM is the answer

        int n; cin >> n;
        vector<int> nums(n+1); for(int i = 1; i < nums.size(); i++){ cin >> nums[i]; }
        // nums is 1 indexed

        UnionFind UF(n+1);

        for(int i = 1; i < nums.size(); i++){
            int cur = i;
            int next = nums[i];
            while(UF.findSet(cur) != UF.findSet(next)){
                UF.unionSet(cur, next); // merge the sets
                cur = nums[i];
                nums[i] = nums[nums[i]];
            }
        }

        // all are unioned now

        // contains unique sizes
        for(int i = 1; i < nums.size(); i++){ 
            cout << UF.sizeOfSet(nums[i]) << (i == nums.size() ? "" : " ");
        }
        cout << endl;



    }

    return 0;
}
