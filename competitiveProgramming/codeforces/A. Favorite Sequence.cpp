#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long testcases; cin >> testcases;

    for(int testcase = 0; testcase < testcases; testcase++){
        int n; cin >> n;

        deque<int> dq;
        int temp;
        for(int i = 0; i < n; i++){cin >> temp;dq.push_back(temp);}

        while(!dq.empty()){
            cout << dq.front() << " ";
            dq.pop_front();

            if(dq.empty())break;
            cout << dq.back() << " ";
            dq.pop_back();
        }
        cout << endl;
    }

    return 0;
}
