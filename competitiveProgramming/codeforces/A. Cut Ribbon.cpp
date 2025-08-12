#include <bits/stdc++.h>
using namespace std;
// try to do bottom up
int main()
{
    vector<int> cut(3);
    int n; cin >> n >> cut[0] >> cut[1] >> cut[2];
    sort(cut.begin(), cut.end());

    queue<int> q;
    q.push(0);
    vector<int> tab(n+1,  -1);
    tab[0] = 0;
    for(int j = 1; j < n+1; j++){ // 
        for(int i = 0; i < 3; i++){ // cut size loop // if this is on the outside, you can exit early when found if sorted (true)
            if(j - cut[i] >= 0 && tab[j - cut[i]] != -1){
                //in bounds
                tab[j] = max(tab[j], 1+tab[j - cut[i]]); // most count
                //cout << j << ": " << tab[j] << endl;
            }
        }
    }

    //for(int i = 0; i < n+1; i++){
    //    cout << tab[i] << endl;
    //}
    cout << tab[n] << endl;
}
