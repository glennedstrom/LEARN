#include <bits/stdc++.h>
using namespace std;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

void solve() {
    int m,s; cin >> m >> s;

    if(m == 1 && s == 0){cout << "0 0" << endl; return;} // corner case

    string str;
    int s2 = s; // sum of digits remaining
    int m2 = m; // length of current string
    while(s2 - 9 >= 0 && m2--){ str+='9';s2-=9;}               // push back biggest digit
    if(s2 > 0 && s2 <= 8){str.push_back(s2 + '0');s2 = 0;m2--;}                  // push back final digit to make the sum even

    string str2(str.rbegin(),str.rend());
    for(int i = str.size(); i < m; i++) if(m2 != m) { str.push_back('0'); str2[0]--; str2.insert(str2.begin(), '1');m2--; }       // else fill in with zeros if there is at least one non-zero digit
    if(m2 != 0 || s2 > 0){ cout << "-1 -1" << endl; } // if impossible
    else cout << str2 << " " << str << endl;

}

// NOTE: only the lower number is failing because it must be 2 digits and it can't be 08
// EX: 2 digit, sum(digit) == 8:  17, 80
//
// current algorithm calculates you 08. All you have to do is subtract 1 from the largest number and shift it over as far as you need to build it
//
// FIXED

int main(){solve();}
