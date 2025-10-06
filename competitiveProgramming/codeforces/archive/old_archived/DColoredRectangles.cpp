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
    int r,g,b; cin >> r >> g >> b;

    vector<int> red(r); for(auto& i : red) cin >> i; sort(red.rbegin(),red.rend());
    vector<int> green(g); for(auto& i : green) cin >> i;sort(green.rbegin(),green.rend());
    vector<int> blue(b); for(auto& i : blue) cin >> i;sort(blue.rbegin(),blue.rend());
    red.insert(red.begin(),0); green.insert(green.begin(),0); blue.insert(blue.begin(),0);
    r++;g++;b++; // fix indexes

    int o = INT32_MIN;
    vector dp(r+3, vector(g+3, vector<int>(b+3,0))); // last 3 is for rg,rb,gb pairs

    // I think I'm starting wrong
    // I need red[0] * green[0] to be one; this is i=1,j=1,k=0
    // I need red[0] * blue[0] to be one; this is i=1,j=0,k=1
    // I need green[0] * blue[0] to be one; this is i=0,j=1,k=1
    //
    // Start from these, then build after.
    // dp[1][1][0] = red[0]*green[0];
    // dp[1][0][1] = red[0]*blue[0];
    // dp[0][1][1] = green[0]*blue[0];

    // move from dp[0][0][0]
    // dp[1][1][0] = dp[0][0][0] + red[1-1] * green[1-1];
    // dp[1][0][1] = dp[0][0][0] + red[1-1] * blue[1-1];
    // dp[0][1][1] = dp[0][0][0] + green[1-1] * blue[1-1];


    // dp[1][1][1] = dp[0][0][1] + red[1-1] * green[1-1];
    // dp[1][1][1] = dp[0][1][0] + red[1-1] * blue[1-1];
    // dp[1][1][1] = dp[1][0][0] + green[1-1] * blue[1-1];
    //
    // for(int i = 0; i < r; i++){
    //     for(int j = 0; j < g; j++){
    //         for(int k = 0; k < b; k++){
    //             if(i+1 <= r && j+1 <= g){
    //                 dp[i+1][j+1][k] = max(dp[i+1][j+1][k], dp[i][j][k] + red[i+1]*green[j+1]);
    //             }
    //             if(i+1 <= r && k+1 <= b){
    //                 dp[i+1][j][k+1] = max(dp[i+1][j][k+1], dp[i][j][k] + red[i+1]*blue[k+1]);
    //             }
    //             if(j+1 <= g && k+1 <= b){
    //                 dp[i][j+1][k+1] = max(dp[i][j+1][k+1], dp[i][j][k] + green[j+1]*blue[k+1]);
    //             }
    //             o = max(dp[i][j][k],o);
    //             //cout << o << ' ';
    //         }
    //         //cout << endl;
    //     }
    //     //cout << endl;
    // }


    for(int i = 0; i < r; i++){
        for(int j = 0; j < g; j++){
            for(int k = 0; k < b; k++){
                // NOTE: if statements are KEY for the initialization instead of 1-indexed & without. Start where you want to start and end where you want to end OR initialize base cases properly
                if(i-1 >= 0 && j-1 >= 0){ dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k] + red[i]*green[j]); }
                if(i-1 >= 0 && k-1 >= 0){ dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-1] + red[i]*blue[k]); }
                if(j-1 >= 0 && k-1 >= 0){ dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k-1] + green[j]*blue[k]); }

                o = max(dp[i][j][k],o);
                // cout << i << " " << j << " " << k << " : " << dp[i][j][k] << endl;
            }
        }
    }
    cout << o << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
