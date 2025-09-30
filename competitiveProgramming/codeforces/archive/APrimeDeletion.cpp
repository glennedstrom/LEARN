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

bool is_prime(int n){

    for(int i = 2; i*i <= n; i++){
        if(n % i == 0){
            return false;
        }
    }

    return true;
}

void solve() {
    int n; cin >> n;
    string s = to_string(n);

    for(int i = 0; i < 511; i++){ // 2^9 - 1
        string num = "";
        for(int j = 8; j >= 0; j--){ // loop backwards through the powers of 2
            bool has_digit = i & (int)pow(2,j);
            // cout << has_digit << endl;
            if(has_digit){ // if true, grab the top digit
                num += s[8-j];
            }
        }
        // cout << num << endl;
        if(num.length() >= 2 && is_prime(stoi(num)) ){
            cout << num << endl;
            return;
        }
        
    }
    cout << -1 << endl;
}

int main(){int t;cin>>t;while(t--){solve();}ios_base::sync_with_stdio(false);cin.tie(NULL);}//{solve();ios_base::sync_with_stdio(false);cin.tie(NULL);}


























