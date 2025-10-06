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
    vector<int> nums(n); for (auto& i : nums)cin >> i;

    // map<int,int> max_counts; // for larger values of nums; not needed because the values are <= n
    vector<int> max_counts(n+1);

    for(int i = 0; i < n; i++){ max_counts[nums[i]] += 1; }

    // for(auto& i : max_counts){cout << i.first << "," << i.second << "; ";} cout << endl;
    for(auto& count : max_counts){
        if(count % k != 0){
            cout << 0 << endl;
            return;
        }
        count /= k;
    }

    // map<int,int> c; // current counts; map is if the values are larger.
    vector<int> c(n+1);
    ll tot = 0;
    int l = 0;

    for(int r = 0; r < n; r++){
        c[nums[r]]++;

        while(c[nums[r]] > max_counts[nums[r]]){
            c[nums[l]]--;
            l++;
        }
        // after the while loop, all counts should be valid; we only increased c[nums[r]], and we shrunk the array until c[nums[r]] was valid
        tot+=r-l+1;
    }
    cout << tot << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
