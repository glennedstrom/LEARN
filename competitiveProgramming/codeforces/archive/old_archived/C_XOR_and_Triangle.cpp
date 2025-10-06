#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void precalc(){
    // optional
}

bool valid(int a, int b, int c){
    vector<int> sides = {a,b,c};
    ranges::sort(sides);
    return sides[0]+sides[1]>sides[2];
}

void solve() {
    int x; cin >> x;
    cout << "X: " << x << endl;

    for(int y = 0; y < x; y++){
        int z = x ^ y;
        if(valid(x,y,z)){
            cout << x << "," << y << "," << z << endl;
            cout << -(-x ^ x) << endl;
            cout << bitset<16>(x) << "," << bitset<16>(y) << "," << bitset<16>(z) << endl;
        }
    }
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;precalc();while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);precalc();solve();}
