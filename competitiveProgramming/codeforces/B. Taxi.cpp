#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin >> n;

    vector<int> groups(n); for (int i=0; i<n; ++i){ cin >> groups[i]; }

    sort(groups.rbegin(),groups.rend());

    int taxis = 0;
    int free_seats[4];
    memset(free_seats, 0,sizeof(free_seats));
    for(int i = 0; i < n; i++){
        bool cont = false;
        switch (groups[i]) {
            case 4:
                taxis++;
                break;
            case 3:
                taxis++;
                free_seats[1]++;
                break;
            case 2:
                if(free_seats[2]){
                    free_seats[2]--;
                    break;
                }
                taxis++;
                free_seats[2]++;
                break;
            case 1:
                if(free_seats[3]){
                    free_seats[3]--;
                    free_seats[2]++; // filled one spot
                    break;
                }
                if(free_seats[2]){
                    free_seats[2]--;
                    free_seats[1]++; // filled one spot
                    break;
                }
                if(free_seats[1]){
                    free_seats[1]--;
                    break;
                }
                taxis++;
                free_seats[3]++;
                break;
        
        }
    }
    cout << taxis << endl;
}
/*
int main()
{
    int n;cin >> n;

    vector<int> groups(n); for (int i=0; i<n; ++i){ cin >> groups[i]; }

    sort(groups.rbegin(),groups.rend());

    int taxis = 0;
    int free_seats[4];
    memset(free_seats, 0,sizeof(free_seats));
    for(int i = 0; i < n; i++){
        // put them a free seat in the car
        if(i >= 1 && free_seats[groups[i-1]] > 0){ // previous group has some left; distribute forwards
            //distribute seats one forward
            for(int j = groups[i]; j < 4; j++){
                free_seats[j] += free_seats[groups[i-1]] / (4 - j);
                free_seats[groups[i-1]] -= free_seats[groups[i-1]] / (4 - j); // subtract from the counter
                if(free_seats[groups[i-1]] == 0)break;
            }
        }
        if(free_seats[groups[i]]){ // if there is spare room in a car that fits the entire groups[i]
            free_seats[groups[i]]--; // put in here instead of calling a new taxi
            //if there is a remainder, I should add the remainder taxi room to the end.
            groups[i];
            continue;
        }
        taxis++;
        free_seats[groups[i] % 4]++;
    }
    cout << taxis << endl;
}*/
