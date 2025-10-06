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

// How to have repeated subproblems:
// l and r pointers
// split
// compute amount of fall damage per scenario instead???
//
// or just straight forward
//
// you need to compute how much damage you could take for each section (ISSUE: Order of the splits matters)
// 
// greedy? find the highest mob that you could do the most damage to and split there? What if there are multiple options? Weight out the cost to make that choice with the damage you save.

vector<int> jockey;

// 1 2 3 4 5
//
// costs with dmg taken out
// 1 1 1 1 1
//
// so the only think that determines which to pick is how much the previous one costs to kill. Adding those back in:
// 1 2 3 4 5
//
// back to where we started on this problem. Maybe this means just take the biggest each time?
//
// Let's try a harder example
// 2 4 2 8 2
//
// cost with dmg taken out: // ISSUE: doesn't really matter how much it costs to kill 
// 2 2 0 5 -2
//
// adding in how much the previous costs to kill
// 2 4 4 7 6
//
//
// 1 1 1 1
// if you kill the bottom, the next 3 take one fall damage and everyone dies.
//
// optimal choice is kill the bottom one here?
// 
// killing every other does this much in fall damage: 4, 2
// killing them if it does max dmg from left: 1,1,1,1
// neither of those strategies works at all.
//
// Why you don't want to break early before finding the highest dmg you can do:
// 1 1 1 5
// X
// 4
// XXXX
//
// 1 1 1 5
// X   X1
// 2
// XX
// /////
//
// 1 1 1 4 4
//       XXXX
// 1 1 1
// X
//
// 4 1 1 1 1 1 1 1 4

ll chicken_jockey(int l, int r){
    // cout << l << ' ' << r << endl;
    if(l == r){return 0;} // empty
    if(l+1 == r){return jockey[l];} // l hits to finish off the mob? NOTE: (MAKE SURE YOUR RECURSIVE CALLS DON'T DOUBLE-COUNT)

    // NOTE: target - l; because in a split, low is at the bottom

    // NOTE: target == falling guy
    // for(int target = l+1; target < r; target++){ // move forwards and take the first guy you can do equal or greater fall damage to (works in 1 1 1 1)
    //     if(target-l >= jockey[target]){

    //     }
    //     if(fall_dmg < min(target-l, jockey[target])){ // if you can do more damage to the guy above you, good
    //         fall_dmg = min(target-l, jockey[target]);
    //         aim_at = target-1; // index of guy below you to shoot at
    //         //if(jockey[target] >= target-l)break; // maximum fall damage; split here
    //     }
    // }
    //for(int target = r-1; target > l; target--){ // start from a layer where you could do extra damage (someone above you) then move down.
    //
    //calculate based on distance to the most recent chosen split rather than to l?
    // 
    // First candidate is kill the 1 to make 4 fall
    // 4 1 1 1 4 1 3
    //
    // Choose the next 1 to make the 3 fall because:
    // 3 wouldn't be able to fall far enough to kill it if you chose the first option.
    //
    // How to calculate this?
    // compare the current choice (kill 1 to damage 4) to the new choice (kill 1 to damage 3)
    //
    // Comparison: 1 hit, 4 fall damage - (INFO FROM NEXT) <=> 1 hit, 3 fall damage
    // INFO FROM NEXT: how much fall damage would be lost if you killed the first option first:
    // 3-1 damage because it will fall once.
    //
    // MAYBE do multiple options in the 
    //
    // 4 1 1 1 4 1 3
    //       |
    // Worth 4 damage - opportunity_cost
    // 
    // 4 1 1 1 4 1 3
    //           |
    //  Worth 3 damage
    //
    // 4 1 1 1 4 1 3
    //       |
    // 2 // from the first split left over. (NOTE: would have had to do 1 extra hit to kill them in the other order anyways)
    //
    // Net opportunity cost = 2 - 1 // off by 1 because two hits
    //
    // CHECK: 4 + (suboptimal: 1 + 2; optimal: 1 + 1;)
    // 
    // your fall damage - previous fall damage  + 1 (took an extra turn to swap order) == difference after change?
    // 6 - 4 + 1 == 1;
    //
    // 
    //

    ll best = 1e18;

    // current condition MINUS OPPORTUNITY COST OF ALL FUTURE LOSSES SUMMED?
    // if you could recursively do this, it would 'feel' more solid. Doesn't seem possible without exponential
//4 1 1 1 4 1 3
//      |
//        4-3=1
//        (target)-(aim_at+1) = 1
//
//    target-1 == who you delete
//        aim_at == who you deleted
//
//        we need aim_at + 1 for how much damage we lost
//        we need target for how much damage we did
//
//        (target)-(aim_at+1) = 1
//
//        more comprehensive (but not required, cancels out):
//        (target-l)-(aim_at+1-l) = 1
    //
    //        This offset is for when you are considering the second option
    //        You need this to BOOST the chance of the second option
    //        

    int fall_dmg = 0;
    int aim_at = l;
    //for(int target = r-1; target >= l+1; target--){ // move forwards and take the first guy you can do equal or greater fall damage to (works in 1 1 1 1)
    for(int target = l+1; target < r; target++){ // move forwards and take the first guy you can do equal or greater fall damage to (works in 1 1 1 1)
        if(fall_dmg < min(target-l, jockey[target])){ // ISSUE: The only reason this code doesn't work is I am picking the wrong one in this loop 4 1 1 1 4 1 3
            fall_dmg = min(target-l, jockey[target]);
            aim_at = target-1; // index of guy below you to shoot at
        }
    }
    //return best;

    //jockey[aim_at+1] -= fall_dmg;
    //jockey[aim_at+1] = max(jockey[aim_at+1],0);
    jockey[aim_at+1] = max(jockey[aim_at+1]-fall_dmg,0);
    return jockey[aim_at] + chicken_jockey(l, aim_at) + chicken_jockey(aim_at + 1, r); // hit the aim_at guy until he dies to split.
}

// 1 1 1 5 4
//       XXXXX
// 1 1 1
// X
//
void solve() {
    int n; cin >> n;
    jockey.resize(n); for(auto& c : jockey) cin >> c;

    //cout << "j, j-i" << endl;
    //for(int i = 0; i < n; i++){ cout << jockey[i] << ' ' << jockey[i] - i << endl; }

    cout << chicken_jockey(0,n) << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}

