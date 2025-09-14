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
    int n; cin >> n;

    vector<vector<int>> grid(n);

    int kmax = 0;
    for (int i = 0; i < n; i++){
        int k; cin >> k;
        kmax = max(k,kmax);
        vector<int> row(k);
        for (auto& r : row)cin >> r;
    }

    // simulate gravity (make them fall) then grab the row with the smallest alphabetical order
    //
    // RESIZE TO MAX K FIRST
    // bottom to top from the last to the first blank spot: loop upwards, and grab the closest value and move it down
    //
    //
    // NO:
    // loop across the bottom row, keep track of a jump counter for every iteration
    // put the results in an answer matrix and 
    cout << "NEWTEST" << endl;
    int j = 0;
    for(int i = n-1; i >= 0; i--){
        cout << i << endl;
        for(; j < grid[i].size();){
            cout << grid[i][j] << endl;
            j++;
        }
    }
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
