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

void solve() {
    int n,m; cin >>n>>m;
    vector<vector<int>> nums(n, vector<int>(m,0));
    for(int i = 0; i < n;i++){ for(int j=0;j<m;j++){ cin >> nums[i][j]; } }
    vector<int> goal = {1,5,4,3};
    int cnt = 0;

    // loop around a nxn grid. start at 0,0 then 1,1 then 2,2 all the way to min(n/2,m/2)
    for(int i = 0; i < min(n/2,m/2); i++){
        //starting spot is i, ending spot is n-i because we take a layer off each time
        int endn = n-i;
        int endm = m-i;
        int cur = 0; // current goal index
        for(int j = i; j < endn; j++){
            // i because how many taken off
            if(nums[j][i] == goal[cur]){ cur++; }
            if(cur == 4){cnt++; cur = 0;} // found it!
        }
        for(int j = i+1; j < endm; j++){
            // i because how many taken off
            if(nums[endm-1][j] == goal[cur]){ cur++; }
            if(cur == 4){cnt++; cur = 0;} // found it!
        }
        //reverse bottom part
        for(int j = endn-2; j >= 0; j--){
            // i because how many taken off
            if(nums[j][endm-1] == goal[cur]){ cur++; }
            if(cur == 4){cnt++; cur = 0;} // found it!
        }
        for(int j = i+1; j < endm; j++){
            // i because how many taken off
            if(nums[endm-1][j] == goal[cur]){ cur++; }
            if(cur == 4){cnt++; cur = 0;} // found it!
        }

        //int endj = m-j;
    }
}
//great problem for practicing indexing, can't finish in time and rushing it makes it worse

int main(){int t;cin>>t;while(t--){solve();}ios_base::sync_with_stdio(false);cin.tie(NULL);}//{solve();ios_base::sync_with_stdio(false);cin.tie(NULL);}
