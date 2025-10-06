#include <bits/stdc++.h>
#include <cstdint>
using namespace std;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

void solve() {
    int n,k; cin >> n >> k;

    vector<int> nums(n); for(int i = 0; i < n; i++){ cin >> nums[i]; }

    //keep a running total for k. add and remove one as you move through the array. if you go to the end then quit.

    int sum=0, sumCount=0;
    int best=INT32_MAX, besti=-1;

    int j = 0;
    for(int j = 0; j < k; j++){ sum += nums[j]; }
    for(int i = 0; i < n; i++){

        //code
        if(sum < best){
            besti = i;
            best = sum;
        }

        if(i+k >= n)break;
        sum += nums[i+k];
        sum -= nums[i]; // pop off the current number when you move forwards
    }
    cout << besti+1 << endl;
}

int main(){solve();}
