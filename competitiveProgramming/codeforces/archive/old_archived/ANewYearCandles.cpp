#include <bits/stdc++.h>
using namespace std;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

void solve() {
    int a,b; cin >> a >> b;

    int count = a;
    while(a/b){
        int mod = a % b;
        a = a / b;
        count += a;
        a += mod;
    }
    cout << count << endl;
}

int main(){solve();}
