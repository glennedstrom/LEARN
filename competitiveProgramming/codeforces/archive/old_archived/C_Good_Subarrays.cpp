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
    int x; cin >> x;
    string s = to_string(x);
    int n = s.size();

    vector<int>v(n); for(int i = 0; i < s.size(); i++){v[i] = s[i] - '0';}

    int tot = 0;
    int acc = 0;
    int l = 0;

    for(int r = 0; r < n; r++){
        acc += v[r];

        while(acc < r-l+1){
            acc -= v[l];
            l++;
        }

        //6*10-6-10cout << l << ' ' << r << endl;
        tot += r-l+1; // huh? how many do I add? this is the hard part.
        //
        // You don't add r-l+1 because not every subarray of a good array is good.
        //
        // Probably keep track of how many are good in a queue somehow or two stacks??
    }

    cout << tot << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
