#include <bits/stdc++.h>
using namespace std;

bool is_triangle(int x, int y, int z){
    return x+y > z && x+z > y && z + y > x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long testcases; cin >> testcases;

    for(int testcase = 0; testcase < testcases; testcase++){
        int x; cin >> x;

        int output = -1;
        for(int y = 1; y < x; y++){
            int z = x ^ y;
            //cout << x << " " << y << " " << z << endl;
            //cout << bitset<30>(x) << '\n' <<  bitset<30>(y) << '\n' <<  bitset<30>(z) << endl << endl;
            if(is_triangle(x,y,z)){
                output = y;
                break;
            }
        }
        cout << output << endl;
    }

    return 0;
}
