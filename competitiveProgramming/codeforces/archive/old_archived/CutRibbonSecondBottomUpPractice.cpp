#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin >> n;
    vector<int> cut(3);
    cin >> cut[0] >> cut[1] >> cut[2];
    sort(cut.begin(), cut.end());

    vector<int> tab(n+1, -1);
    tab[0] = 0;

    for(int i = 1; i < n+1; i++){
        for(int j = 0; j < 3; j++){
            if(i - cut[j] >= 0 && tab[i-cut[j]] != -1){
                tab[i] = max(tab[i], 1+tab[i-cut[j]]);
            }
        }
    }

    cout << tab[n] << endl;

    return 0;
}
