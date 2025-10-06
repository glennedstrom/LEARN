#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a,b,c; cin >> a >> b >> c;
    long long length, width;

    length = a / c + (a % c == 0 ? 0 : 1);
    width = b / c + (b % c == 0 ? 0 : 1);

    cout << length * width << endl;
}
