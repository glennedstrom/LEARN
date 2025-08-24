#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s; cin >> s;

    string o;

    for(int i = 0; i < s.size(); i++){
        char c = s[i];
        if(c <= 'Z'){c += 'a' - 'A';}
        if(c == 'a' ||c == 'e' ||c == 'i' ||c == 'o' ||c == 'u' || c == 'y')continue;
        o.push_back('.');
        o.push_back(c);
    }
    cout << o << endl;
}
