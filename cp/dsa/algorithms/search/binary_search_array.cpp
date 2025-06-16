#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // if duplicates, return the lowest
    int binary_search_left(vector<int>& nums, int target) {
        int min = 0; int max = nums.size()-1;
        int result = -1;

        while(max >= min){
            int mid = (max-min)/2+min;
            if(nums[mid] == target){ 
                result = mid;  // found answer
                max = mid - 1; // keep searching up/down depending on what you want
            }
            else if(nums[mid] > target){
                max = mid-1;
            }
            else{
                min = mid+1;
            }
        }
        return result;
    }

    // if duplicates, return the highest
    int binary_search_right(vector<int>& nums, int target) {
        int min = 0; int max = nums.size()-1;
        int result = -1;

        while(max >= min){
            int mid = (max-min)/2+min;
            if(nums[mid] == target){ 
                result = mid;  // found answer
                min = mid + 1; // keep searching up/down depending on what you want
            }
            else if(nums[mid] > target){
                max = mid-1;
            }
            else{
                min = mid+1;
            }
        }
        return result;
    }

    //normal binary search; return right after finding
    int binary_search(vector<int>& nums, int target) {
        int min = 0; int max = nums.size()-1;

        while(max >= min){
            int mid = (max-min)/2+min;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) max = mid-1;
            else min = mid+1;
        }
        return -1;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {0,1,2,3,4,4,4,4,4,4,4,4,4,6,8,9,10};

    cout << "binary_search" << endl;
    for(int target = -1; target <= 9; target++){
        int ans = s.binary_search(nums, target);
        cout << "Index: " << ans << endl;
        cout << "Target: " << (ans != -1 ? to_string(nums[ans]) : "Not found") << endl;
    }

    cout << "binary_search_left" << endl;
    for(int target = -1; target <= 9; target++){
        int ans = s.binary_search_left(nums, target);
        cout << "Index: " << ans << endl;
        cout << "Target: " << (ans != -1 ? to_string(nums[ans]) : "Not found") << endl;
    }

    cout << "binary_search_right" << endl;
    for(int target = -1; target <= 9; target++){
        int ans = s.binary_search_right(nums, target);
        cout << "Index: " << ans << endl;
        cout << "Target: " << (ans != -1 ? to_string(nums[ans]) : "Not found") << endl;
    }
    return 0;
}
