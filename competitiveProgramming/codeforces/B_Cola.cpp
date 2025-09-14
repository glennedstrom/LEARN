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
    int n,a,b,c;cin >> n >> a >> b >> c;
    // first try the minimum, then try the maximum, then figure out how many in-between based on how many go into the next one

    int remaining = n;
    int buyc = min(remaining/2,c); // how many c's I can buy
    remaining -= 2*buyc;
    cout << remaining << ", " << buyc << endl;

    int buyb = min(remaining,b);
    remaining -= buyb;
    cout << remaining << ", " << buyb << endl;

    int buya = min(remaining*2,a);
    remaining -= buya/2;
    cout << remaining << ", " << buya << endl;
    if(buyc*2 + buyb + buya/2 < n){ // or remaining == 0
        cout << "IMPOSSIBLE" << endl;
    }

    int remc =c-buyc, remb =b-buyb, rema =a-buya;

    // option 1: convert remaining b's to a's
    // option 2: convert remaining c's to a's
    // you need to loop over them multiple times. once you do all b's to a's, restart with one less c and pushed over.
    //
    // Simple case: only bought c's so try to distribute them downwards
    //
    // Middle case: Bought only C's and B's. Push B's to A's, then repeat after resetting with one C pushed to B and so on
    
    // if in bounds, start with a count of 1 and count every iteration on how many you push from one to the next, breaking if it's full.
    // C outer loop pushes to B, B's loop pushes to A and A fills up.
    //
    // All of them starting from 0 pushed looping up to their buyc amount to say you pushed everything you bought to the next one.
    int cnt = 0;
    // for(int i = 0; i <= buyc; i++){ // try to push from C
    //     for(int j = i*2; j <= buyb; j++){ // start from i*2 because that's how fast this one fills up when the previous loses one, push these one by one to the next
    //         for(int k = j*2; k <= buya; k++){
    //             cnt += 1;
    //         }
    //     }
    // }
    //
    // Let's say we have 5 buyc's to make ten
    // count = 1
    // now we have 4 c's and 2 b's
    // count = 2
    // now we have 4 c's and 1 b's and 2 a's
    // count = 3
    // 4c,0b,4a
    // count = 4
    // now we maxed out on a's and ran out of b's. 
    // 3c,4b,0a
    // count = 5
    // 3c,3b,2a
    // count = 6
    // 3c,2b,4a
    // count = 7
    // (make sure you don't skip the last options because we can't start from the beginning of the loop)
    // 2c,4b,4a
    // count = 8
    for(int i = buyc; i >= 0; i--){ // try to push from C
        for(int j = buyb - i*2; j >= 0; j--){ // start from i*2 because that's how fast this one fills up when the previous loses one, push these one by one to the next
            for(int k = buya - j*2; k >= 0; k--){
                cnt += 1;
            }
        }
    }
    cout << "COUNT: " << cnt << endl;
    cout << remaining << " : " << buyc << ", " << buyb << ", " << buya << endl;

}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
