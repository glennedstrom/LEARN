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
    int climbStairs(int n) {
        if(n <= 3){return n;}
        //bottom up approach
        vector<int> ways(n);
        ways[ways.size()-1] = 1;
        ways[ways.size()-2] = 2;

        for(auto it = ways.rbegin()+2; it != ways.rend(); it++){
            *it = *(it-1) + *(it-2);
        }
        return ways[0];
    }
};
int main()
{
    Solution s;

    for(int i = 0; i < 10; i++){
        int ans = s.climbStairs(i);
        cout << "Answer " << i << ": " << ans << endl;
    }
    return 0;
}
