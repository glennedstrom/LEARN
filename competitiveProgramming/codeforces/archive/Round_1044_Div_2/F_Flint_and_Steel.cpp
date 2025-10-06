#include <cstdint>
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
* URL:     https://codeforces.com/contest/2133/problem/F
* Date:    Wed Oct  1 06:42:12 2025
* Contest: Codeforces Round 1044 (Div. 2):
* Problem: F. Flint and Steel
* Limits:  2000ms, 256MB
*/

void precalc(){ } // optional

// NOT EVEN CLOSE: this is exponential
// NOTE: This does not work because this is greedy and you need to know "Who you blow up and when"
// What about instead of taking the first node, we try to take the first zero? or all zeros?
/*int divide_and_boom(vector<int>& creepers, int l, int r){
    if(l > r)return 0; // empty
    
    // minimum element
    vector<int> targets;
    int smol = creepers[l];
    for(int i = l; i <= r; i++){smol = min(smol,creepers[i]);}
    //cout << smol << endl;
    //int target = l; 
    for(int i = l; i <= r; i++) if(creepers[i] == smol){
        targets.push_back(i);
        //target = i;
    }

    int best = INT32_MAX; // only return best IF you kill all creepers in your range
    for(auto& target : targets){
        for(int i = l; i <= r; i++){
            // try to blow up creeper target
            if(abs(i-target) < creepers[i]){ // determined left guy can blow up
                //cout << i-l << " " << creepers[i] << endl;
                int lhs = divide_and_boom(creepers, l, i-creepers[i]);
                int rhs = divide_and_boom(creepers, i+creepers[i], r);
                if(lhs != -1 && rhs != -1){
                    best = min(best,lhs+rhs+1);
                }
            }
        }
    }
    return best == INT32_MAX ? -1 : best; // update parent map here too OR RETURN WHO BLEW UP?
}//*/

// top down approach
int top_down(){
    return 1;
}

void solve() {
    int n; cin >> n;

    vector<int> creepers(n); for(auto& i : creepers) cin >> i;

    // NOTE: "Order matters"

    //cout << divide_and_boom(creepers, 0, n-1) << endl;

    // either blow up current creeper & count OR don't and try to blow up the next creepers instead that you would have killed off
    //
    // if you blow up a creeper, move forwards that distance and count++ ONLY IF ALL CREEPERS HAVE DIED SO FAR; Don't take a path if you can't kill all creepers. (BAD PATH)

    // can you do it with just 1d? I think so, just only step forwards if you kill everyone behind you. otherwise don't.
    // How do you keep track of killing everyone behind you?
    //
    // for each node, either blow up the current creeper, or find a creeper in the future to blow yourself up. Move forwards by the blast radius. If you can't go further, -1
    vector<int> dp(n, 0); 
    
    // loop through and find all people who can kill the first guy. If this guy never dies, game over

    // NOTE: Maybe 2d dp? dp[creeper][num_detonated]
    for(int i = 0; i < n; i++){ // try to kill creeper i
        for(int j = i; j <= n; j++){ // FIND A CREEPER TO BLOW i UP
            if(j-i < creepers[j]){ // boom
                // BLAST from j-creepers[j]+1 to j+creepers[j]-1

                // kill everyone in this range:
                int l = j-creepers[j]+1;
                int r = j+creepers[j]-1;
                for(int k = l; k <= r; k++){ // NOTE: possibly lazy seg tree for faster range updates?
                    dp[k] = min(dp[j]+1,dp[k]); // DP[k] is either dp[j]+1 OR dp[k] if killed by someone else
                }
            }
        }
        if(dp[i] == 0){ // nobody can kill me
            cout << -1 << endl;
            return;
        }
    }
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;precalc();while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);precalc();solve();}
