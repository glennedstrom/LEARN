#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    int total = 0;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        total+=temp;
    }
    cout << total << endl;
}
