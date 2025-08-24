#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,t; cin >> n >> t;

    vector<int> nums(n); for(int i = 1; i < nums.size(); i++){cin >> nums[i];}

    //start at cell 1 and move forward
    int cur = 1;

    bool yes = false;

    while(true){
        if(cur == t){
            yes = true;
            break;
        }
        if(cur == n){ // can't move past the end
            break;
        }

        cur = cur + nums[cur];
    }

    cout << (yes ? "YES" : "NO") << endl;
}
