#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    int n; cin >> n;

    vector<int> lucky;
    for(int i = 1; i <= 1000; i++){
        string s = to_string(i);
        bool luck = true;
        for(int j = 0; j < s.size(); j++){
            if( !(s[j] == '4' || s[j] == '7') ){ luck = false; break; }
        }
        if(luck){ lucky.push_back(i); }
    }

    bool almost_lucky = false;
    for(int i = 0; i < lucky.size(); i++){
        if(n % lucky[i] == 0){
            almost_lucky = true;
            break;
        }
    }

    cout << (almost_lucky ? "YES" : "NO") << endl;
}
