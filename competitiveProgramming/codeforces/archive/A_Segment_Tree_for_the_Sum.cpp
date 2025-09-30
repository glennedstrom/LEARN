#include <cmath>
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void precalc(){
    // optional
}


typedef vector<int> vi;

class SegmentTree {
private:
  int n;
  vi A, st, lazy;

  int l(int p) { return p<<1; }
  int r(int p) { return (p<<1)+1; }

  int conquer(int a, int b) {
    if (a == -1) return b;
    if (b == -1) return a;
    return a+b;//max(a, b); // Change this for different operations
  }

  void build(int p, int L, int R) {
    if (L == R)
      st[p] = A[L];
    else {
      int m = (L+R)/2;
      build(l(p), L, m);
      build(r(p), m+1, R);
      st[p] = conquer(st[l(p)], st[r(p)]);
    }
  }

  void propagate(int p, int L, int R) {
    if (lazy[p] != -1) {
      st[p] = lazy[p];
      if (L != R)
        lazy[l(p)] = lazy[r(p)] = lazy[p];
      else
        A[L] = lazy[p];
      lazy[p] = -1;
    }
  }

  int RMQ(int p, int L, int R, int i, int j) {
    propagate(p, L, R);
    if (i > j) return -1;
    if ((L >= i) && (R <= j)) return st[p];
    int m = (L+R)/2;
    return conquer(RMQ(l(p), L, m, i, min(m, j)),
                   RMQ(r(p), m+1, R, max(i, m+1), j));
  }

  void update(int p, int L, int R, int i, int j, int val) {
    propagate(p, L, R);
    if (i > j) return;
    if ((L >= i) && (R <= j)) {
      lazy[p] = val;
      propagate(p, L, R);
    }
    else {
      int m = (L+R)/2;
      update(l(p), L, m, i, min(m, j), val);
      update(r(p), m+1, R, max(i, m+1), j, val);
      int lsubtree = (lazy[l(p)] != -1) ? lazy[l(p)] : st[l(p)];
      int rsubtree = (lazy[r(p)] != -1) ? lazy[r(p)] : st[r(p)];
      st[p] = conquer(lsubtree, rsubtree);
    }
  }

public:
  SegmentTree(int sz) : n(sz), A(n), st(4*n), lazy(4*n, -1) {}

  SegmentTree(const vi &initialA) : SegmentTree((int)initialA.size()) {
    A = initialA;
    build(1, 0, n-1);
  }

  void update(int i, int j, int val) { update(1, 0, n-1, i, j, val); }
  int RMQ(int i, int j) { return RMQ(1, 0, n-1, i, j); }
};


#include <vector>
#include <cassert>

template<typename T, typename AssociativeOperation>
struct segment_tree {
    int SZ;
    T identity;
    AssociativeOperation TT;
    std::vector<T> data;

    segment_tree() {}

    segment_tree(int _SZ, T _identity, AssociativeOperation _TT)
            : SZ(_SZ), identity(_identity), TT(_TT) {
        data.resize(2 * SZ, identity);
    }

    // Returns the value at index i
    const T& operator[](int i) const {
        assert(0 <= i && i < SZ);
        return data[SZ + i];
    }

    // Assigns fn(i) at index i for each i in [0, SZ)
    template<typename Function>
    void assign(Function fn) {
        for (int i = 0; i < SZ; i++)
            data[SZ + i] = fn(i);
        for (int i = SZ - 1; i; i--)
            data[i] = TT(data[2 * i], data[2 * i + 1]);
    }

    // Assigns v at index i
    void assign(int i, T v) {
        assert(0 <= i && i < SZ);
        data[i += SZ] = v;
        for (i /= 2; i; i /= 2)
            data[i] = TT(data[2 * i], data[2 * i + 1]);
    }

    // Returns the result of a left fold of the elements at indices in [first, last) over TT
    T accumulate(int first, int last) const {
        assert(0 <= first && last <= SZ);
        T left = identity, right = identity;
        for (first += SZ, last += SZ; first < last; first /= 2, last /= 2) {
            if (first & 1) left  = TT(left, data[first++]);
            if (last  & 1) right = TT(data[--last], right);
        }
        return TT(left, right);
    }
};



void solve() {
    int n,m; cin >> n >> m;
    vector<int> nums(n); for(auto& i : nums)cin >> i;

    SegmentTree st(nums);
    auto op = [](ll a, ll b){return a+b;};
    segment_tree<ll,plus<ll>> st2(n,0,plus<ll>());
    for(int i = 0; i < n; i++){ st2.assign(i,nums[i]); }

    while(m--){
        int op; cin >> op;

        if(op == 1){
            int i,v; cin >> i >> v;
            //st.update(i,i,v);
            st2.assign(i,v);
        }
        else{
            int l,r; cin >> l >> r;
            cout << st2.accumulate(l, r) << endl;
            // cout << st.RMQ(l,r-1) << endl;
        }
    }
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);precalc();solve();}
