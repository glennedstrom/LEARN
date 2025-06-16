#include <bits/stdc++.h>
//#include <bits/extc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0;
        int sell = 0;
        int profit = 0;

        for(int i = 1; i < prices.size(); i++){
            cout << profit << ", ";
            if(prices[i] < prices[sell]){ // price went DOWN
                profit += prices[sell] - prices[buy]; // sell before the drop
                buy = i; // found a cheaper price
                sell = i;
            }
            else if(prices[i] > prices[sell]){ // price went UP
                sell = i; // can sell for more
            }
        }
        cout << endl;

        int final_day = prices[sell] - prices[buy];
        cout << profit << endl;
        cout << final_day << endl;
        return profit + (final_day > 0 ? final_day : 0);
    }
};
int main()
{
    Solution s;
    vector<int> prices = {1,2,3,0,5};
    prices = {5,4,3,2,1,0,5,1,2};

    int ans = s.maxProfit(prices);
    cout << "Answer: " << ans << endl;
    return 0;
}
