#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void precalc(){
    // optional
}

void solve() {
    int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;

    if(x1 == x2){ // y's are the magnitude
        int mag = abs(y2-y1);
        cout << x1+mag << " " << y1 << " " << x2 + mag << " " << y2 << endl;
    }
    else if(y1 == y2){ // x's are the magnitude
        int mag = abs(x2-x1);
        cout << x1 << " " << y1 + mag << " " << x2 << " " << y2 + mag << endl;
    }
    else if(abs(x2-x1) == abs(y2-y1)){ // none of them are the same, just make the square easy
        cout << x1 << " " << y2 << " " << x2 << " " << y1 << endl;
    }
    else{
        cout << -1 << endl;
    }
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);precalc();solve();}
