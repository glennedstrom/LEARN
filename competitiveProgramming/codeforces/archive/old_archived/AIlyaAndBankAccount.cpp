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

    if(n < 0){
        string s = to_string(n);
        if(s[s.size()-1] > s[s.size()-2]){
            s.erase(s.begin() + s.size()-1);
        }
        else{
            s.erase(s.begin() + s.size()-2);
        }
        if(s.length() == 1 && s[0] == '-'){
            cout << 0 << endl;
        }
        else{
            cout << stoi(s) << endl;
        }
    }
    else{
        cout << n << endl;
    }
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
