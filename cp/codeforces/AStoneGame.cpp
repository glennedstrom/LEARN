#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long testcases; cin >> testcases;

    for(int testcase = 0; testcase < testcases; testcase++){
        int high = 0, low = 0;
        int n; cin >> n;
        vector<int> nums(n);for(int i = 0; i < n; i++){
            cin >> nums[i];
            if(nums[i] > nums[high]){ high = i; }
            if(nums[i] < nums[low]){ low = i; }
            
        }
        

        int o = min(min( 
            max(high,low)+1,
            n-min(high,low)),
            n-abs(high-low)+1 
        ); // double check each case

        cout << o << endl;

            
            
            
    }

    return 0;
}

