#include <bits/stdc++.h>
//#include <bits/extc++.h>
using namespace std;

class Solution {
public:
    vector<int> memo;
    bool cansum_topdown(int target, vector<int>& nums) {
        if(target <= 0)return target == 0;
        if(memo[target] != -1){return memo[target];}
        for(int i = 0; i < nums.size(); i++){
            memo[target] = cansum_topdown(target - nums[i], nums);
            if(memo[target]){
                return true;
            }
        }
        return false;
    }
    bool cansum_bottomup(int target, vector<int>& nums) {
        vector<bool> cs(target+1);
        cs[0] = true;
        // build from here

        queue<int> q;
        q.push(0);

        while(!q.empty()){
            int cur = q.front();
            q.pop();

            //visit neighbors
            for(int i = 0; i < nums.size(); i++){
                int neigh = cur + nums[i];
                if(neigh == target){
                    return true; // early return
                }
                else if(neigh < target && !cs[neigh]){ // visit and push; all visitable are true
                    q.push(neigh);
                    cs[neigh] = true;
                }
            }
        }

        return cs[target];
    }
};

int main()
{
    cout << boolalpha;
    Solution s;
    for(int target = 0; target <= 1000; target++){
        vector<int> nums = {1,5,10,25,100,500,1000}; // divide by 100 to get coins
        s.memo = vector<int>(target+1, -1);

        bool ans1 = s.cansum_topdown(target, nums);
        bool ans2 = s.cansum_bottomup(target, nums);
        if(ans1 != ans2){
            cout << "Incorrect Case: " << target << endl;
            cout << "Answer: " << ans1 << "!=" << ans2 << endl;
        }
    }
    return 0;
}
