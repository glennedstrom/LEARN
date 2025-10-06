#include <cstdint>
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
    string s; cin >> s;

    // min(shift 2nd to the left, shift all to the right)

    int firstA = -1;
    int firstB = -1;
    int lastA = -1;
    int lastB = -1;
    for(int i = n-1; i >= 0; i--){
        if(lastA == -1 && s[i] == 'a'){ lastA = i; }
        if(lastB == -1 && s[i] == 'b'){ lastB = i; }
    }
    for(int i = 0; i < n; i++){
        if(firstA == -1 && s[i] == 'a'){ firstA = i; }
        if(firstB == -1 && s[i] == 'b'){ firstB = i; }
    }
    if(lastA == -1 || lastB == -1){ cout << 0 << endl; return; }


    // for moving a's to the left
    vector<int> b_outwards(n, INT32_MAX);
    vector<int> a_outwards(n, INT32_MAX);
    int countal = 0;
    int countar = 0;
    int countbl = 0;
    int countbr = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'a'){ countal++; }
        else{ // for each a, it needs to move by count(b) or cur
            b_outwards[i] = min(b_outwards[i], countal);
        }

        if(s[n-1-i] == 'a'){ countar++; }
        else{ // for each a, it needs to move by count(b) or cur
            b_outwards[n-1-i] = min(b_outwards[n-1-i], countar);
        }

        if(s[i] == 'b'){ countbl++; }
        else{ // for each a, it needs to move by count(b) or cur
            a_outwards[i] = min(a_outwards[i], countbl);
        }

        if(s[n-1-i] == 'b'){ countbr++; }
        else{ // for each a, it needs to move by count(b) or cur
            a_outwards[n-1-i] = min(a_outwards[n-1-i], countbr);
        }
    }

    ll tot1 = 0;
    ll tot2 = 0;
    for(int i = 0; i < n; i++){
        if(b_outwards[i] != INT32_MAX)
            tot1 += b_outwards[i];
        if(a_outwards[i] != INT32_MAX)
            tot2 += a_outwards[i];
    }
    cout << min(tot1,tot2) << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
