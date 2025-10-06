#include <bits/stdc++.h>
using namespace std;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

void solve() {
    int n; cin >> n;
    int lower = n/2020*2020;
    int upper = lower + n/2020;
    if(n >= lower && n <= upper){ YES; }
    else{ NO; }
}

int main() { int testcases; cin >> testcases; for(int testcase = 0; testcase < testcases; testcase++){ solve(); } }// {solve();}
