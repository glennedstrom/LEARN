#include <bits/stdc++.h>
//#include <bits/extc++.h>
using namespace std;

// How do you remember which walls are visited? // recursively set and unset a visited boolean array? note: you also might want this in your states
//
// memo[E][x][l][r] with expanding l&r but to go from l to r you have to calculate all the way from l to r
//
//
// memo[E][x];


int runThroughWalls(vector<int>wallXValues, vector<int> wallCosts, int E) {

    vector<pair<int,int>> walls(wallXValues.size());

    int i = 0;
    for(auto& [x, cost] : walls){
        x = wallXValues[i];
        cost = wallCosts[i];
        i++;
    }
    sort(walls.begin(), walls.end());
    //walls are sorted now


    //find first value below 0 for l
    int l = 0;
    for(int i = 0; i < walls.size(); i++){
        if(walls[i].first < 0){
            l = i;
        }
    }
    int r;
    if(walls[l].first < 0){ // set r 
        r = l + 1;
    }
    else{ // all positive nums case (always go right: easy)
        r = 0;
        l = -1;
    }

    vector<unordered_map<int,int>> tab(E+1);
    tab[0][0] = 0;
    //build up from 0


    return 0;
}
int main()
{
    vector<int> wallXValues = {-5,2,-3,29,38,2};
    vector<int> wallCosts = {2, 5, 3, 1, 8, 4};
    int E = 38;
    cout << "Answer: " << runThroughWalls(wallXValues, wallCosts, E) << endl;
    return 0;
}
