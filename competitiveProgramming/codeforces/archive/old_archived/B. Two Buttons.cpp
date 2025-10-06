#include <bits/stdc++.h>
using namespace std;

//dijkstra moving

int main(){
    int n,m; cin >> n >> m;

    //priority_queue<pair<int,int>,
    //     std::vector<std::pair<int,int>>,
    //     std::greater<std::pair<int,int>>
    //> pq; // button_presses, value; do fewest first
    stack<int> s;
    s.push(n);
    unordered_map<int,int> best;
    int depth = 1;

    while(!s.empty()){
        //auto& [b_press, val] = q.top();
        int val = s.top();
        int b_press = best[val];
        s.pop();
        depth--;
        //cout << val << ", " << b_press << endl;
        if(val == m){cout << b_press << endl; break;}

        if(best.find(val-1) == best.end()){
            best[val-1] = b_press+1; // no do edges instead
            s.push(val-1);
            depth++;
        }
        if(val > m){continue;} // skip *2 if you are too high
        if(best.find(val*2) == best.end()){
            best[val*2] = b_press+1; // no do edges instead
            s.push(val*2);
            depth++;
        }

    }

}


// if I can prove the problem is only -1 -1 -1 -1 *2 *2 *2 order then it'll be a simpler problem because then your options are either
//
//
// 5 -> 4 -> 8 -> 7 -> 14
//
// if you can get to 14 faster or equal the normal way it is good.
// 5 -> 4 ->
// 5 -> 10 -> 
//
// no work...
//
//
//
// NEXT THEORY:
//
// only go down until it's divisible by the number then up?
// NO
//
// if -1 *2 -1 -1 ... is slow, then is this always faster? -1 -1 *2 than any future ones like -1 -1 *2?
// 8 -> 
// 7 14 13 12 11 10
// 8 7 6 12


































































































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
