#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;

    vector<int> seq(n);
    for(int i = 0; i < n; i++){cin >> seq[i];}
    if(n == 1){cout << 1 << endl; return 0;} // guerentee n>=2

    int best = 1, cur = 1; // start assuming 0th is good, start checking on 1st
    for(int i = 1; i < n; i++){
        if(seq[i] < seq[i-1]){
            //decreasing
            cur = 1;

        }
        else{
            cur++;
            best = max(best,cur);
        }
    }
    cout << best << endl;
}
