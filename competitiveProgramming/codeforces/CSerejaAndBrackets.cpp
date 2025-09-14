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
    string s; cin >> s;
    int q; cin >> q;



    // GOAL: some kind of range query, where you can ask "What is the longest bracket sequence in here?"
    // union find? we can union any proper bracket sequences and union them to 0 if they are invalid to "throw them away"
    // If l and r have the same unio...
    //
    // NO this doesn't work, we need range queries for subsets of valid sequences
    //
    // mark each valid pair where it has a closing parentheses as a valid range
    //
    // mark a single range by doing: 













    int sum = 0;
    vector<bool> valid(s.size());
    for(int i = 0; i < s.size(); i++){
        sum += s[i];
        sum += (s[i] == '(' ? 1 : -1); 
        valid[i] = sum >= 0; // negative values are invalid, 
        if(sum < 0){ sum = 0;} // reset the sum if hit zero to find valid sequences only
    }
    // for(int i = s.size()-1; i >= 0; i-- ){
    //     if(sum[i] > 0){
    //         valid[i] = false;
    //     }
    //     else break;
    //     // you can have intermediate parentheses values like (()() where the entire thing isn't a sequence, but the second to the end is
    // }
    for(auto& p : valid){
        cout << p << " ";
    }
    cout << endl;

    while(q--){
        int l,r; cin >> l >> r;


    }
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
