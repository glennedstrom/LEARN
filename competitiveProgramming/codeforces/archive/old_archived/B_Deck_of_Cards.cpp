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

    string cmds; cin >> cmds;
    vector<char> s(n,'+');


    int l = 0;
    int r = n-1;
    int q = 0;
    for(int i = 0; i < k; i++){
        if(cmds[i] == '0'){ 
            s[l] = '-';
            l++; 
        }
        if(cmds[i] == '1'){ 
            s[r] = '-';
            r--; 
        }
        if(cmds[i] == '2'){ 
            q++; 
        }
    }

    if(q == r-l+1){
        // all -
        for(int i = 0; i < q && l <= r; i++){
            s[l] = '-';
            s[r] = '-';

            l++;r--;
        }
    }
    else{
        for(int i = 0; i < q && l <= r; i++){
            s[l] = '?';
            s[r] = '?';

            l++;r--;
        }

    }



    for(int i = 0; i < n; i++){
        cout << s[i];
    }
    cout << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
