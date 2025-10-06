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

    multiset<int> nums;
    char prev = s[0];
    int cnt = 0;
    for(auto& c : s){
        if(c == '0'){
            if(cnt > 0){ nums.insert(cnt); }
            cnt = 0;
        }
        else{
            cnt++;
        }
    }
    if(cnt > 0){ nums.insert(cnt); }

    int a = 0;
    int turn = true;
    for(auto i = nums.rbegin(); i != nums.rend(); ++i, turn = !turn){
        if(!turn)continue;
        a += *i;
    }
    cout << a << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
