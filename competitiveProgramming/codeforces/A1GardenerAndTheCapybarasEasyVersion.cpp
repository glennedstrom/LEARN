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
    string names;
    cin >> names;
    // starts with a, there is: b, there is an a after that b
    // starts with b, there is: a, there is an b after that a
    // all a's or all b's because they are alphabetically the same.
    //
    //just try and brute force

    for(int s1 = 1; s1 < names.size()-1; s1++){
        for(int s2 = s1+1; s2 < names.size(); s2++){
            vector<string> strings = {names.substr(0,s1), names.substr(s1,s2-s1),names.substr(s2,names.size()-s2)};
            // for(auto& s : strings){cout << s << " ";}
            // cout << endl;
            if((strings[0] <= strings[1] && strings[2] <= strings[1]) || (strings[0] >= strings[1] && strings[2] >= strings[1])){
                cout << strings[0] << " " << strings[1] << " " << strings[2] << endl;
                return;
            }
        }
    }
    cout << ":(" << endl;
}

int main(){int t;cin>>t;while(t--){solve();}ios_base::sync_with_stdio(false);cin.tie(NULL);}//{solve();ios_base::sync_with_stdio(false);cin.tie(NULL);}
