#include <bits/stdc++.h>
using namespace std;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

void solve() {
    int n; cin >> n;
    vector<int> hp(n); for(int i = 0; i < n; i++) cin >> hp[i];

    long long hits = 0;

    // make a list of targets? anyone n off the ground will auto-die if you do it in the right order
    // if you kill the bottom guy every time, it only does 1 extra damage. if you kill the 2nd to top guy every time, it does n damage.

    for(int i = n-2; i >= 0; i++){ // don't damage the top guy unless he is the last one left. he will take fall damage

    }
}

// hp[n-2] + max(0,hp[n-1] - (len()-1 fall damage)); WHAT ABOUT 1 4 1? 8 does more damage than 4 to 4 because 1 doesn't need the full fall damage.
//
// if(doesn't need full fall damage){try the next one?}
// how do you determine how far to go?
//
// 1 8 1 2 3 4
//           
//  for the second half:
//  4 if you kill 3 then 1
//  (still preserves greedy order, otherwise you don't do much damage to the top one)
//
//  
//
// 7 if you start at 2nd 1 and kill the stack
// 4 if you do 
//
// if(next >= current) knock your current one out.
//
// find a function valuing each move:
// 3 + max(0,4-fall_damage);
// vs
// 2 + max(0,3-fall_damage. -> if died, fall damage + 1 recursively to the node above)

int main(){ int testcase; cin >> testcase; while(testcase--){ solve(); } }//{solve();}
