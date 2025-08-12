#include <bits/stdc++.h>
//#include <bits/extc++.h>
using namespace std;



int fibonacci(int n, vector<int>& memo) {
    if(n == 0 || n == 1) return n;
    if(memo[n] != -1){return memo[n];}

    memo[n] = fibonacci(n-1, memo) + fibonacci(n-2, memo);
    return memo[n];
}

// 0 1 1 2 3 5 8 13


// O(2^n)

int main()
{
    int n = 30;
    vector<int> memo(n+2, -1);
    cout << INT32_MAX << endl;
    cout << memo.size() << endl;
    int ans = fibonacci(n, memo);
    cout << "Answer: " << ans << endl;
    return 0;
}
