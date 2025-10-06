#include <ranges>
#include <stdexcept>
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void precalc(){
    // optional
}

int maxk;

template <typename func>
int query(vector<vector<int>>& sparsetable, int l, int r, func f){
    if(l > r) return -1; // too far, break loop and push right further
    int k = 32 - __builtin_clz(r - l + 1) - 1;

    k = 32 - __builtin_clz(r - l + 1) - 1;
    // cout << f(sparsetable[k][l], sparsetable[k][r - (1 << k) + 1]) << ' ';
    return f(sparsetable[k][l], sparsetable[k][r - (1 << k) + 1]);

    // int k = __lg(r-l+1);
    // //int k = 32 - __builtin_clz(r - l + 1) - 1;
    // //cout << sparsetable[k][l] << "," << sparsetable[k][l+(1<<k)] << ": " << f(sparsetable[k][l], sparsetable[k][l+(1<<k)]) << endl;
    // 
    // return f(sparsetable[k][l], sparsetable[k][r-(1<<k)+1]);
}

/*TODO:
*
Sort first by value to group similar values. Sort second by indexes to make similar values in order of indices (grouping the consecutive indices)

Just find the range of consecutive indices of the same value so you can compute how many of the same are in a row because in the case where there are a lot in a row, it only becomes large if that is the only value in that range because if any one is higher or lower, it is invalid. This means we can just count how many consecutive indices with the same value there are then calculate how many in each consecutive range to add them to the total with n*(n+1)/2 where n == r-l+1.

This makes it O(n) because any individual query is O(1) and the only case where there are multiple in a row is ammortized O(1) for each operation (O(seg_len), but moves forwards seg_len)
*
*
*/

void solve() {
    int n; cin >> n;

    maxk = __lg(n)+1;

    // init first row
    vector sta(maxk, vector<int>(n, -1)); for(auto& i : sta[0])cin >> i;
    vector stb(maxk, vector<int>(n, -1)); for(auto& i : stb[0])cin >> i;

    auto fa = [](int a, int b){return max(a,b);};
    auto fb = [](int a, int b){return min(a,b);};


    int k = 0;
    for(k = 1; k < maxk; k++){
        for(int i = 0; i + (1 << k) <= n; i++){
            sta[k][i] = fa(sta[k-1][i], sta[k-1][i+(1<<(k-1))]);
            stb[k][i] = fb(stb[k-1][i], stb[k-1][i+(1<<(k-1))]);
        }
    }
    // NOTE: Methods to solve:
    // 1. Brute force with range queries.
    // 2. sort({v,i}) pairs for both then while(va == vb) find the highest and lowest indices where this condition is true (two pointers)
    // 3. With high & low, len = high-low+1 and len*(len+1)/2 == total, then subtract wrong arrays
    // 4. Find consecutive subarrays and subtract out "bad" clumps based on their clump size and n*(n+1)/2
    // 5. what about cases without any consecutive?
    int tot = 0;

    auto viewa = ranges::views::zip(sta[0], views::iota(0,n));
    vector<pair<int,int>> vpa(viewa.begin(),viewa.end());

    auto viewb = ranges::views::zip(stb[0], views::iota(0,n));
    vector<pair<int,int>> vpb(viewb.begin(),viewb.end());

    ranges::sort(vpa);
    ranges::sort(vpb);

    //stack<pair<int,int>> stacka(vpa.rbegin(),vpa.rend()); // least should be on top of the stack (back end?)
    //stack<pair<int,int>> stackb(vpb.rbegin(),vpb.rend());
    int idxa = 0;
    int idxb = 0;
    for(auto& i : vpa) cout << "(" << i.first << ", " << i.second << ") ";
    cout << endl;
    for(auto& i : vpb) cout << "(" << i.first << ", " << i.second << ") ";
    cout << endl;
    cout << endl;

    while(idxa < n && idxb < n){//!stacka.empty() && !stackb.empty()) // NOTE: I put && because I presume once one is done, it is impossible to "pair" with the other
    //while(indexa < n || indexb < n)
        int val,ial; // val or -1
        int vbl,ibl; // val or -1

        tie(val,ial) = vpa[idxa]; 
        tie(vbl,ibl) = vpb[idxb]; 

        if(val == vbl){ // same value, try to connect them
            // go from the smaller to the larger value
            int start = min(ial,ibl);
            int end = max(ial,ibl);
            unordered_map<int,int> imperfect; // push not exactly equal values here
            // check looping from start to end (inclusive) if it's valid
            auto check = [](){}; // to check if it's in bounds & update
            bool valid = true;
            int max_a = sta[0][start];
            int min_b = sta[0][start];
            for(int i = start; i <= end; i++){
                //max_a = max(sta[0][i],max_a); //query(sta,start,i,fa); //  // alternative lower constant equivalent
                //min_b = min(stb[0][i], min_b); //query(stb,start,i,fb); // 
                max_a = sta[0][i]; //query(sta,start,i,fa); //  // alternative lower constant equivalent
                min_b = stb[0][i]; //query(stb,start,i,fb); // 
                // if query a is equal to the start and query b (nothin changed) continue (this is good); 
                // TODO: modify to have the proper directional range checking on qa and qb
                // check if each is on the stack and pop
                // pop if you find your node on the stack ; push later ; MIGHT BE EASIER IF YOU USE INDEXES, +/- pop/unpop easily; ONLY ONE SHOULD EVER ADVANCE PAST 1 FROM THIS
                if(vpa[idxa].second == i){ idxa++; } // match up the index
                if(vpa[idxb].second == i){ idxb++; } // match up the index
                if(max_a > sta[0][start] || min_b < stb[0][start]){ valid = false; break; }
                else if(max_a < sta[0][start] || min_b > stb[0][start]){ // one is not equal
                    imperfect[start]++; 
                    // both are on the stack?
                }
                else if(max_a == sta[0][start] && min_b == stb[0][start]){ // good, count; should cover all other cases (logically)
                    continue;
                }
                else{
                    assert(false); // should be impossible
                }
            }
            if(valid){
                // subtract out tiny non-equal arrays from the accumulator
                // TODO: Expand in both directions first to get the max size, then compute count after?
                // Push the bounds of start and end here
                // ends are guaranteed valid; see how far out you can push it. If you find another going upwards, good. MAKE SURE TO BOUNDS CHECK BOTH DIRECTIONS
                while(start-1 >= 0 && ){



                    // if valid, increment these and end
                    end++;
                    if(vpa[idxa].second == end){ idxa++; } // match up the index
                    if(vpa[idxb].second == end){ idxb++; } // match up the index
                    if(max_a > sta[0][start] || min_b < stb[0][start]){ valid = false; break; }
                    else if(max_a < sta[0][start] || min_b > stb[0][start]){ // one is not equal
                        imperfect[start]++; 
                        // both are on the stack?
                    }
                    else if(max_a == sta[0][start] && min_b == stb[0][start]){ // good, count; should cover all other cases (logically)
                        continue;
                    }
                    else{
                        assert(false); // should be impossible
                    }

                }





                int acc = end-start+1; acc = acc*(acc+1)/2; // init accumulator to the full range; subtract out excess after
                for(auto& [i,c] : imperfect){
                    acc -= c*(c+1)/2;
                }
                if(ial <= ibl){ // prevent double counting
                    //cout << ial << " " << ibl << endl;
                    cout << start << " " << end << endl;
                    tot += acc;
                }
            }
            else{
                // I don't think you need this below
                // Move the smaller one back if not valid based on original value (the only one that moves)
                // if(val<vbl){
                //     //stacka.pop();
                //     idxa--;
                // }
                // else{
                //     //stackb.pop();
                //     idxb--;
                // }
            }
        }
        else{
            // pop the smaller off when equal
            if(vpa[idxa]<vpb[idxb]){
                idxa++;
            }
            else{
                idxb++;
            }
        }
    }

    cout << tot << endl;
    // for(int l = 0; l < n; l++){
    //     auto& [val,ial] = vpa[l];
    //     auto& [vbl,ibl] = vpb[l];
    //     if(val != vbl){
    //         l++;
    //         continue;
    //     }
    // }



    //     //for(k = 0; k < maxk; k++){ for(int i = 0; i + (1 << k) <= sta[0].size(); i++){ cout << sta[k][i] << ' '; } cout << endl; } cout << endl;
    //     //for(k = 0; k < maxk; k++){ for(int i = 0; i + (1 << k) <= stb[0].size(); i++){ cout << stb[k][i] << ' '; } cout << endl; } cout << endl;
    //     //for(k = 0; k < maxk; k++){ for(int i = 0; i + (1 << k) <= stb[0].size(); i++){ cout << (sta[k][i] == stb[k][i]) << ' '; } cout << endl; } cout << endl;
    //     cout << tot << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);precalc();solve();}
