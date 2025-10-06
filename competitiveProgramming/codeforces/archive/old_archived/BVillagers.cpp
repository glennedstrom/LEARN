#include <bits/stdc++.h>
using namespace std;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;


// NOTE: give yourself easy cin methods like type vi<c-y> to use a snippet for reading in a vector.
// or vi1<c-y> for 1 indexed

void solve() {
    long long n; cin >> n;
    vector<long long> grump(n);
    for(long long i = 0; i < n; i++)cin >> grump[i];

    sort(grump.rbegin(),grump.rend());

    // union friends. if all are friends, you are finished (numSets == 1)

    long long cost = 0;
    for(long long i = 0; i < n; i+=2){
        if(i+1 < n){
            cost += max(grump[i],grump[i+1]);
        }
        else{
            cost += grump[i];
        }
    }
    cout << cost << endl; // simplified to greedy because easy UF


}

// union max pairs as much as you can, then union the last one in for the cost of the last one. Then union the rest for free (not needed, just output)

int main(){ long long testcase; cin >> testcase; while(testcase--){ solve(); } }//{solve();}
