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

void solve() {
    int n,k; cin >> n >> k;
    vector<int> nums(n);for(auto& i : nums){cin >> i;}
    sort(nums.begin(),nums.end());

    UnionFind UF(n);

    int deleted = 0;
    for(int i = 1; i < nums.size(); i++){
        if(abs(nums[i] - nums[i-1]) > k){
            deleted++;
        }
        else{
            UF.unionSet(i-1, i);
        }
    }
    int maxnum = 0;
    for(int i = 0; i < n; i++){
        maxnum = max(UF.setSize(i),maxnum);
    }

    cout << n - maxnum << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
