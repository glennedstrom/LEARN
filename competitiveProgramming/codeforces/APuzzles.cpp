#include <algorithm>
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
    int n,m; cin >> n >> m;
    vector<int> nums(m);
    for(auto& i : nums)cin >> i;
    sort(nums.begin(),nums.end());

    int best = INT32_MAX;
    int r = 0;
    for(int l = 0; l < m; l++){
        while(r < m && r - l < n){
            r++;
        } // push r forwards
        if(r-l != n)break;

        best = min(best, nums[r-1]-nums[l]);
    }

    cout << best << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
