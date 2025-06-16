#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // find the lowest true value
    int binary_search_answer(int left, int right, function<bool(int)> canSolve) {
        int result = -1;

        while(right >= left){
            int mid = (right-left)/2+left;
            if(canSolve(mid)){
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

    auto canSolve = [&](int num){return num > 6;};

    int ans = s.binary_search_answer(0, 6, canSolve);
    cout << "Value: " << (ans != -1 ? to_string(ans) : "Not found") << endl;
    return 0;
}
