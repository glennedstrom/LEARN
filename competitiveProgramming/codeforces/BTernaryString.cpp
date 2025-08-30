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

// Top-down DP with memoization
string s;
// int memo[1005][1005]; // can't do 200k by 200k
// 
// int dp(int l, int r, int a, int b, int c) {
//   // Base cases
//   if (base_condition) return base_value;
//   
//   // Check memo
//   int &ans = memo[i][j];
//   if (ans != -1) return ans;
//   
//   // Recursive cases
//   ans = initial_value;
//   // Add transitions here
//   
//   return ans;
// }

void solve() {
    cin >> s;
    int a=0,b=0,c=0;

    // for(int i = 0; i < s.size(); i++){
    //     if(s[i] == '1')a++;
    //     else if(s[i] == '2')b++;
    //     else c++;
    // }

    // just two pointers and 3 counters.
    int best = INT32_MAX;
    int r = 0;
    for(int l = 0; l < s.size(); l++){
        while(r < s.size() && (a == 0 || b == 0 || c == 0)){
            if(s[r] == '1')a++;
            else if(s[r] == '2')b++;
            else c++;
            r++;
        }
        if((a == 0 || b == 0 || c == 0)){break;} // not valid
        //  right is adjusted properly now.
        //check for solution
        best = min(best,r-l);
        // remove current.
        if(s[l] == '1')a--;
        else if(s[l] == '2')b--;
        else c--;

    }


    cout << (best == INT32_MAX ? 0 : best) << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
