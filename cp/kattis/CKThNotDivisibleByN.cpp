#include <bits/stdc++.h>
using namespace std;

int f(int x, int n){
    return x-(x/n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long testcases; cin >> testcases;

    for(int testcase = 0; testcase < testcases; testcase++){
        int n,k; cin >> n >> k;

        //cout << f(k+k/n, n) << endl;

        int l=1, h=2e9; // theoretically should be high enough for the worst case: n=2 so every other one missing so 2x as high as the max

        while(h >= l){
            int mid = (h-l)/2+l;

            if (f(mid, n) >= k){ // lower bound
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        cout << h+1 << endl;
    }
    // for(int i = 0; i < 100; i++){
    //     cout << i << ": " << f(i, 3) << endl;
    // }

    return 0;
}
