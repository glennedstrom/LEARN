#include <bits/stdc++.h>
using namespace std;

int main()
{
    int mins;
    int penalty = 20;
    vector<bool> correct(8);
    vector<int> time_if_correct(8);
    
    while (cin >> mins && mins != -1){
        //other stuff
        char problem;
        string stemp;
        cin >> problem >> stemp;
        bool correctness = stemp == "right";


        if(!correct[problem - 'A']){ // solidify correct ones
            if(correctness){
                correct[problem - 'A'] = true;
                time_if_correct[problem - 'A'] += mins;
            }
            else{
                //penalty
                time_if_correct[problem - 'A'] += penalty;
            }
        }

    }
    int tc = 0, tt = 0;
    for(int i = 0; i < 8; i++){
        if(correct[i]){
            tc += correct[i];
            tt += time_if_correct[i];
        }
    }
    cout << tc << " " << tt << endl;
}
