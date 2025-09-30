#include <bits/stdc++.h>
using namespace std;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

void solve() {
    int n,t; cin >> n >> t;
    if(n == 1 && t == 10) {cout << -1 << endl;return;}


    cout << t;
    for(int i = 0; i < n-1-(t==10); i++){
        cout << 0;
    }
}

int main(){solve();}
