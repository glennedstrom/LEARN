#include <bits/stdc++.h>
#include <cstdint>
using namespace std;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

void solve() {
    int n,k; cin >> n >> k;


    int evenCount = 0;
    int minDist = INT32_MAX;
    for(int i = 0; i < n; i++){ // if it is 4, you need two even prime factors. either divisible by 4 or two numbers divisible by 2.
        int num; cin >> num;
        evenCount += num % 2 == 0;
        minDist = min(((-num) % (k)+k)%k, minDist); // c++ version of -n mod k
    }
    // cout << minDist << endl;
    if(k == 4 && minDist == 3){
        minDist = 2; // furthest distance away case, must add 1 to two different numbers
    }
    else if(k == 4 && minDist == 2 && evenCount == 1){
        minDist = 1; // only has one number 2
    }
    if(k == 4 && evenCount >= 2){ minDist = 0; }
    cout << minDist << endl;
    //vector<int> nums(n); for(int i = 0; i < n; i++)cin >> nums[i];

}

int main(){ int testcase; cin >> testcase; while(testcase--){ solve(); } }//{solve();}
