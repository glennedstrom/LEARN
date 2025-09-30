#include <bits/stdc++.h>
using namespace std;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

vector<int> fib;

void solve() {
    fib.push_back(0); fib.push_back(1);

    int n; cin >> n;
    for(int i = 2; i <= n; i++){ fib.push_back(fib[i-1] + fib[i-2]); }
    
    int tot = 0;
    for(int i = 0; i <=n; i++){ tot+=fib[i]; }
    cout << tot << endl;
}

int main(){solve();}
