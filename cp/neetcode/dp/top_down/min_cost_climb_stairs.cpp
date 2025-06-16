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

    // USE FIND to check if a key is in it or count OTHERWISE memo[i] CREATES A KEY = 0; 0 cost is a valid cost; don't falsely write
    unordered_map<int,int> memo; // store min cost here

    //recursively call from the left to build it up from the right
    int rec(vector<int>& cost, int i) {
        if(i >= cost.size()-2){return cost[i];} // base case, one step to victory
        if(memo.find(i) != memo.end()){return memo[i];}

        memo[i] = cost[i] + min(rec(cost, i + 1), rec(cost, i + 2));
        return memo[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() < 2){return 0;}
        return min(rec(cost,0), rec(cost,1));
    }
};
int main()
{
    Solution s;
    vector<int> costs = {1,2,1,2,1,1,1};
    int ans = s.minCostClimbingStairs(costs);
    cout << "Answer: " << ans << endl;
    return 0;
}
