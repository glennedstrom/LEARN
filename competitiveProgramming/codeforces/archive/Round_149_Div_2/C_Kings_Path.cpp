#include <cstdint>
#include <queue>
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
* URL:     https://codeforces.com/contest/242/problem/C
* Date:    Sat Oct  4 00:21:48 2025
* Contest: Codeforces Round 149 (Div. 2):
* Problem: C. King's Path
* Limits:  2000ms, 256MB
*/

void precalc(){
    // optional
}

struct Node{
    int row,left,right;

    //Node(int row,int left,int right):row(row),left(left),right(right){ }

    // lexiographic order; is that incorrect?; VALID FOR MERGING SEGMENTS; what else?
    //bool operator<(const Node& o) const{
    //    return tie(row,left,right) < tie(o.row,o.left,o.right);
    //}
    friend ostream& operator<<(std::ostream& os, const Node& a){
        os << a.row << ":[" << a.left << ',' << a.right << ']';
        return os;
    }
    bool operator==(const Node& b)const{
        return tie(row,left,right) == tie(b.row,b.left,b.right);
    }
    bool operator==(const pair<int,int> b)const{
        return tie(b.first,b.second) >= tie(row,left) && tie(b.first,b.second) <= tie(row,right);
    }
};
struct NodeComp{
    using is_transparent = void;
    // INFO: This is for:
    // 1. sorting the tree
    // 2&3. binary searching in the tree for a value

    // lexiographic order; is that incorrect?; VALID FOR MERGING SEGMENTS; what else?
    bool operator()(const Node& a, const Node& o) const{
        return tie(a.row,a.left,a.right) < tie(o.row,o.left,o.right);
    }
    
    bool operator()(const Node& a, const pair<int,int>& o) const{ // {row, val} for looking up one value
        return make_pair(a.row,a.right) < o;
    }
    bool operator()(const pair<int,int>& o, const Node& a) const{ // {row, val} for looking up one value
        return o < make_pair(a.row,a.left);
    }
};

// Ignoring rows
Node possible_jumps(const Node& u, const Node& v){
    // range of possible widths to jump to in v including diagonals
    Node inter = {v.row, max(u.left-1,0), min(u.right+1,(int)1e9)};
    // row 1: [1,5]
    // range: [1,6]
    // row 2:     [6,10]
    //
    // intersection: [6]

    inter.left = max(v.left,inter.left);
    inter.right = min(inter.right,v.right);
    if(inter.left > inter.right){
        return {-1,-1,-1};
    }
    //if(inter.right >= v.left && inter.left <= v.right){
    //    inter.left = min(v.left,inter.right);
    //    inter.right = max(inter.left,v.right);
    //    inter.row = v.row;
    //}
    //else{
    //    inter = {-1,-1,-1};
    //}

    return inter;
}

void solve() {
    int x0,y0,x1,y1; cin >> x0 >> y0 >> x1 >> y1;

    //Node u = {1,10,20};
    //Node v1 = {2,15,25};
    //Node v2 = {2,14,16};
    //Node v3 = {2,5,25};
    //Node v4 = {2,22,30};
    //Node v5 = {2,1,8};
    //cout << u << " To " << v1 << possible_jumps(u, v1) << endl;
    //cout << u << " To " << v2 << possible_jumps(u, v2) << endl;
    //cout << u << " To " << v3 << possible_jumps(u, v3) << endl;
    //cout << u << " To " << v4 << possible_jumps(u, v4) << endl;
    //cout << u << " To " << v5 << possible_jumps(u, v5) << endl;

    int n; cin >> n;

    set<Node, NodeComp> legal; 
    //vector<tuple<int,int,int>> legal(n); 
    int r,a,b;
    for(int i = 0; i < n; i++){cin >> r >> a >> b; legal.emplace(r,a,b);}
    //cout << *legal.begin() << endl;
    //ranges::sort(legal);

    // merge intersecting legal segments
    auto cur = legal.begin();
    auto prev = cur++;

    // merge intersecting segment IF row is the same and prev.b > cur.a

    while(cur != legal.end()){
        if(prev->row == cur->row){
            if(prev->right > cur->left){
                // merge two segments
                int glob_left = min(prev->left, cur->left);
                int glob_right = max(prev->right, cur->right);

                auto inserted = legal.insert(prev, Node(cur->row,glob_left,glob_right));
                legal.erase(prev);
                legal.erase(cur);

                // point to the next comparison
                prev = inserted;
                cur = ++inserted; // point to inserted node so the next loop points right after
                continue;
            }
        }
        prev = cur++; // NOTE: This is the proper way to update two neighboring pointers
    }
    // find the row you can move in then 
    //for(auto& node : legal){
    //    cout << node << endl;
    //}


    // 1. I could binary search for the most left and right ends of my current segment
    // 2. Binary search for these exact values in the row above and below.
    // 3. Everything between those two from the previous step you can get to from your current segment. MOVE TO THE EARLIEST POINT IN EITHER SUBSEGMENT?
    // You can only move up if there is a "collision" between segments and they are off by one row
    //
    //
    // can you binary search a value into these ranges?
    // custom comparator?
    //
    // 1. Binary search for a value on the lower end of your range
    // 2. Binary search for a value on the upper end of your range
    // 3. iterate through each matching segment and push the minimum manhattain distatnce end of the segment to the queue
    // 4. (optional) mark current segment as visited? remove the segment? have a boolean visited flag? something
    // MOST LIKELY BOOLEAN FLAG IN THE STRUCT

    // can do this with my current comparators OR range comparators to return the intersection of the binary search range
    // INFO: starting range
    auto manhat = [](pair<int,int> a, pair<int,int> b){
        return abs(a.first-b.first) + abs(a.second-b.second);
    };
    auto start_range = legal.lower_bound(make_pair(x0,y0));

    priority_queue<pair<ll,Node>> pq; // <cheapest dist to node, Node>


    //cout << x0 << " " << y0 << endl;
    //cout << start_range->row << ": " << start_range->left << "," << start_range->right << endl;
    //NOTE: Giving up for now, I want to work on something else
    for(int i = 1; i <= 9; i++){

        auto start_range = legal.lower_bound(make_pair(x0,i));


        cout << x0 << " " << y0 << endl;
        if(*start_range == make_pair(x0,i)){
            cout << start_range->row << ": " << start_range->left << "," << start_range->right << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
    return;



    if(y0 < start_range->left && y0 > start_range->right){ // out of bounds; invalid
        cout << -1 << endl; // NOTE: you will need to search everything between for future q's
        return; // won't actually return -1 here probably, just don't continue this path.
    }
    cout << manhat({x0,y0},{x0,y0}) << endl;
    cout << manhat({x0,y0},{start_range->row,start_range->left}) << " " << manhat({x0,y0},{start_range->row,start_range->right}) << endl;

    // BINARY SEARCH ONE BELOW MIN AND ONE ABOVE MAX BOTH UP AND DOWN
    // ?how do you "push forward" the distance?
    int low = min(start_range->left-1,0);
    int high = max(start_range->right+1,(int)1e9);

    // going down


    int x = x0;
    auto up = legal.lower_bound({x0,y0});
    if(legal.begin() != up){
        up--; // good
    }
    else{
        // nothing lower, can't go up
    }
    auto down = legal.upper_bound({x,INT32_MAX,INT32_MAX});
    if(down != legal.end()){
        //good

    }
    else{
        //nothing higher
    }
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);precalc();solve();}


// 1. merge intersecting segments
// 2. binary search for the column?

//0X11111110
//0000111110
//1111100000
//Y000000000
//0000000000
//0000000000
//0000000000
//
//0X12345670
//0000456780
//9876500000
//Y000000000
//0000000000
//0000000000
//0000000000
//
//
// abs(l-r+1)
