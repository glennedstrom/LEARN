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
    vector<int> nums; for(auto& i : nums)cin >> i;

    int upper = pow(2,30)-1;
    for(int i = 0; i < upper; i++){
        bitset<30>s(i);

        if(s.count() >= 2){
            // grab the places.
            for(int j = 1; j <= upper; j *= 2) if(i & j){ // loop through the digits to count
                cout << (i & j) << " ";
            }
            cout << endl;
        }
    }
} 

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}


// can you do it or does it need to be recursive?
// maybe just xor dp...
// how do you make sure that you don't xor to zero and hold off at size 1?
//
// 0 2 2
// 
//
// 2 3 1 10
//
// aren't there xor prefix sum
// do those help?
//
// what about an xor fenwick tree?
// you can add and remove things and it will be nlogn
// if the full sum 
