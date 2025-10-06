#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
#define YES 
#define NO 
// EPS for doubles; do 1e-6 for floats
#define EPS 1e-9
#define INF 1e9

void solve() {
    
    int a,b,c; cin >> a >> b >> c;
    vector<int> nums = {a,b,c};

    vector<char> ops = {'+', '*'};

    //a,b,c with both combos of + and *
    //a,c,b with both combos of + and *

    // both *,* and both +,+



    // a*c handled separately?
    int top = 0;

    for(int op = 0; op < 4; op++){
        // op & 2 is first op, op & 1 is second op
        int tot = 0;
        if(op & 2){
            
            tot = a*b;
        }
        else{
            
            tot = a + b;
        }
        if(op & 1){
            
            tot *= c;
        }
        else{
            
            tot += c;
        }
        top = max(tot,top);
    }
    reverse(nums.begin(),nums.end());
    a = nums[0]; b = nums[1]; c = nums[2];
    for(int op = 0; op < 4; op++){
        // op & 2 is first op, op & 1 is second op
        int tot = 0;
        if(op & 2){
            
            tot = a*b;
        }
        else{
            
            tot = a + b;
        }
        if(op & 1){
            
            tot *= c;
        }
        else{
            
            tot += c;
        }
        top = max(tot,top);
    }

    cout << top << endl;
}

int main(){solve();ios_base::sync_with_stdio(false);cin.tie(NULL);}
