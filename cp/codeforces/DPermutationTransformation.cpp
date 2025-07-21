#include <bits/stdc++.h>
using namespace std;

int rec(vector<int>& nums, int low, int high, vector<int>& outvec, int depth = 0){
    if(low > high){ return -1; }

    int midi = high;

    for(int i = low; i < high; i++){ // start with high and compare
        midi = nums[midi] > nums[i] ? midi : i;
    }

    outvec[midi] = depth;

    rec(nums, low, midi-1, outvec, depth+1);  // left
    rec(nums, midi+1, high, outvec, depth+1); // right

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long testcases; cin >> testcases;

    for(int testcase = 0; testcase < testcases; testcase++){
        int m; cin >> m; // max number

        vector<int>nums(m+1); // add space to one index this array
        for(int i = 1; i < m+1; i++){cin >> nums[i];} // one index insert

        vector<int> outvec(m+1); // big enough to store all solutions in their correct spots
        rec(nums,1,m, outvec, 0);
        
        for(int i = 1; i < m+1; i++){
            cout << outvec[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
