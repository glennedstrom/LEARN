#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <cmath>
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

double DEG_to_RAD(double d) { return d*M_PI/180.0; }
double RAD_to_DEG(double r) { return r*180.0/M_PI; }

struct point_i {
  int x, y;
  point_i() { x = y = 0; }
  point_i(int _x, int _y) : x(_x), y(_y) {}
};

struct point {
  double x, y;
  point() { x = y = 0.0; }
  point(double _x, double _y) : x(_x), y(_y) {}
  bool operator < (point other) const {
    if (fabs(x-other.x) > EPS)
      return x < other.x;
    return y < other.y;
  }
  bool operator == (point other) const {
    return (fabs(x-other.x) < EPS && (fabs(y-other.y) < EPS));
  }
};

struct line { double a, b, c; };

struct vec { double x, y;
  vec(double _x, double _y) : x(_x), y(_y) {}
};

void solve() {
    point_i p;
    int n; cin >> n;
    string s; cin >> s;

    for(int i = 0; i < n; i++){
        switch (s[i]) {
            case 'U':
            p.y++;
            break;
            case 'D':
            p.y--;
            break;
            case 'L':
            p.x--;
            break;
            case 'R':
            p.x++;
            break;
        
        }
        if(p.x == 1 && p.y == 1){
            YES;
            return;
        }
    }
    NO;
}

int main(){int t;cin>>t;while(t--){solve();}ios_base::sync_with_stdio(false);cin.tie(NULL);}//{solve();ios_base::sync_with_stdio(false);cin.tie(NULL);}
