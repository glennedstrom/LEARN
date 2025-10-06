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
    int n,k,minlen,maxlen; cin >> n >> k >> minlen >> maxlen;

    vector<int> sym(n); for(auto& i : sym) cin >> i;

    //multiset<int> s;
    map<int,int> m;
    int tot = 0;
    int l = 0;
    int distinct = 0;
    for(int r = 0; r < n; r++){
        //s.insert(sym[r]);
        m[sym[r]]++;
        if(m[sym[r]] == 1){ distinct++; }
        //while(s.count(sym[r]) > 1 || m.size() > k){
        while(distinct > k){ // distinct and
            //s.erase(s.find(sym[l]));
            m[sym[r]]--;
            l++;
            if(m[sym[r]] == 0){ distinct--; }
        }

        //if(s.size() >= minlen && s.size() <= maxlen && m.size() == k){
        if(r-l+1 >= minlen && r-l+1 <= maxlen && distinct == k){
            tot += r-l+1 - minlen+1;
        }
    }

    cout << tot << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
