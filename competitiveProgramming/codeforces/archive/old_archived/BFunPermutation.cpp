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

    vector<int> p(n); for(int i = 0; i < n; i++){ cin >> p[i]; }

    vector<int> vec2(n);iota(vec2.begin(),vec2.end(),1);
    
    unordered_set<int> nums(vec2.begin(),vec2.end()); // pull from here
    int prevSum = 0;//p[1] + n;
    //nums.erase(n);

    vector<int> outnums;
    for(int i = 0; i < n; i++){ // actual indexes
        bool flag = false;
        for(auto& a : nums){
            if(p[i] + a >= 3 && (p[i] + a) % 2 != prevSum % 2){
                cout << a << ' ';
                nums.erase(a);
                outnums.push_back(a);
                prevSum = p[i] + a;
                flag = true;
                break;
            }
        }
        if(!flag){
            //find somewhere else to swap.
            for(int j = 0; j < n; j++){ 
                if(p[i] + a >= 3 && (p[i] + a) % 2 != prevSum % 2){
                    swap(outnums[i],outnums[j]);
                }
            }
        } // I don't have enough time to store the values in an
    }
    cout << endl;
    //as long as both sums aren't even
    
    //for(auto& i : out)cout << i << ' ';cout << endl;

    // GCD of the sum of each pair of indices is more than 2:
    // GCD(p[i] + q[i], p[i+1] + q[i+1]) >= 3

}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
