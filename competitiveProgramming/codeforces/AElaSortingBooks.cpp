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
    int n,k; cin >> n >> k;


    string s;
    cin >> s;
    vector<int> letter_count(26);
    for(auto& c : s){ ++letter_count[c - 'a']; } // count each letter
    sort(s.begin(),s.end());

    for(int i = 0; i < k; i++){ // loop through k groups
        int j = 0;
        for(; j < n/k; j++){ // loop through n/k elements in each group
            if(letter_count[j] > 0){ letter_count[j]--; }
            else{ // won't go out of bounds because z is 0
                //cout and break;
                break;
            }
        }
        cout << (char)(j + 'a');
    }
    cout << endl;
}

int main(){int t;cin>>t;while(t--){solve();}ios_base::sync_with_stdio(false);cin.tie(NULL);}//{solve();ios_base::sync_with_stdio(false);cin.tie(NULL);}
