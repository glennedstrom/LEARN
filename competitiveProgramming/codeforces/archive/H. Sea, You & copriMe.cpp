#include <bits/stdc++.h>
using namespace std;

int euclids(int a, int b){ // test me before using
    while(b != 0){
        tie(a,b) = make_tuple(b, a%b);
    }
    return a;
}

int main()
{
    int testcases; cin >> testcases;

    for(int testcase = 0; testcase < testcases; testcase++){
        int n,m; cin >>  n >>  m;

        vector<int> nums(n);
        for(int i = 0; i<n;++i){cin >> nums[i];}
        vector<int> snums(nums.begin(),nums.end()); sort(snums.begin(),snums.end());
        int p=-1,q=-1,r=-1,s=-1;

        // figure out the indexes of the coprimes
        //
        //2 parts? sort then find the coprimes, then search the original array to find the indexes of the coprimes
        vector<int> qv;
        // cout << "FIRST HALF: " << endl;
        for(int i = 0; i<n; ++i){
            for(int j = i+1; j < n; ++j){
                // make a list of all j values then remove i if valid
                if(euclids(snums[i], snums[j]) == 1){
                    p = i;
                    qv.push_back(j);
                    // cout << i << " " << j << endl;
                }
            }
            if(p != -1){break;}
        }
        // in this second half, you need to move forward the index if it isn't valid or find multiple
        if(qv.size() == 0){cout << "0" << endl;continue;}
        // cout << "SECOND HALF: " << endl;
        vector<int> sv;
        for(int i = p+1; i<n; ++i){
            if(qv.size() == 1 && qv[0] == i)continue; // skip first problem's pair
            for(int j = i+1; j < n; ++j){ // make a list of all j values then remove i if valid
                if(qv.size() == 1 && qv[0] == j)continue; // skip first problem's pair
                if(euclids(snums[i], snums[j]) == 1){
                    r = i;
                    sv.push_back(j);
                    // cout << i << " " << j << endl;
                }
            }
            if(p != -1){break;}
        }
        if(qv.size() == 0){cout << "0" << endl;continue;}

        // test if it works before the index conversion
        //
        // cout << "snums: ";
        // for(int i = 0; i < snums.size(); ++i){
        //     cout << snums[i] << " ";
        // }
        // cout << endl;


        if(p == -1 || r == -1){cout << "0" << endl;continue;}
        // SEGFAULT HERE ON TEST CASE 2
        for(auto& val : qv){
            //cout << "QV: " << val << endl;
            auto val2 = find(sv.begin(), sv.end(), val);
            //cout << "QV: " << (val2 == sv.end() ? "NOT FOUND" : to_string(*val2)) << endl;
            //cout << 'r' << r << endl;
            if(val != r && (val2 == sv.end() || sv.size() > 1)){ // r needs to be able to change, index in a 2d vector for that one and store everything? or better
                if(val2 == sv.end()){
                    q = val;
                    s = sv[0]; // grab any, val isn't in the second
                }
                else{
                    q = val;
                    s = (val2 - sv.begin() == 0 ? sv[1] : sv[0]); // equal to NOT val index
                }
                //q = val;
                //s = *val2;
                //cout << "Q&S!!!" << q << ' ' << s << endl;
                break;
            }
        }

        // this was indexes in the sorted array. loop through and find the indices in the original array before printing
        // make sure you don't have collisions on these indexes when finding them. modify the values after taking one to an invalid value maybe
        if(q == -1 || s == -1){cout << "0" << endl;continue;}
        p = find(nums.begin(), nums.end(), snums[p]) - nums.begin(); // search nums for the value found in the sorted array
        q = find(nums.begin(), nums.end(), snums[q]) - nums.begin(); // search nums for the value found in the sorted array
        r = find(nums.begin(), nums.end(), snums[r]) - nums.begin(); // search nums for the value found in the sorted array
        s = find(nums.begin(), nums.end(), snums[s]) - nums.begin(); // search nums for the value found in the sorted array

        // if you have an easy divisor then 
        cout << p + 1 << ' ' << q + 1 << ' ' << r + 1 << ' ' << s + 1 << endl; 
        //cout << index + 1 << endl;
    }
}
