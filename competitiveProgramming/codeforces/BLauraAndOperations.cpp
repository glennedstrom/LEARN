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
    int ones,twos,threes; cin >> ones >> twos >> threes;
    vector<pair<int,int>> nums = {{ones, 1}, {twos, 2}, {threes, 3}};
    // sort(ordered.begin(), ordered.end());

    //most is at the right, if the difference between the first and the last is... brute forceable

    if(ones == twos && twos == threes){ cout << 1 << " "; cout << 1 << " "; cout << 1 << endl; return; }

    // shrink last two and build the first
    int a = ones;
    int b = twos;
    int c = threes;
    while(b > 0 && c > 0){
        a++;
        b--;
        c--;
    }
    int low2 = max(b,c);
    if(low2 % 2 == 0){
        //it can make a win
        cout << 1 << ' ';
    }
    else{
        // it can't make a win
        cout << 0 << ' ';
    }
    a = twos;
    b = ones;
    c = threes;
    while(b > 0 && c > 0){
        a++;
        b--;
        c--;
    }
    low2 = max(b,c);
    if(low2 % 2 == 0){
        //it can make a win
        cout << 1 << ' ';
    }
    else{
        // it can't make a win
        cout << 0 << ' ';
    }
    a = threes;
    b = twos;
    c = ones;
    while(b > 0 && c > 0){
        a++;
        b--;
        c--;
    }
    low2 = max(b,c);
    if(low2 % 2 == 0){
        //it can make a win
        cout << 1 << ' ';
    }
    else{
        // it can't make a win
        cout << 0 << ' ';
    }
    cout << endl;
    
}

int main(){int t;cin>>t;while(t--){solve();}ios_base::sync_with_stdio(false);cin.tie(NULL);}//{solve();ios_base::sync_with_stdio(false);cin.tie(NULL);}
