#include <bits/stdc++.h>
using namespace std;

int main()
{
    string name;
    cin >> name;

    unordered_set<int> chars;
    for(char c : name){ chars.insert(c); }
    cout << (chars.size() % 2 == 0 ? "CHAT WITH HER!" : "IGNORE HIM!") << endl;
}
