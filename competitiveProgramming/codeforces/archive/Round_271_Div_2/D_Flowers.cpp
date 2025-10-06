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

vector<ll> fact = {1,1};
ll factorial(int n){
    for(int i = fact.size(); i <= n; i++){
        fact.push_back(fact[(fact.size()-1)]*i%MOD);
    }
    return fact[n];
}

vector<vector<ll>> nCk(100, vector<ll>(100,0));
ll choose(int n, int k){
    assert(n>=k);
    return nCk[n][k];
}

void pascal(){
    // BAD because factorial already mods the number, can't divide a modded num

    // initialize first column to 1
    for(int i = 0; i < nCk.size(); i++){ nCk[i][0] = 1; }

    for(int i = 1; i < nCk.size(); i++){
        for(int j = 1; j <= i; j++){
            nCk[i][j] = (nCk[i-1][j-1] + nCk[i-1][j]) % MOD;
        }
    }
    //for(int i = 0; i < 100; i++){
    //    for(int k = 0; k <= i; k++){
    //        nCk[i][k] = factorial(i)/factorial(k)/factorial(i-k);
    //    }
    //}
    // dp[0] =     {1}
    // dp[1] =    {1,1}
    // dp[2] =   {1,2,1}
    // dp[3] =  {1,3,3,1}
    // dp[3] = {1,4,6,4,1}
    //
    // what's this dp transition like?
    //
    // dp[i][0] = 1; for all i
    //
    // for j in range(len(prev+1))
    // dp[i][j] = dp[i][]
}

ll k;
void precalc(){
    pascal();
    cin >> k;
}

void solve() {
    ll a,b; cin >> a >> b;
    for(auto& row : nCk){
        for(auto& o : row) if(o != 0){
            cout << o << ' ';
        }
        cout << endl;
    }
    return;

    // step 1: get all multiples of k in the range from 0 to a to b
    // step 2: sum the range of red flowers.
    //
    // let W = number of white flowers
    // let x = b - W
    // tot += x*(x+1)/2
    ll tot = 0;
    for(ll W = 0; W <= b; W+=k){ // white flower values
        ll x = b - W;
        tot += x*(x+1)/2 % (ll)(1e9+7);
        //ll redlow = max(a,W)-W; // how many red flowers on the lower end
        //ll redhigh = b-k;
        // white is i
        // red is everything from max(a,i)-k to b-k

    }
    cout << tot << endl;

    // 1st: any combo of R's between a and b
    // 2nd: any combo of k W's and a-k R's up to b R's
    // ...increment by k
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;precalc();while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);precalc();solve();}
