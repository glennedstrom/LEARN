#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, k; cin >> n >> k;

    int score, count = 0;
    for(int i = 0; i < k; i++){
        cin >> score;
        if(score <= 0){
            break;
        }
        count++;
    }
    int s;
    while(cin >> s && s == score && score > 0){
        count++;
    }

    cout << count << endl;

    return 0;
}
