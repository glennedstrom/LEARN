#include <bits/stdc++.h>
using namespace std;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

void solve() {
    int n; cin >> n;
    int init_sum = 0;
    vector<int> nums(n+1); for(int i = 1; i <= n; i++){cin >> nums[i];init_sum += nums[i];}

    // prefix sum of the resuult of the flip (x = 1 - x)


    // not pfs anymore, commented out.
    // for(int i = 1; i <= n; i++){
    //     nums[i] = nums[i-1] + (1 - nums[i])*2-1; // add the flipped bit to the pfs
    // }

    // now we need a high and a low value to sum between that is good.
    int best = 0;
    int tot = 0;
    for(int i = 1; i <= n; i++){ // pfs wasn't needed. I can do it anyways.
        tot = max(tot + (1 - nums[i])*2-1, 0);
        best = max(tot,best);
    }
    if(best == 0){
        best = -1;
    }
    cout << best + init_sum << endl;
}

int main(){solve();}
