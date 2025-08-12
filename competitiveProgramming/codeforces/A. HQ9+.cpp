#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s; getline(cin, s);

    vector<char> lets = {'H','Q','9'};
    string output = "NO";
    for(int i = 0; i < s.size(); i++){
        if(find(lets.begin(),lets.end(),s[i]) != lets.end()){
            output = "YES";
        }
    }
    cout << output << endl;
}
