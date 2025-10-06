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


struct vec { double x, y;
  vec(double _x, double _y) : x(_x), y(_y) {}
};

double dot(vec a, vec b) { return (a.x*b.x + a.y*b.y); }

struct point_i {
  int x, y;
  point_i() { x = y = 0; }
  point_i(int _x, int _y) : x(_x), y(_y) {}
};

double dist(point_i p1, point_i p2) {
  return hypot(p1.x-p2.x, p1.y-p2.y);
}

void solve() {
    int x, y, k; cin >> x >> y >> k;


    point_i a(0,0);// a(0,0)
    point_i b(0,min(x,y));// b(i,y)

    point_i c(0,0); // c(0,i)
    point_i d(min(x,y),0); // d(x,0)
    for(int i = 0; i < min(x,y); i++){
        if(dist(a,b) >= k && dist(c,d) >= k){
            break;
        }
        // line 1
        b.x++;
        // line 2
        c.y++;

        vec e = vec(b.x-a.x, b.y-a.y);
        vec f = vec(d.x-c.x, d.y-c.y);
        // cout << "DOT PROD: " << endl;
        // cout << dot(e,f) << endl;
        // if(in bounds){
        //     break;
        // }
    }
    cout << a.x << ' ' << a.y << ' ' << b.x << ' ' << b.y << endl;
    cout << c.x << ' ' << c.y << ' ' << d.x << ' ' << d.y << endl;
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
