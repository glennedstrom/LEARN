#include <bits/stdc++.h>
using namespace std;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

vector<int>pfs;

void solve() {
    int n; cin >> n;
    //brute force first, if not, binary search for the initial value?
    //no just start from the bottom dumbass...

    for(auto& num : pfs){
        //if(x*num > n)break;

        if(n % num == 0){
            cout << n / num << endl;
            return;
        }
    }

    // if x*pfs == n
    // n/pfs == x
}

int main(){ 
    int prev = 1;
    for(int i = 1; i < 30; i++){
        pfs.push_back((1 << i) + prev);
        prev = pfs[pfs.size()-1];
        //cout << prev << ' ';
    }
    //cout << endl;
    int testcase; cin >> testcase; while(testcase--){ solve(); } 
}//{solve();}


// prefix sum of the binary numbers, then find a number brute force? exponential numbers makes less numbers to check


// x + 2x is the minimum
// x(111111111)
// binary sequence
//
//  1 2 4 8 16 32 64 128 256
//    3 7 8 16 32 64 128 256
//    6 12 24
//    10 20 40
// 
// x == 2 just shifts it.
