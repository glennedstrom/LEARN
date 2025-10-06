#include <bits/stdc++.h>
using namespace std;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

void solve() {
    int n; cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; ++i){ cin >> nums[i]; }

    int c = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            c += j-i == nums[j] - nums[i];
        }
    }
    cout << c << endl;
}

int main() { int testcase; cin >> testcase; while(testcase--){ solve(); } }// {solve();}
