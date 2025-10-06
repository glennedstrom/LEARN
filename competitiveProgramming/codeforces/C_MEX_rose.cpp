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
    int n,k; cin >> n >> k;


    vector<int> nums(n); for(auto& i : nums)cin >> i;
    multiset<int> s(nums.begin(),nums.end());

    sort(nums.begin(),nums.end());

    int tot = 0;
    for(int i = 0; i < k; i++){
        // i is my current value and index
        if(s.find(i) == s.end()){
            tot++;
        }
    }

    // only tot++ if tot < count(k); if tot >= count(k) then it's even.
    // basically max(tot,count(k))
    //
    // either change a bunch of k's to the other values with (original tots) or not enough to clear k's so push it out of the way with count times
    tot = max(tot,(int)s.count(k));
    //while(s.find(k) != s.end()){
    //    tot++;
    //    s.erase(s.find(k)); // in case there are duplicates
    //}

    cout << tot << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
