#include <bits/stdc++.h>
#include <string>
using namespace std;


int main()
{
    long long testcases; cin >> testcases;

    for(int testcase = 0; testcase < testcases; testcase++){
        int n; cin >> n;

        string sn = to_string(n);

        // output counter
        int o1 = 0;
        int o2 = 0;

        string out1;
        string out2;
        for(int i = 0; i < sn.size(); i++){
            int mid = (sn[i] - '0')/2;
            int remainder = (sn[i] - '0') % 2;

            if(o1 > o2){
                o1 += mid;
                o2 += mid + remainder;
                out1 += mid + '0';
                out2 += mid + remainder + '0';
            }
            else{
                o1 += mid + remainder;
                o2 += mid;
                out1 += mid + remainder + '0';
                out2 += mid + '0';
            }
        }
        cout << stoi(out1) << ' ' << stoi(out2) << endl;
        // go from here: b increase by

        // cout << "n = " << n << ": ";

        // if you need an odd number, you need to do it until you carry one. If you need an even number, you do it on easy numbers
        // if you have a big number you want to reduce

        //while(b > 0){ // clearly inefficient AF, but i thought it would work until I realzed I had to multiply the time complexity by the testcases
        //    // The real solution is to go digit by digit and do some flippy algorithm probably
        //    // just make sure that you CONVERGE to the solution, not just flipping and hoping
        //    if(abs(sumc(a) - sumc(b)) <= 1)break;
        //    a++; b--;
        //}

        //cout << a << " " << b << endl;
    }

    return 0;
}
// take the two numbers and take the biggest digit from the number with the biggest sum.
// shrink that one until it matches.
//
// make sure you have a convergance case to make sure it lands on your answer... do some examples.




// 11 0
// 10 1
//
//
//15 0
//14 1
//13 2
//12 3
//
//16 0
//15 1
//14 2
//13 3
//12 4
//11 5
//10 6
//9  7
//8 8
//18
//
//
//199 = 100 + 99
//
//large difference. break up the 99?
//
//99 = 45 + 44
//
//one is one more than the other. pair that with the 100
//
//144 + 45 = 199
//
//
//
//
//that was easy, now let's try bigger.
//
//1999 = 1000 + 999
//
//999 = 500 + 499
//499 = 250 + 249
//249 = 125 + 124
//
//does this help? can you re-build the number now or not?
//
//500 + 250 + 125 + 124
//
//500 + 125 = 625
//250 + 124 = 374
//
//
// if it doesn't make a solution, do you just repeat the algorithm? or does it always work? if you have to carry digits, it has to fail.
//

// 8999 = 4500 + 4499
// a = 4500
// b = 4499 = 2250 + 2249 (send one to a)
// 2249 / 2 = 1125 + 1124
// 1124 / 2 = 562 + 562
//
// a = 2250 + 1124 + 562 = 3374 + 562 = 3936 : 
// b = 1125 + 562 =                     1687 : 
//
// I don't think this is 
//
// 4950 = 
//
//
// take the tens place of each, add the digits, then divide by 2 and if it is odd then give the bigger value to the smaller one.
//
// do that for each of the places. Largest possible value is 9+9=18. first unstable number is 19 because that is 10 and 2. This works BARELY.
//
// 8999 = 4500 + 4950
//

