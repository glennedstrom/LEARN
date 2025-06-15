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
    unordered_map<int,int> memo;

    int climbStairs(int n) {
        if(n <= 2){ return n; } // base case
        if(memo[n]){ return memo[n]; } // memo

        //take one or two steps
        memo[n] = climbStairs(n - 1) + climbStairs(n - 2);
        return memo[n];
    }
};
int main()
{
    Solution s;
    int ans = s.climbStairs(7);
    cout << "Answer: " << ans << endl;
    return 0;
}
/*
*
* Don't double count
*
* 1 1  (1)
* 2 2  (1,1, 2)
* 3 3: (1,1,1; 2,1;  1,2)
* 4 5: (1,1,1,1; 2,1,1;  1,2,1; 1,1,2; 2,2)
* 5 8: (1,1,1,1,1; 2,1,1,1;  1,2,1,1; 1,1,2,1; 1,1,1,2; 2,2,1; 2,1,2; 1,2,2)
* 6 13
* 7 21
* 8 34
*
*/
