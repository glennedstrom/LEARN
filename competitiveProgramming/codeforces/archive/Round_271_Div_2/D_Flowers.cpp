#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
* URL:     https://codeforces.com/problemset/problem/474/D
* Date:    Sat Oct  4 22:04:56 2025
* Contest: Codeforces Round 271 (Div. 2):
* Problem: D. Flowers
* Limits:  1500ms, 256MB
*/

// a=4,k=2 is:
// RRRR
// WWRR
// RWWR
// RRWW
// WWWW
//
// a=4,b=5,k=2 is:
// RRRR
// WWRR
// RWWR
// RRWW
// WWWW
// RRRRR
// WWRRR
// RWWRR
// RRWWR
// RRRWW
// WWWWR
// WWRWW
// RWWWW

const ll MOD = 1e9+7;
//const ll UPPERCHOOSE = 1e5+1;

vector<ll> fact = {1,1};
ll factorial(ll n){
    for(ll i = fact.size(); i <= n; i++){
        fact.push_back(fact[(fact.size()-1)]*i%MOD);
    }
    return fact[n];
}

ll mod_inv(ll n){
    // compute n^(mod-2) % mod

    return 1;
}

//vector<vector<ll>> nCk(UPPERCHOOSE, vector<ll>(UPPERCHOOSE,0));
ll choose(ll n, ll k){
    assert(n>=k);
    return factorial(n) * mod_inv(factorial(k)) * mod_inv(factorial(n-k));
}

//void pascal(){
//    // BAD because factorial already mods the number, can't divide a modded num
//    // initialize first column to 1
//    for(ll i = 0; i < nCk.size(); i++){ nCk[i][0] = 1; }
//
//    for(ll i = 1; i < nCk.size(); i++){
//        for(ll j = 1; j <= i; j++){
//            nCk[i][j] = (nCk[i-1][j-1] + nCk[i-1][j]) % MOD;
//        }
//    }
//}

ll k;
void precalc(){
    //pascal();
    cin >> k;
}

void solve() {
    ll a,b; cin >> a >> b;
    //for(auto& row : nCk){
    //    for(auto& o : row) if(o != 0){
    //        cout << o << ' ';
    //    }
    //    cout << endl;
    //}

    // for every value that satisfies R + W*k == X
    // where X ∈ [l,r]

    ll tot = 0;
    for(ll X = a; X <= b; X++){
        for(ll W = 0; W*k <= X; W++){ // white flower values
            ll R = X - W*k;
            ll n = R + W;
            //cout << X << "," << W << choose(X,R) << endl;
            tot = (tot + choose(n,W)) % MOD;
        }
    }
    cout << tot << endl;

    // 1st: any combo of R's between a and b
    // 2nd: any combo of k W's and a-k R's up to b R's
    // ...increment by k
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;precalc();while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);precalc();solve();}
