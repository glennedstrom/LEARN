#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void precalc(){

}

void solve() {
    vector<int> count('Z'+1);

    string a,b; cin >> a >> b;
    for(int i = 0; i < a.size(); i++){
        count[a[i]]++;
    }
    for(int i = 0; i < b.size(); i++){
        count[b[i]]--;
    }
    // ISSUE: order of deletion matters. You need to be able to make up the solution still in some way (subsequence of characters makes your word)
    // NOT Just count
    //
    // NOTE:
    // You could achieve this by going from the back and making sure you have enough letters to make the full word maybe?
    //
    // NOTE: This is just edit distance except delete distance variation. Just count how many deletions? Or maybe use the deletions here to track if it goes to the end still?
    // 

    int tot = 0;
    int del;
    while(cin >> del){
        if(count[a[del-1]] == 0){
            break; // might cause their thing to crash?
        }
        cout << "deleting " << a[del-1] << endl;
        count[a[del-1]]--;
        tot++;
    }
    cout << tot << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);precalc();solve();}
