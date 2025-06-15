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
    int test() {

        vector<int> nums = {1,2,3,4};
        unordered_map<int,int> m;

        int i = 0;
        for(auto& n : nums){
            i++;
            cout << n << endl;
        }

        for(auto& [key,value] : m){
            //
        }

        for(auto& p : m){
            cout << p.first << ", " << p.second << endl;
        }

        pair<string,int> p = make_pair("test", 5);

        cout << p.first << ", " << p.second << endl;

        vector<pair<string,int>> test;

        for(auto& [s,b] : test){
            
        }



    }
};
int main()
{
    Solution s;
    int ans = s.test();
    cout << "Answer: " << ans << endl;
    return 0;
}
