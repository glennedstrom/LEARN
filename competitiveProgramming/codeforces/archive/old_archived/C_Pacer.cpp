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

// when I save, it jumps to the top to auto tab indent. Don't have jumps like this, it makes it added to your jumplist

void solve() {
    int n,m; cin >> n >> m;

    int side = 0;
    int cnt = 0;
    int minute = 0;




    for (int i = 0; i < n; i++){
        int a,b; cin >> a >> b;

        int elapsed = a-minute;

        if(side != b && elapsed % 2 == 1){
            // run across no remainder
            cnt += 1 + (elapsed-1) / 2*2; // made it across + how many times you can run back and forth (minus one then truncate)
            // cout << "CASE 1" << endl;
        }
        else if(side != b && elapsed % 2 == 0){
            // run across no remainder
            cnt += 1 + (elapsed-1) / 2*2; // made it across + how many times you can run back and forth (minus one then truncate)
            // cout << "CASE 2" << endl;
        }
        else if(side == b && elapsed % 2 == 0){
            // run back and forth
            cnt += elapsed / 2 * 2;
            // cout << "CASE 3" << endl;
        }
        else if(side == b && elapsed % 2 == 1){
            // run back and forth
            cnt += elapsed / 2 * 2;
            // cout << "CASE 4" << endl;
        }

        side = b;
        minute = a;
    }


    cout << cnt + m-minute << endl;
    return;





























    return;
    for (int i = 0; i < n; i++){
        int a,b; cin >> a >> b;
        if(!(a - minute == 1 && side == b)){ // only if the minute changed, you can do stuff

            // just count total time first
            cnt += a-minute;
            //cout << a << ", " << minute << endl;

            // subtract out any impossible cases
            if (side != b && a-minute > 0){ // must switch sides
                cnt -= (a-minute) % 2 == 0;
            }
            // else{
            // }
        }
        minute = a;
        side = b;

    }
    cout << cnt + (m-minute) << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
