#include <bits/stdc++.h>
using namespace std;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

void solve() {
    vector<int> medians(3);
    vector<int> tempNums(3);
    cin >> tempNums[0]>> tempNums[1]>> tempNums[2];
    sort(tempNums.begin(),tempNums.end());
    medians[0] = tempNums[1];

    cin >> tempNums[0]>> tempNums[1]>> tempNums[2];
    sort(tempNums.begin(),tempNums.end());
    medians[1] = tempNums[1];

    cin >> tempNums[0]>> tempNums[1]>> tempNums[2];
    sort(tempNums.begin(),tempNums.end());
    medians[2] = tempNums[1];

    sort(medians.begin(), medians.end());
    cout << medians[1] << endl;
}

int main(){solve();}


// 6 4 5 : 5
// 7 9 8 : 8
// 1 2 3 : 2
// 
// 2 8 5 : 5

