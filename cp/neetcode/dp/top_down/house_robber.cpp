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
    // skip 1 or 2 houses every time; i + 2 || i + 3
    unordered_map<int,int> memo;
    int rec(vector<int>& nums, int i) {
        if(i >= nums.size()){return 0;} //base case past the end
        if(i >= nums.size() - 2){return nums[i];} // base case: rob the final house
        if(memo.find(i) != memo.end()){return memo[i];}

        memo[i] = nums[i] + max(rec(nums, i+2), rec(nums, i+3));
        return memo[i];
    }
    int rob(vector<int>& nums) {
        return max(rec(nums, 0), rec(nums, 1));
    }
};
int main()
{
    Solution s;
    vector<int> houses = {2,2,3,12,2,3,23,2,9,23,7,0,8,3,7,4,3};
    int ans = s.rob(houses);
    cout << "Answer: " << ans << endl;
    return 0;
}

