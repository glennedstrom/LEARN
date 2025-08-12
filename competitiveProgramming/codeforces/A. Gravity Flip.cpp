#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;

    vector<int> nums(n); 
    unordered_map<int,int> count;
    for(int i = 0; i < n; i++){cin >> nums[i];count[nums[i]]++;}

    auto cmp = [](const pair<int,int>& a, const pair<int,int>& b){return a.second > b.second;};

    vector<pair<int,int>> ordered;
    for(auto& [k,v] : count){
        ordered.push_back(make_pair(k,v));
    }
    sort(ordered.begin(),ordered.end());

    for(int i = 0; i < ordered.size(); i++){
        for(int j = 0; j < ordered[i].second; j++){
            cout << ordered[i].first << ' ';
        }
    }
}
