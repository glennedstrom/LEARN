#include <bits/stdc++.h>
using namespace std;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

void solve() {
    int n,queries; cin >> n>>queries;
    vector<long long> nums(n); for(int i = 0; i < n; i++){cin >> nums[i];}

    vector<long long> psum(n); for(int i = 0; i < n; i++){psum[i] = nums[i] + (i != 0 ? psum[i-1] : 0);}
    // psum[n-1] - ( range sum ) + (k % 2 == 1 && (r-l+1) % 2 == 1) // if both odd then add the odd to it.

    while(queries--){
        long long l,r,k; cin >> l >> r >> k;
        //do queries
        l--;r--;

        //NEEDS long long FOR FINAL NUM
        long long out = psum[n-1] - (psum[r] - (l > 0 ? psum[l-1] : 0)) + (k*(r-l+1));
        if(out % 2 == 1)YES
        else NO
    }
}

int main() { int testcase; cin >> testcase; while(testcase--){ solve(); } }// {solve();}
