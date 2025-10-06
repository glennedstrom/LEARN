#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
* URL:     https://codeforces.com/contest/2155/problem/C
* Date:    Sun Oct  5 11:59:40 2025
* Contest: Codeforces Round 1056 (Div. 2):
* Problem: C. The Ancient Wizards' Capes
* Limits:  2000ms, 256MB
*/

const ll CHOOSE_LIM = 200;
const ll MOD = 1e9+7;

vector<ll> fact = {1,1};
ll factorial(int n){
    for(int i = fact.size(); i <= n; i++){
        fact.push_back(fact[(fact.size()-1)]*i%MOD);
    }
    return fact[n];
}
vector<vector<ll>> nCk(CHOOSE_LIM, vector<ll>(CHOOSE_LIM,0));
ll choose(int n, int k){
    assert(n>=k);
    return nCk[n][k];
}

void precalc(){
    for(int i = 0; i < nCk.size(); i++){ nCk[i][0] = 1; }

    for(int i = 1; i < nCk.size(); i++){
        for(int j = 1; j <= i; j++){
            nCk[i][j] = (nCk[i-1][j-1] + nCk[i-1][j]) % MOD;
        }
    }
}

// if a node is n:
// - everyone must look away. 1 way
//
// if a node is n-1

void solve() {
    int n; cin >> n;
    vector<int> v(n); for(auto& i : v) cin >> i;
    vector<int> c(n+1);
    for(int i = 0; i < n; i++){
        c[v[i]]++;
    }
    //cout << "C: ";
    //for(int i = 0; i < n; i++){
    //    cout << c[i] << ' ';
    //}
    //cout << endl;

    // edge case?
    if(n == 1){ cout << 2 << endl; }

    vector<int> wiz_dir(n,1); // right facing
    vector<int> wiz_cnt(n);
    ranges::iota(wiz_dir,1);
    // starting with all looking to the right.
    auto flip_dir = [&](int target){
        for(int i = 0; i < n; i++){
            if(i < target){
                wiz_cnt[i] += wiz_dir[target];
            }
            else if (i > target) {
                wiz_cnt[i] -= wiz_dir[target];
            }
        }
        wiz_dir[target] *= -1;
    };

    

    // make them look to the left until it's valid.

    // try to 
    for(int i = 0; i < n; i++){

    }
    int high = v[0];
    ll o =0;
    for(int i = 0; i < n; i++){
        high = max(high,v[i]);

        if(choose(n,v[i]) != 0){
            o = min(o,choose(n/2,v[i]/2));
        }
        cout << choose(n,v[i]) << ' ';
    }
    cout << endl;
    //cout << choose(n-1,high-1) << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;precalc();while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);precalc();solve();}
