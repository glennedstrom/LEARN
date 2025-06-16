#include <bits/stdc++.h>
//#include <bits/extc++.h>
using namespace std;

class Solution {
public:

    static float f(float a){ // f(a) = a^3; binary search to inverse bs(a^3) = a; works for any nth root
        return a*a*a;
    }

    float binary_search_float(function<float(float)> f, float target, float epsilon) {
        float low = 0;
        float high = INT32_MAX;
        float mid, fmid;

        while(high - low > epsilon){
            mid = (high-low)/2+low;
            fmid = f(mid);

            if(abs(fmid - target) < epsilon){
                return mid;
            }
            else if(target < fmid){
                high = mid;
            }
            else{
                low = mid;
            }
        }

        return (high-low)/2+low;
    }
};
int main()
{
    Solution s;
    float ans = s.binary_search_float(Solution::f, 8, 1e-6);
    cout << "Answer: " << ans << endl;
    return 0;
}
