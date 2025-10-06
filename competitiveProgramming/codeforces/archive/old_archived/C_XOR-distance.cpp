#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void precalc(){
    // optional
}

void solve() {
    long long a,b,r; cin >> a >> b >> r;


    auto xor_dist = [&](long long x){return abs(a^x-b^x);};
    // bitwise dp?
    vector dp(63, vector<ll>(63,0));
    //init
    for(ll i = 0; i < dp.size(); i++){
        dp[i][0] = 1ll << i;
        dp[0][i] = 1ll << i;
    }

    // do I need a third loop inside to grab all possible distances to put in dists_shortened?
    // loop through all i's less than current and get min(dp[i-1-x][j], dp[i-1-x][j]^i)
    // same with j's
    // push all to dists_shortened
    // sort
    // take best option in bounds (or limit putting it in in the first place?)
    // has to be optimal?
    //
    // basically: all possible previous values: what's the best option to xor with me right now?
    // grab it and move on.
    //
    // Is it needed to be 2d? I think so because this allows you to pick some "out of order"
    //ll best = INT64_MAX;
    //for(ll i = 1; i < dp.size(); i++){ // rows
    //    for(ll j = 1; j < dp.size(); j++){ // cols
    //        ll xor1 = 1ll << i, xor2 = 1ll << j;
    //        vector<ll> dists_shortened = { dp[i-1][j], dp[i][j-1], dp[i-1][j]^xor1, dp[i][j-1]^xor2 };

    //        for(int k = 0; k < i; k++){ dists_shortened.push_back(dp[k][j]^xor1); }
    //        for(int k = 0; k < j; k++){ dists_shortened.push_back(dp[i][k]^xor2); }
    //        ranges::sort(dists_shortened, [xor_dist](ll a, ll b){
    //            return xor_dist(a) < xor_dist(b);
    //        });
    //        //vector<pair<ll,ll>> dists = {
    //        //    {xor_dist(dp[i-1][j]), dp[i-1][j]},
    //        //    {xor_dist(dp[i][j-1]), dp[i][j-1]},
    //        //    {xor_dist(dp[i-1][j]^xor1), dp[i-1][j]^xor1},
    //        //    {xor_dist(dp[i][j-1]^xor2), dp[i][j-1]^xor2}
    //        //};
    //        //sort(dists.begin(),dists.end());

    //        //dp[i][j] = dists[0].second;
    //        int o = INT64_MAX;
    //        for(auto& val : dists_shortened){ // take the best option still bounded by our limiter
    //            if(val <= r){
    //                o = val;
    //                break;
    //            }
    //        }
    //        dp[i][j] = dists_shortened[0];
    //        best = min(xor_dist(dp[i][j]), best); // best dist
    //    }
    //}

    //for(auto& i : dp){ for(auto& j : i){ cout << fixed << setw(10) << j << ' '; } cout << endl; } cout << endl;

    //cout << best << endl;
    //return;

    // loop through and try every bit
    // NOTE: Here I'm trying the solution from tutorial, not finished
    ll x = 0;
    for(ll i = 0; i <= __lg(a); i++){
        if((x | (1 << i)) <= r && (a ^ b) & (1 << i)){ // if the i'th bit is different
            x |= (1 << i);
        }
    }
    cout << x << endl;
    return;
    //for(ll i = 1; i <= r; i <<= 1){
    for(ll i = __lg(r); i > 0; i >>= 1){
        if((x ^ i) <= r && xor_dist(x^i) < xor_dist(x)){
            //x ^= i;
            x = x ^ i; // save current change as best dist
        }
    }

    // now try to replace each rep with it

    for(ll rep = 1; rep <= r; rep <<= 1){ // specific bit to attempt to replace: "undo" rep and replace with a new one
        if(!(x&rep))continue; // only take bits that were on to replace them
        ll best = x; // ^ 0
        //for(ll i = __lg(r); i > 0; i >>= 1){
        for(ll i = 1; i <= r; i <<= 1){
            if(i == rep)continue;
            if((x ^ rep ^ i) <= r && xor_dist(x^rep^i) < xor_dist(x)){ // if it's better to undo rep and put i
                //x ^= i;
                best = x ^ rep ^ i; // save current change as best dist
            }
        }
        x = best; // set to new best
    }

    assert(x <= r);
    assert(x >= 0);
    cout << xor_dist(x) << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;precalc();while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);precalc();solve();}
