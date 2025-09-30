#include <bits/stdc++.h>
using namespace std;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

void solve() {
    int n,k; cin >> n >> k;

    //if(k == 1 && n % 2 == 1){ YES; return;}
    if(k % 2 == 1 && n % 2 == 0 && n >= k*k){ // where k*k is the sum of the first k odds
        // all odds above the minimum 
        YES; return;
    }

    //n*(n+1)/2

}

int main(){ int testcase; cin >> testcase; while(testcase--){ solve(); } }//{solve();}
//
// not relevant but I wanna re-learn telescoping series
// SUM OF FIRST N ODD NUMS IS N^2
//
// f = 1 + 2 + 3 + 4 + 5 + 6 + 7...n = sum_1^n(i)
// n + 1 = 
// 2 + 3 + 4 + 5 + 6 + 7 + 8...n
// 2*(n + 1) = 
// 2 + 3 + 4 + 5 + 6 + 7 + 8...n
//
//
// 2f = 2 + 4 + 6 + 8 + 10 + 12 + 14...2n = sum_1^n(i)
//
// f-2f
// 1 3 5 == 9
// 1 3 7 == 11
// 
