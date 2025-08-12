#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long testcases; cin >> testcases;

    for(long long testcase = 0; testcase < testcases; testcase++){
        long long n; cin >> n;

        long long total = 0;
        vector<long long> nums(n);
        for(long long i = 0; i < n; i++){ cin >> nums[i]; }

        bool neg = nums[0] < 0;
        bool negprev = neg; //!neg;
        long long cmax = nums[0];
        for(long long i = 0; i < n; i++){
            neg = nums[i] < 0;
            if(neg != negprev){
                total += cmax;
                //cout << cmax << " ";
                cmax = nums[i];
            }
            cmax = max(cmax, nums[i]);
            negprev = neg;
        }
        total += cmax;

        cout << total << endl;


    }

    return 0;
}
