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
    int n;cin >> n;
    vector<int> nums(2*n); for(auto& i : nums)cin >> i;


    sort(nums.begin(),nums.end());

    int l = 0, r = n*2-1;
    int tot = 0;
    for(int i = 0; i < n; i++){
        tot += nums[r] - nums[l];
        cout << nums[r] - nums[l] << ' ';
        l++;
    }
    cout << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
