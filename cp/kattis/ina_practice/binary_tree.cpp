#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int data, Node* l, Node* r){
        val = data;
        left = l; 
        right = r;
    }
};

void bfs(Node* n){
    queue<Node*> q;

    q.push(n);
    while(!q.empty()){
        Node* cur = q.front();
        q.pop();

        if(cur->left)
            q.push(cur->left);
        if(cur->right)
            q.push(cur->right);
        cout << cur->val << endl;
    }
}

void print_node(Node* n){
    if (n == nullptr){ return; }

    cout << n->val << endl;
    print_node(n->left);
    print_node(n->right);
}

Node* invert_tree(Node* n){
    if (n == nullptr){ return n; }

    Node* temp = invert_tree(n->left);
    n->left = invert_tree(n->right);
    n->right = temp;
    return n;
}


int main(){
    Node a = Node(7, nullptr, nullptr);
    Node b = Node(6, nullptr, nullptr);
    Node c = Node(5, &b, &a);
    Node d = Node(4, &c, nullptr);
    Node e = Node(3, nullptr, nullptr);
    Node f = Node(2, &d, nullptr);
    Node g = Node(1, &f, &e);

    //Node a = Node(1, &b, &c);
    //Node c = Node(3, nullptr, nullptr);
    //Node a = Node(1, &b, &c);
    //
    bfs(&g);
    cout << endl;

    print_node(&g);
    invert_tree(&g);
    cout << endl;
    print_node(&g);

    return 0;
    /*
    vector<int> nums = {2,5,1,6,7,3};

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++){
        cout << nums[i] << endl;
    }

    for(int i : nums){
        cout << i << endl;
    }

    vector<pair<int,int>> pairs = {{1,2}, {8,3}, {9,2}};
    vector<tuple<int,int,int>> tup = {{1,2,3}, {8,3,3}, {9,2,3}};

    for(auto& [a,b] : pairs){
        cout << "(" << a << "," << b << ")" << endl;
    }

    for (int i = 0; i < pairs.size(); i++){
        cout << pairs[i].first  << "," << pairs[i].second << endl;
    }

    for(auto& [a, b, c] : tup){
        cout << "(" << a << "," << b << ")" << endl;
    }

    for (int i = 0; i < tup.size(); i++){
        cout << get<0>(tup[i])  << get<1>(tup[i])  << get<2>(tup[i])  << endl;
    }
    */
}
