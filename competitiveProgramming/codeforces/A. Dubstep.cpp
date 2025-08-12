#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s; cin >> s;

    char wubarr[3] = {'W', 'U', 'B'};
    int WUB = 0;
    int start = 0;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == wubarr[WUB]){
            WUB++;
            assert(WUB <= 3);
            if(WUB == 3){
                // from start to the beginning of WUB
                if(i - WUB + 1 > start){
                    cout << s.substr(start, i-WUB+1-start) << ' ';
                }
                start = i+1;
                WUB = 0;
            }
        }
        else{
            WUB = s[i] == wubarr[0];
        }
    }
    cout << s.substr(start,s.size()-start) << endl; // finish off the last example if incomplete
}
// WUBWUBABCWUB
