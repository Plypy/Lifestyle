/**
 * Description: Caution, the square's edges are not guaranteed to be parallel with axes
 * Source: Ural 1111
 * Author: Ply_py
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
using namespace std;
const double eps = 1e-14;
const double inf = 1e100;
const double PI = acos(-1);
int dblcmp(double x) {
    if (abs(x) < eps)
        return 0;
    return x>0?1:-1;
}
typedef struct Vector {
    double x, y;
    Vector(double x = 0, double y = 0): x(x), y(y) { }
    friend istream &operator>>(istream &is, Vector &v) {
        is >> v.x >> v.y;
        return is;
    }
    friend ostream &operator<<(ostream &os, const Vector &v) {
        os << v.x << ' ' << v.y;
        return os;
    }
} Point;
Vector operator-(const Vector &a, const Vector &b) {
    return Vector(a.x-b.x,a.y-b.y);
}
Vector operator+(const Vector &a, const Vector &b) {
    return Vector(a.x+b.x,a.y+b.y);
}
Vector operator*(const Vector &a, double d) {
    return Vector(d*a.x,d*a.y);
}
Vector operator*(double d, const Vector &a) {
    return a*d;
}
double dot(const Vector &a, const Vector &b) {
    return a.x*b.x+a.y*b.y;
}
double cross(const Vector &a, const Vector &b) {
    return a.x*b.y-a.y*b.x;
}
double area2(const Point &l, const Point &r, const Point &p) {
    return cross(r-l,p-l);
}
double length(const Vector &v) {
    return sqrt(v.x*v.x+v.y*v.y);
}
Vector rotate(const Vector &a, double rad) {
    return Vector(a.x*cos(rad)-a.y*sin(rad),a.x*sin(rad)+a.y*cos(rad));
}
double p2segment(const Point &l, const Point &r, const Point &p) {
    double len = length(r-l);
    if (dblcmp(len) == 0)
        return length(p-l);
    Vector v1 = r-l, v2 = p-l, v3 = p-r;
    if (dblcmp(dot(v1,v2)) < 0)
        return length(v2);
    if (dblcmp(dot(v1,v3)) > 0)
        return length(v3);
    return abs(cross(v1,v2)/len);
}
struct Square {
    Point a, b;
    double dis;
    int id;
    bool operator<(const Square &t) const {
        if (dblcmp(dis-t.dis) != 0)
            return dis < t.dis;
        return id<t.id;
    }
};
void calDis(Square &s, const Point &p) {
    Point mid = 0.5*(s.a+s.b);
    Vector delta = s.a-mid;
    Point ar[4];
    for (int i =0; i < 4; ++i) {
        ar[i] = mid+delta;
        delta = rotate(delta,PI/2);
    }

    double ret = inf;
    bool in = true;
    for (int i = 0; i < 4; ++i) {
        ret = min(ret,p2segment(ar[i],ar[(i+1)%4],p));
        if (dblcmp(area2(ar[i],ar[(i+1)%4],p)) <= 0)
            in = false;
    }
    if (in)
        s.dis = 0;
    else
        s.dis = ret;
    // for (int i = 0; i < 4; ++i)
    //     cout << ar[i] << ' ';
    // cout << endl << s.dis << endl;
}
const int MAXN = 55;
int n;
Square sq[MAXN];
Point pt;
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> sq[i].a >> sq[i].b;
        sq[i].id = i;
    }
    cin >> pt.x >> pt.y;
    for (int i = 1; i <= n; ++i)
        calDis(sq[i],pt);
    sort(sq+1,sq+n+1);

    cout << sq[1].id;
    for (int i = 2; i <= n; ++i)
        cout << ' ' << sq[i].id;
    cout << endl;
    return 0;
}