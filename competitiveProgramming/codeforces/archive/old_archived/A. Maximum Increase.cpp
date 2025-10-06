#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin >> n;
    int best = 0;
    int total = 0;

    int prev = INT32_MIN;
    int cur;
    for(int i = 0; i < n; i++){
        cin >> cur;
        if(cur > prev){ total++; } // update total
        else{total = 1;prev=INT32_MIN;}
        if(best < total){ best = total; } // update best


        prev = cur; // update prev at end
    }
    cout << best << endl;
}
