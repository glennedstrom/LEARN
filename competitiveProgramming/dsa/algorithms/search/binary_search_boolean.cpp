#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // find the lowest true value
    int binary_search_bool(vector<bool>& vals) {
        int left = 0; int right = vals.size()-1;
        int result = -1;

        while(right >= left){
            int mid = (right-left)/2+left;
            if(vals[mid]){ 
                result = mid;  // found answer
                right = mid - 1; // keep searching up/down depending on what you want
            }
            else{
                left = mid+1;
            }
        }
        return result;
    }

};
int main()
{
    Solution s;
    vector<bool> nums = {false, true, true, true, true};

    int ans = s.binary_search_bool(nums);
    cout << "Index: " << (ans != -1 ? to_string(ans) : "Not found") << endl;
    return 0;
}
