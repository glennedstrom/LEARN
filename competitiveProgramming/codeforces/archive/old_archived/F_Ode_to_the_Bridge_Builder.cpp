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

const double EPS = 1e-9;

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
    friend vec operator-(const vec& lhs, const vec& rhs){
        return {lhs.x - rhs.x, lhs.y - rhs.y};
    };
};

double dist(point p1, point p2) {
  return hypot(p1.x-p2.x, p1.y-p2.y);
}

point rotate(point p, double theta) {
  double rad = DEG_to_RAD(theta);
  return point(p.x*cos(rad) - p.y*sin(rad),
               p.x*sin(rad) + p.y*cos(rad));
}

vec toVec(const point &a, const point &b) {
  return vec(b.x-a.x, b.y-a.y);
}

vec scale(const vec &v, double s) {
  return vec(v.x*s, v.y*s);
}

point translate(const point &p, const vec &v) {
  return point(p.x+v.x, p.y+v.y);
}

double dot(vec a, vec b) { return (a.x*b.x + a.y*b.y); }

double cross(vec a, vec b) { return a.x*b.y - a.y*b.x; }

double norm_sq(vec v) { return v.x*v.x + v.y*v.y; }

double perimeter(double ab, double bc, double ca) {
  return ab + bc + ca;
}

double area(double ab, double bc, double ca) {
  double s = 0.5 * perimeter(ab, bc, ca);
  return sqrt(s) * sqrt(s-ab) * sqrt(s-bc) * sqrt(s-ca);
}

double rInCircle(double ab, double bc, double ca) {
  return area(ab, bc, ca) / (0.5 * perimeter(ab, bc, ca));
}

double rCircumCircle(double ab, double bc, double ca) {
  return ab * bc * ca / (4.0 * area(ab, bc, ca));
}

int circumCircle(point p1, point p2, point p3, point &ctr, double &r){
  double a = p2.x - p1.x, b = p2.y - p1.y;
  double c = p3.x - p1.x, d = p3.y - p1.y;
  double e = a * (p1.x + p2.x) + b * (p1.y + p2.y);
  double f = c * (p1.x + p3.x) + d * (p1.y + p3.y);
  double g = 2.0 * (a * (p3.y - p2.y) - b * (p3.x - p2.x));
  if (fabs(g) < EPS) return 0;

  ctr.x = (d*e - b*f) / g;
  ctr.y = (a*f - c*e) / g;
  r = dist(p1, ctr);
  return 1;
}

bool canFormTriangle(double a, double b, double c) {
  return (a+b > c) && (a+c > b) && (b+c > a);
}

point moveVert(point start, point other, double height){
    // dist must be between 0.5 and 1
    double angle = height/1;
    point o = {start.x + cos(angle), start.y + height};



    //either intersection of two circles or right triangle or binary search your angle or something
    return o;
}
double f(vec min, vec at){
    return pow(pow(min.x-at.x,2)+pow(min.y-at.y,2),0.5);
}

double h(double d){
    pow(1-(d/2*d/2),0.5);
}

point point_towards(point a, point b, point target){
    // try to get as close as you can to target
    // create a vector pointed towards our target then rotate until b can reach it.
    vec at = vec(target.x-a.x, target.y - a.y);
    //binary search an angle that is in bounds of b if out of bounds
    vec min = vec(b.x - a.x, b.y - a.y);
    // if this can't form a triangle, binary search between them
    int val = f(min,at);
    if(val >= 0.5 && val <= 1){
        return target;
    }

    // intersection between the two circles

    double r0=1;
    double r1=1;
    double d;

    double x2 = (a.x + b.x)/2;
    double y2 = (a.y + b.y)/2;

    double hh = h(d);
    point ia = {h(d)*(b.y-a.y)/d, -h(d)*(b.x-a.x)/d};
    point ib = {-h(d)*(b.y-a.y)/d, h(d)*(b.x-a.x)/d};

    if(dist(ia,target) < dist(ib,target)){
        return ia;
    }
    return ib;
}

void solve() {
    double p,q,m; cin >> p >> q >> m;

    point dest = point({p,q});
    // p&q are x
    point a = {0,0};
    point b = {1,0};
    
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);int t;cin>>t;while(t--){solve();}}//{ios_base::sync_with_stdio(false);cin.tie(NULL);solve();}
