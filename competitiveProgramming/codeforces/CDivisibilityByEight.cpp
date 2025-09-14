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
    string n; cin >> n;

    // loop backwards to dp from the ones place then the tens place
    //
    // dp[i] = dp[i+1]

    int top = 64;
    vector<unordered_map<char,int>> count(to_string(top*8).size()); // ones place, character, count
    for(int i = 1; i <= top; i++){
        string si = to_string(i*8);
        reverse(si.begin(),si.end());
        for(int j = 0; j < si.size(); j++){
            count[j][si[j]]++;
        }
        //cout << 8*i << endl;
    }
    for(int digit = 0; digit < count.size(); digit++){
        cout << "DIGIT : " << digit << endl;
        for(auto& [ch,cnt] : count[digit]){
            cout << ch << "," << cnt << " ";
        }
        cout << endl;
    }
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
