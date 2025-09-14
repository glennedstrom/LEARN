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
    string x; cin >> x;
    string y(x);

    for(auto& c : x){
        if(c >= '5')
            c = 9 - (c-'0')+'0';
    }
    long long o = stoll(x);
    if(o == 0){
        cout << '9';
        for(int i = 0; i < x.size()-1; i++){
            cout << '0';
        }
        cout << endl;
    }
    else{
        if(x[0] == '0'){
            x[0] = '9';
        }
        cout << x << endl;
    }

}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
