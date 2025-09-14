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
    vector<int> nums(n); for(auto& i : nums)cin >> i;

    sort(nums.rbegin(),nums.rend());

    int mx = 0;

    int cnt = 1;
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] == nums[i-1]){
            cnt++;
        }
        else{
            if(cnt % 2 == 1){
                cout << "YES" << endl;
                return;
            }
            cnt = 1;
        }
    }
    if(cnt % 2 == 1){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    // if there is one max, take it.
    // if there are two don't 
    // if there are three, take it
    //
    // basically move down the tree if even count.
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
