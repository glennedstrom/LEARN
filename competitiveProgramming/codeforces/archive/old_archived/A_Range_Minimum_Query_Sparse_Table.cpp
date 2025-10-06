#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void precalc(){ }

void solve() {
    int n; cin >> n;
    int kmax = __lg(n)+1;

    auto f = [](int a, int b){ return min(a,b); };
    vector st(kmax, vector<int>(n,-1)); // st[k][i]
    for(auto& i : st[0])cin >> i;

    // initialize sparse table
    for(int k = 1; k < kmax; k++)
        for(int i = 0; i + (1 << k) <= n; i++)
            st[k][i] = f(st[k-1][i], st[k-1][i+(1<<(k-1))]);

    // Display table:
    // for(int k = 0; k < kmax; k++){ for(int i = 0; i + (1 << k) <= n; i++) cout << st[k][i] << ' '; cout << endl; } cout << endl;

    int q; cin >> q;
    while(q--){
        int l,r; cin >> l >> r;
        int k = __lg(r-l+1); // plog[r-l+1]; // floor(log2(r-l+1));
        //r++; // past the end then the - (1<<k) shifts it back

        cout << f(st[k][l], st[k][r-(1<<k)+1]) << endl; // go back right - k where k is the power of 2 or size
    }
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;precalc();while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);precalc();solve();}
