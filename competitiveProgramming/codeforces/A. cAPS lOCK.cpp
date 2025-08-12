#include <bits/stdc++.h>
using namespace std;

int main()
{

    string s; cin >> s;

    bool caps = true;

    for(int i = 1; i < s.size(); i++){
        if(s[i] >= 'a'){
            caps = false;
        }
    }
    
    if(!caps){
        cout << s << endl;
        return 0;
    }

    //else swap caps
    int diff = 'a' - 'A';
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= 'a'){
            cout << (char)(s[i] - diff);
        }
        else{
            cout << (char)(s[i] + diff);
        }
    }
}
