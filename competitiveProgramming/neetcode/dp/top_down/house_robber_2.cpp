#include <bits/stdc++.h>
using namespace std;
#define tc    \
    int t;    \
    cin >> t; \
    while (t--)
#define pb push_back
#define mp make_pair
#define pii pair<ll, ll>

class Solution {
public:
    vector<unordered_map<int,int>> memo; // store one for each start pos

    int rec(vector<int>& nums, int i, int robAt0) {
        if(memo[robAt0].find(i) != memo[robAt0].end()){return memo[robAt0][i];}
        if(i == nums.size()-1 && robAt0){return 0;}
        if(i == nums.size()-1 && !robAt0){return nums[i];}
        if(i == nums.size()-2){return nums[i];} // doesn't matter about loop if 2
        if(i == nums.size()-3 && !robAt0){return nums[i] + nums[i+2];}
        if(i == nums.size()-3 && robAt0){return nums[i];}
        // base cases done

        memo[robAt0][i] = nums[i] + max(rec(nums,i+2,robAt0),rec(nums,i+3,robAt0));
        return memo[robAt0][i];
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1){return nums[0];}
        if(nums.size() == 2){return max(nums[0],nums[1]);}
        memo = vector<unordered_map<int,int>>(2);
        return max(max(rec(nums, 0, 1), rec(nums,1,0)), rec(nums,2,0));
    }
};
int main()
{
    Solution s;
    //vector<int> houses = {3,4,3};
    vector<int> houses = {1,2};
    int ans = s.rob(houses);


    cout << "Answer: " << ans << endl;
    return 0;
}
