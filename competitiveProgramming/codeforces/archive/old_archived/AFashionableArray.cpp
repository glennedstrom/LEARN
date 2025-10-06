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
    int n; cin >> n;
    vector<int> nums(n);


    for(int i = 0; i < n; ++i){cin >> nums[i]; }
    sort(nums.begin(),nums.end());
    int high = nums[nums.size()-1], low = nums[0];
    int lhs = 0;
    int rhs = 0;
    //cout << high << " " << low << " : " << high + low << endl;
    if((high + low) % 2 == 1){
        //cout << "A";
        int i = 0;
        int original = nums[i] % 2;
        while(i < n && nums[i] % 2 == original){
            lhs++;
            i++;
        }
        i = n-1;
        original = nums[i] % 2;
        while(i >= 0 && nums[i] % 2 == original){ // while equal to the end one (to flip it from 0 to 1 or 1 to 0)
            rhs++;
            i--;
        }
        // cout << lhs << " " << rhs << endl;
        cout << min(lhs,rhs) << endl;
    }
    else{
        cout << 0 << endl;
    }
}

int main(){int t;cin>>t;while(t--){solve();}ios_base::sync_with_stdio(false);cin.tie(NULL);}//{solve();ios_base::sync_with_stdio(false);cin.tie(NULL);}
