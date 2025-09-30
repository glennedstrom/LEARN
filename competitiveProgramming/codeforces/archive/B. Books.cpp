#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; int t; cin >> n >> t;

    vector<int> bookt(n); for(int i = 0; i < n; i++){cin >> bookt[i];}

    //sliding window method
    int l = 0;

    int cur_sum = 0;
    int largest_range = 0;
    int best = 0;


    for(int r = 0; r < n; r++){ 
        cur_sum += bookt[r];

        while(cur_sum > t && r >= l){
            cur_sum -= bookt[l];
            l++;
        }

        best = max(r-l+1, best);
    }

    cout << best << endl;
}
