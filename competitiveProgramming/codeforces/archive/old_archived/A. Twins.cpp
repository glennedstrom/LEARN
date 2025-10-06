#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    int half = 0;
    vector<int> nums(n); for(int i = 0; i < n; i++){ cin >> nums[i]; half += nums[i];}
    half /= 2;

    sort(nums.rbegin(), nums.rend());

    int ncoins = 0;

    int tot = 0;
    for(int i = 0; i < n; i++){
        if(tot <= half){ // make sure this works for odd and even
            tot+=nums[i];
            ncoins++;
        }
    }

    cout << ncoins << endl;
}
