#include <utility>
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
// EPS for doubles; do 1e-6 for floats
#define EPS 1e-9
#define INF 1e9

// WARN: THIS IS A SEGMENT TREE PROBLEM. IMPLEMENT YOUR OWN TO PRACTICE
// stick lightnings in front of the biggest one not already doubled. (greedy) Range query for the sum of the damage. This is a fenwick tree problem!!!
// ::
// This is a segment tree problem because you need to be able to insert elements between other elements.
// Fenwick trees only update values, and don't insert values
// ::
// OR WE CAN DO A CUSTOM THING: Keep a running total, but also store non-doubled values in:
// set<vector<int>> (comparator reverse lexiographic starting with n-1 index so you can push_back latest things O(1) time)
// This way, we can choose to double a value at any time by grabbing the highest vector in the set and pushing lightnings back on the ends
//
// NOTE: If we need to do a custom dp change, I'm fucked. If it's greedy, it could work.
// I am just slapping them down, then if I need to do a x2, then put it on the end of one.
// SHOULD WORK FOR ALL CASES AS FAR AS I CAN TELL
// * Do you need to store all of them, or only a pair? If the right one is already doubled, you can only insert on the left one anyways
// Just use a pair: set<pair<int,int>>
// WHAT ABOUT REMOVING IF THEY DON'T EXIST?
// YOU ALSO NEED TO SHIFT VALUES FROM THE DELETED ELEMENTS TO THE LOWEST DOUBLER IF NECESSARY
// Maybe keep pointers to each value to find them easier. Or bare minimum to the vector they are in inside the set
//

void solve() {
    int spells_remaining; cin >> spells_remaining;
    int sp = spells_remaining;

    // sorted linked list?
    // linked list with pointers to the nodes that is sorted?
    list<list<int>> linked;
    map<int, pair<list<list<int>>::iterator,list<int>::iterator>> to_spell; // pointer to the linked-list iterator[s]? to modify it. [outer, inner] iterators
    //
    // NOTE: if I delete something important in this one, I can move it to the current biggest one in constant time because I always have the iterator locations (sorted by power)
    // ONLY THE FIRST ITEM IS THE POWER, maybe make a custom comparator to be accurate
    // WE DON'T NEED THE SMALLER ITERATOR IN THE MAP

    int max_dmg = 0;

    set<int> fire;
    set<int> lightning;
    while(spells_remaining--){
        int type,damage; cin >> type >> damage;

        // ONLY NEEDS THE TRUE VALUE IF YOU ARE ERASING.
        // YOU NEED THE PARENT ITERATOR IF INSERTING THEN GRAB THE CHILD
        //
        // PARENT ITERATOR POINTS TO WHICH LIST YOU WANT
        // CHILD ITERATOR POINTS TO WHICH INT YOU WANT


        if(damage > 0){ // Learn spell
            if(type == 0){ // fire
                //fire.insert(damage);
                // insert a new list
                linked.push_back({damage});
                max_dmg += damage;
                to_spell[damage] = {prev(linked.end()), linked.front().begin()}; // both forward iterators
            }
            else{ // lightning (x2)
                auto big_it = to_spell.rbegin();
                if(big_it != to_spell.rend()){
                    auto parent = big_it->second; // pair of iterators to the most damage spell list we can double
                    max_dmg += parent.first->front(); // x2 multiplier
                    parent.first->front() *= 2; // double next node's damage
                    parent.first->push_front(damage); // insert our node
                    max_dmg += damage; // our damage
                    // NOW ERASE AND UPDATE OUR KEY IN TO_SPELL
                    auto value = big_it->second;
                    to_spell.erase(big_it->first); // erase the old one
                    to_spell[damage] = value; // insert the new one
                    //lightning.insert(damage);
                    // double the first item in a list
                    // then insert at the beginning
                }
                else{
                    // needs to push to a special spot to keep track of the unused lightning nodes so we can use it to double other things.
                }
            }
        }
        else{ // forget spell
            if(type == 0){ // fire
                // Make sure there is no lightnings behind it
                    // If there is, save the lightning and insert it at the front of the best (rightmost in the map) node you can RE-ASSIGN KEY!
                    // Remaining container after erasing the node has a list of whatever was to the right of your node. RE-ASSIGN the key to the new head node.
                fire.erase(-damage);
            }
            else{ // lightning (x2)
                lightning.erase(-damage);
            }
        }

        for(auto& [dmg, pair] : to_spell){}
    }
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
