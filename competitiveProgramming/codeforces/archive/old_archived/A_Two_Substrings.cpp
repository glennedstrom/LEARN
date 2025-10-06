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
    string s; cin >> s;

    // two passes: look for ab then ba
    // look for ba then ab
    // if either is true, output yes

    int flag = 0;
    for(int i = 1; i < s.size(); i++){
        if(!flag && s[i-1] == 'A' && s[i] == 'B'){
            flag = 1;
            i++;
        }
        else if(flag && s[i-1] == 'B' && s[i] == 'A'){
            flag = 2;
            break;
        }
    }
    if(flag == 2){
        cout << "YES" << endl;
        return;
    }
    flag = 0;
    for(int i = 1; i < s.size(); i++){
        if(!flag && s[i-1] == 'B' && s[i] == 'A'){
            flag = 1;
            i++;
        }
        else if(flag && s[i-1] == 'A' && s[i] == 'B'){
            flag = 2;
            break;
        }
    }
    if(flag == 2){
        cout << "YES" << endl;
        return;
    }
    else{
        cout << "NO" << endl;
    }
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
