#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void precalc(){
    // optional
}

void solve() {
    string sa,sb;
    cin >> sa >> sb;
    for(int i = 0; i < sa.size(); i++){
        cout << (int(sa[i]) ^ int(sb[i]));
    }
    cout << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);precalc();solve();}
