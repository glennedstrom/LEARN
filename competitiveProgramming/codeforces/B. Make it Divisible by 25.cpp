#include <bits/stdc++.h>
using namespace std;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

void solve() {
    string n; cin >> n;

    // first look for 5 or 0. if found, look for the correct second digit.
    int ops = 0;
    bool n5 = false;
    int n0 = false;

    reverse(n.begin(),n.end());

    for(auto& d : n){
        int digit = d - '0';

        if(digit == 5)n5 = true;
        if(digit == 0)n0++;

        //solutions:
        if(n0 == 2)break; // 00 case
        if(digit == 5 && n0)break; // 50 case
        if(digit == 2 && n5)break;
        if(digit == 7 && n5)break; // 25 && 75 cases

        ops++; // subtract the digit
    }
    cout << ops-1 << endl; // minus one because we read in a 5 or a 0 as the first digit
}

int main(){ int testcase; cin >> testcase; while(testcase--){ solve(); } }//{solve();}
