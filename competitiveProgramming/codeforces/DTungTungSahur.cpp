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
    string hits,heard; cin >> hits >> heard;
    cout << hits << " " << heard << endl;

    int next = 1;
    int jstart = 0;
    for(int i = 0; i < hits.size(); i = next){
        //make sure that for n hits on the left side in a row, we get between n and 2*n hits on the right side
        int j = i;
        int count1 = 0;
        while(j < hits.size() && hits[i] == hits[j]){
            count1++;
            j++;
            cout << hits[j] << ' ';
        }
        next = j;
        j = jstart;
        int count2 = 0;
        cout << " : ";
        while(j < heard.size() && heard[jstart] == heard[j]){
            count2++;
            j++;
            cout << heard[j] << ' ';
        }
        cout << endl;
        jstart = j; // our next for this second loop
        if(count2 >= count1 && count2 <= count1*2){
            //valid
        }
        else{ NO; return; }
    }

    YES;
}

int main(){int t;cin>>t;while(t--){solve();}ios_base::sync_with_stdio(false);cin.tie(NULL);}//{solve();ios_base::sync_with_stdio(false);cin.tie(NULL);}
