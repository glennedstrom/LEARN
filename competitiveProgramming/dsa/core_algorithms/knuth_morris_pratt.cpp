#include <bits/stdc++.h>
using namespace std;

int main(){
    // string s =  "bababababcababcabab";
    // string key = "ababcabab";
                   //001201234

    string s;
    string key;
    cin >> s >> key;

    vector<int> jump(key.size());

    int len = 0;

    for(int i = 1; i < key.size(); i++){
        while(len > 0 && key[i] != key[len]){ // jump backwards to check through the key to see how far we are in the string so far
            len = jump[len-1];
        }
        // found one longer in the sequence
        len += key[len] == key[i];
        jump[i] = len;//jump[len] + 1;
    }

    // for(int i = 0; i < key.size(); i++){
    //     cout << jump[i] << ' ';
    // }
    // cout << endl;
    // for(int i = 0; i < key.size(); i++){
    //     cout << key[i] << ' ';
    // }
    // cout << endl;

    int i=0,j=0;
    int cnt = 0;

    while(i < s.size()){
        if(s[i] == key[j]){
            ++i;
            ++j;
        }
        else if(j != 0){ //wrong answer, jump back
            j = jump[j-1];
        }
        else{
            i++; // move forward because we have nothing.
        }
        //if hit the end, count and jump back
        if(j == key.size()){
            cnt++;
            j = jump[j-1];
        }
    }

    cout << cnt << endl;
}
