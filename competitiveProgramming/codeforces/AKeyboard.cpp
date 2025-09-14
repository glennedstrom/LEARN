#include <bits/stdc++.h>
using namespace std;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

void solve() {
    string keyboard = "qwertyuiop asdfghjkl; zxcvbnm,./";

    char direction;
    cin >> direction;
    int d = direction == 'R' ? 1 : -1;

    string s; cin >> s;

    for(int i = 0; i < s.size(); i++){
        cout << (keyboard[keyboard.find(s[i]) + -d]);
    }
}

int main(){solve();}
