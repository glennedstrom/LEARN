#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    string s; cin >> s;

    char cur = s[0];
    int tot = 0;
    string output = "NO";
    for(int i = 0; i < s.size(); i++){
        if(cur == s[i]){
            tot++;
        }
        else{
            tot = 1;
        }
        cur = s[i];

        if(tot >= 7){
            output = "YES";
        }
    }
    cout << output << endl;
}
