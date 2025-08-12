#include <bits/stdc++.h>
using namespace std;

struct pair_hash {
  size_t operator()(const pair<int,int>& p) const {
    return hash<int>{}(p.first) ^ (hash<int>{}(p.second) << 1);
  }
};

int gridTraveler(int m, int n, unordered_map<pair<int,int>,int, pair_hash> &memo){
  if (memo.find(make_pair(m,n)) != memo.end()){
    return memo[make_pair(m,n)];
  }
  if(m == 0 || n == 0){
    return 0;
  }
  if(m == 1 || n == 1){
    return 1;
  }
  memo[make_pair(m,n)] = gridTraveler(m-1,n,memo) + gridTraveler(m,n-1,memo);
  return memo[make_pair(m,n)];
}

int main(){
  unordered_map<pair<int,int>,int, pair_hash> memo = {};
  cout << gridTraveler(1, 1, memo) << endl;
  memo = {};
  cout << gridTraveler(10, 2, memo) << endl;
  memo = {};
  cout << gridTraveler(2, 2, memo) << endl;
  memo = {};
  cout << gridTraveler(3, 2, memo) << endl;
}
