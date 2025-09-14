#include <bits/stdc++.h>
using namespace std;
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl

void solve() {
    int n; cin >> n;
    if(n == 1){ cout << "yes\n" << 1 << ' ' << 1 << endl; return;}
    vector<int> nums(n); for(auto& i : nums)cin >> i;


    int l=0,r=0;
    for(int i = 1; i < n; i++){
        if(nums[i] < nums[i-1] ){
            l = i-1;
            while(i < n && nums[i] < nums[i-1]){
                i++;
            }
            r = i-1;
            break;
        }
    }
    sort(nums.begin() + l, nums.begin() + r + 1);
    bool yes = true;
    for(int i = 1; i < n; i++){
        if(nums[i] <= nums[i-1]){
            yes = false;break;
        }
    }
    yes ? cout << "yes\n" << l + 1 << ' ' << r + 1 << endl : cout << "no" << endl;
    //cout << l + 1 << ' ' << r + 1 << endl;
}

int main(){solve();}
