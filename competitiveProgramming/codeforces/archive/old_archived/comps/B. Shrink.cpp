#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testcases; cin >> testcases;

    for(int testcase = 0; testcase < testcases; testcase++){
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int i = 0; i < n; i++){ // check for odd and even cases of n
            if(i % 2 == 0){
                nums[i/2] = i;
            }
            else{
                nums[n-1-i/2] = i;
            }
        }

        for(auto& num : nums){
            cout << num + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}
