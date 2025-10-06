#include <deque>
#include <functional>
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
* URL:     https://codeforces.com/problemset/problem/242/E
* Date:    Thu Oct  2 07:32:35 2025
* Contest: Codeforces Round 149 (Div. 2):
* Problem: E. XOR on Segment
* Limits:  4000ms, 256MB
*/

template<typename T, typename U,
    typename TAssociativeCombineFunction,
    typename UAssociativeCombineFunction,
    typename UApplicator>
struct segment_tree_lazy {
    int SZ;
    T t_identity;
    U u_identity;
    TAssociativeCombineFunction TT;
    UAssociativeCombineFunction UU;
    UApplicator UT;

    std::vector<T> data;
    std::vector<bool> has_update;
    std::vector<U> updates;

    segment_tree_lazy() {}

    segment_tree_lazy(int _SZ, T _t_identity, U _u_identity,
            TAssociativeCombineFunction _TT, UAssociativeCombineFunction _UU, UApplicator _UT)
            : SZ(_SZ), t_identity(_t_identity), u_identity(_u_identity), TT(_TT), UU(_UU), UT(_UT) {
        data.assign(2 * SZ, t_identity);
        has_update.assign(SZ, false);
        updates.assign(SZ, u_identity);
    }

    template<typename Function>
    void assign(Function fn) {
        for (int i = 0; i < SZ; i++)
            data[SZ + i] = fn(i);
        for (int i = SZ - 1; i; i--)
            data[i] = TT(data[2 * i], data[2 * i + 1]);
        has_update.assign(SZ, false);
        updates.assign(SZ, u_identity);
    }

private:
    void apply_update(int i, const U &u) {
        data[i] = UT(u, data[i]);
        if (i < SZ) {
            has_update[i] = true;
            updates[i] = UU(u, updates[i]);
        }
    }

    void propagate_ancestor_updates(int i) {
        for (int ht = 31 - __builtin_clz(i); ht > 0; ht--) {
            int anc = i >> ht;
            if (has_update[anc]) {
                apply_update(2 * anc, updates[anc]);
                apply_update(2 * anc + 1, updates[anc]);
                has_update[anc] = false;
                updates[anc] = u_identity;
            }
        }
    }

    void recompute_ancestors(int i) {
        for (i /= 2; i; i /= 2)
            data[i] = UT(updates[i], TT(data[2 * i], data[2 * i + 1]));
    }

    void modify_leaf(int i, T v, bool overwrite) {
        i += SZ;
        propagate_ancestor_updates(i);
        data[i] = overwrite ? v : TT(data[i], v);
        recompute_ancestors(i);
    }

public:
    // Assigns v at index i
    void assign(int i, T v) {
        modify_leaf(i, v, true);
    }

    // Replaces the current value at index i with TT(current value, v)
    void combine_and_assign(int i, T v) {
        modify_leaf(i, v, false);
    }

    // Applies update u to the elements at indices in [first, last)
    void apply_update(int first, int last, U u) {
        assert(0 <= first && last <= SZ);
        first += SZ, last += SZ;

        propagate_ancestor_updates(first);
        propagate_ancestor_updates(last - 1);

        for (int i = first, j = last; i < j; i /= 2, j /= 2) {
            if (i&1) apply_update(i++, u);
            if (j&1) apply_update(--j, u);
        }

        recompute_ancestors(first);
        recompute_ancestors(last - 1);
    }

    // Accumulates the elements at indices in [first, last)
    T accumulate(int first, int last) {
        assert(0 <= first && last <= SZ);
        first += SZ, last += SZ;

        propagate_ancestor_updates(first);
        propagate_ancestor_updates(last - 1);

        T left = t_identity, right = t_identity;
        for (int i = first, j = last; i < j; i /= 2, j /= 2) {
            if (i&1) left = TT(left, data[i++]);
            if (j&1) right = TT(data[--j], right);
        }
        return TT(left, right);
    }

    // Returns the current value at index i
    T read(int i) {
        i += SZ;
        propagate_ancestor_updates(i);
        return data[i];
    }
};


struct Node{
    static constexpr int BITS = 20;
    //vector<ll> bit_count;
    ll bit_count[BITS];
    //ll val;
    ll length;


    Node(){ memset(bit_count,0,sizeof(bit_count)); length = 1;}//bit_count.resize(BITS,0);
    //creating constructors deletes others, AVOID!
    //Node(const Node& rhs) : bit_count(rhs.bit_count), val(rhs.val){  }
    //Node(Node&& rhs) : bit_count(std::move(rhs.bit_count)), val(std::move(rhs.val)){ }

    Node(ll num){
        //val = num;
        length = 1;
        //bit_count.resize(BITS,0);
        memset(bit_count,0,sizeof(bit_count));

        ll cur = num;
        for(ll i = 0; i < BITS; i++){
            bit_count[i] = ((1 << i) & num) != 0;
        }
    }

    ll get(){
        ll tot = 0;
        for(ll i = 0; i < BITS; i++){
            tot += (1 << i) * bit_count[i];
        }
        return tot;
    }

    Node operator+(const Node& rhs){
        Node out;
        //out.val = val + rhs.val;
        out.length = length + rhs.length;

        for(ll i = 0; i < BITS; i++){
            out.bit_count[i] += bit_count[i] + rhs.bit_count[i];
        }
        return out;
    }
    Node operator+(const ll& rhs){
        return *this + Node(rhs);
    }
    Node operator^(const ll& rhs){
        Node out;
        out.length = length;
        //out.val = 0;

        for(ll i = 0; i < BITS; i++){
            if(rhs & (1 << i)){ // if rhs bit is on; flip bits
                out.bit_count[i] = length - bit_count[i]; // flip bits
            }
            else{ 
                out.bit_count[i] = bit_count[i];
            } // bits stay the same
            //out.val += out.bit_count[i] * (1 << i);
        }

        return out;
    }
};

void solve() {
    int n; cin >> n;

    vector<int> v(n+1);
    for(int i = 1; i <= n; i++){ cin >> v[i]; }

    // merge two nodes up the tree
    auto TT = [](Node& t0, Node& t1){return t0+t1;};//Node{t0.x^t1.x, t0.size+t1.size};};

    auto UU = [](ll new_u, ll old_u){return new_u ^ old_u;};

    //merge update into tree node
    auto UT =[](ll u, Node t){return t^u;};
    // node-wise xor with value

    segment_tree_lazy<Node, ll, decltype(TT), decltype(UU), decltype(UT)> st(n+1,Node(),0,TT,UU,UT);

    //for(ll i = 1; i <= n; i++){
    //    st.assign(i,Node(v[i]));
    //}
    int i = 1;
    st.assign([&](int i){
        return Node(v[i]);
    });
    ll q; cin >> q;

    vector<ll> out(q,-1);
    int idx = 0;
    while(q--){
        ll op; cin >> op;

        if(op == 1){
            ll l,r; cin >> l >> r;
            //cout << st.accumulate(l, r+1).get() << endl;
            out[idx] = st.accumulate(l, r+1).get();
            //out[idx] = st.accumulate(l, r+1).val;
            idx++;
        }
        else{
            ll l,r,x; cin >> l >> r >> x;
            st.apply_update(l, r+1, x);
        }
    }

    for(int i = 0; i < idx; i++){
        cout << out[i] << '\n';
    }
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
