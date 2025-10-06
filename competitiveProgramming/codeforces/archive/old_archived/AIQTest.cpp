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
    int oc = 0;
    vector<int> nums(n); for(int i = 0; i < n; i++){cin >> nums[i];oc += nums[i] % 2 == 1;}

    if(oc == 1){
        for(int i = 0; i < n; i++){
            if(nums[i] % 2 == 1){
                cout << i+1 << endl;
                return;
            }
        }
    }
    else{
        for(int i = 0; i < n; i++){
            if(nums[i] % 2 == 0){
                cout << i+1 << endl;
                return;
            }
        }
    }

}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
