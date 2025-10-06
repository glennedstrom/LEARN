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
    long long n; cin >> n;
    long long abssum = 0;
    long long min_num = INT64_MAX;
    long long negcount = 0;
    bool zero_exists = false;
    vector<long long> nums(n); for(int i = 0; i < n; i++){ cin >> nums[i]; abssum += abs(nums[i]); negcount += nums[i] < 0; zero_exists = max(zero_exists,nums[i] == 0); min_num = min(min_num,abs(nums[i]));}

    if(negcount % 2 == 0 || zero_exists){ cout << abssum << endl; return; }

    cout << abssum - 2*min_num << endl;
}

int main(){int t;cin>>t;while(t--){solve();}ios_base::sync_with_stdio(false);cin.tie(NULL);}//{solve();ios_base::sync_with_stdio(false);cin.tie(NULL);}
