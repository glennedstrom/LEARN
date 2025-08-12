#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long inputs; cin >> inputs;

    vector<int> nums(inputs);
    for(int i = 0; i < inputs; i++){
        cin >> nums[i];
    }

    sort(nums.begin(),nums.end());

    int cc = 0; // consecutive counter

    for(int i = 0; i < inputs-1; i++){
        if(nums[i+1]-nums[i] == 1){ cc++; }
        else if(cc >= 2){
            cout << nums[i-cc] << "-" << nums[i] << ' ';
            cc = 0;
        }
        else{ 
            for(int j = i - cc; j <= i; j++){
                cout << nums[j] << ' '; 
            }
            cc = 0;
        }
    }
    if(cc >= 2){
        cout << nums[nums.size()-1-cc] << "-" << nums[nums.size()-1] << ' ';
        cc = 0;
    }
    else{
        for(int j = nums.size()-1 - cc; j <= nums.size()-1; j++){
            cout << nums[j] << ' '; 
        }
    }

    return 0;
}
