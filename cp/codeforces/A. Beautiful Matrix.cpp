#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> nums(5, vector<int>(5));

    int x, y;
    for(int i = 0; i < nums.size(); i++){ for(int j = 0; j < nums[i].size(); j++){ cin >> nums[i][j]; if(nums[i][j] == 1){ x = i; y = j; } } }

    cout << abs(x-2) + abs(y-2) << endl;
}
