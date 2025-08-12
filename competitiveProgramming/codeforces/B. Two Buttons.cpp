#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m; cin >> n >> m;

    // priority_queue<pair<int,int>,
    //     std::vector<std::pair<int,int>>,
    //     std::greater<std::pair<int,int>>
    // > pq; // button_presses, value; do fewest first
    queue<int> q;
    q.push(n);
    unordered_map<int,int> best;

    while(!q.empty()){
        //auto& [b_press, val] = q.top();
        int val = q.front();
        int b_press = best[val];
        q.pop();
        //cout << val << ", " << b_press << endl;
        if(val == m){cout << b_press << endl; break;}

        if(best.find(val-1) == best.end()){
            best[val-1] = b_press+1; // no do edges instead
            q.push(val-1);
        }
        if(best.find(val*2) == best.end()){
            best[val*2] = b_press+1; // no do edges instead
            q.push(val*2);
        }

    }

}






































































































/*int main()
{
    int n,target; cin >> n >> target;
    if(n > target){
        cout << n - target << endl;
        return 0;
    }

    // *2 and -1 plan:
    //you may want to -1 earlier before *2 because that makes it move at speeds much faster.
    //OR you can just get close then move by powers of 2 between 2^0 and 2^x where x is how many x2 buttons you pressed
    int pressed = 0;
    int x = 0;
    while(n*2 <= target){ // one more to exceed it then subtract backwards?
        n *= 2;
        x++;
        pressed++;
    }

    if(n == target){
        cout << pressed << endl;
        return 0;
    }

    // now you have to increase it by values starting with 2^x going down
    while(x >= 0){
        if(n * pow(x,2) <= target){
            n *= pow(x,2);
            pressed++;
        }
        --x;
    }
    cout << pressed+1 << endl;

}*/
// Decrease by:
// 1 2 4 8 16 32 64 128 256 ...
//
