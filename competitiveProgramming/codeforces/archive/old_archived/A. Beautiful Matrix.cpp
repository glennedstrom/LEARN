#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> nums(5, vector<int>(5));
    vector<pair<int,int>> vals = {{1,2}, {8,9}};
    vector<tuple<int,int,string>> vals2 = {{1,2,"cat"}, {8,9,"dog"}};

    for(auto [a,b] : vals){
        cout << a << ", " << b << endl;
    }
    for(auto p : vals){
        cout << p.first << ", " << p.second << endl;
    }
    for(auto t : vals2){
        cout << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << endl;
    }
    for(auto [a,b,c] : vals2){
        cout << a << ", " << b << ", " << c << endl;
    }


    int x, y;
    for(int i = 0; i < nums.size(); i++){ 
        for(int j = 0; j < nums[i].size(); j++){ 
            cin >> nums[i][j]; 
            if(nums[i][j] == 1){ 
                x = i; y = j; 
            } 
        } 
    }

    cout << abs(x-2) + abs(y-2) << endl;
}
