#include <bits/stdc++.h>
using namespace std;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

void solve() {
    string s; cin >> s;

    int o = 0;
    int Q = 0;
    int A = 0;

    bool Q_Turn = true;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'A'){ A+= Q; }
        if(s[i] == 'Q'){ 
            Q++; 
            o += A; // how many new QAQs we can now make
        }

    }
    cout << o << endl;
}
// NOTE: the order of the QAQ matters for counting. QAQQ does 2. QAQAQ does 4 (1 + 3)
// QAAQ does 2 (count A's on all future Qs.) QAAQQ does 4: 2 + 2; QAAQQAQ does 4 + 5 ;  QAAQQAQAQ does 9 + (sum of A's between Q's so far from right to left.)
//
// Needs to store some type of counter? each Q you add, you add the sum of how many A's between each Q and the last Q
// maybe it's easy dp?

int main(){solve();}

// NOTE: make sure they are in order
// QAQAQAQ
//   1 
//     3 
//       6


// UNDER THE A COUNT: store how many Qs to the left?
// That's how much each Q counts for
// AND a running total because you have to do PREV_TOTAL + 
//
// Q = 1 (no A to sum)
// A=1 : one Q to the left
// A=2 : one Q to the left
// Q = 2 : T += A (2)
// Q = 4 : T += A (4)
// A=5 : three Q's to the left
// Q = 9 : T += A (5)
