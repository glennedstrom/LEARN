#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long nanroisten; cin >> nanroisten;

    for(int i = 0; i < nanroisten; i++){
        int n;
        cin >> n;

        int first = 0, second = 0;

        
        vector<int> scores(n);

        for(int i = 0; i < n; i++){
            cin >> scores[i];
            if(scores[i] >= first){
                second = first;
                first = scores[i];
            }
            else if(scores[i] > second){ // not first, but  better than second
                second = scores[i];
            }
        }

        for(int i = 0; i < n; i++){
            if(scores[i] == first){
                cout << scores[i] - second << (i != n-1 ? " " : "\n");
            }
            else{
                cout << scores[i] - first << (i != n-1 ? " " : "\n");
            }
        }

    }

    return 0;
}
