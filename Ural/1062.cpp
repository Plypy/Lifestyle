/**
 * Description: Transform the problem into finding 2-dims feasible region.
 * Each inequation corresponds to a half-plane, so we only have to do one time half-plane intersection will be fun
 * Note that there is not only n-1 half-planes, the boundary condition is also important
 * Source: Ural 1062
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

const double eps = 1e-10;
int dblcmp(double x) {
    if (fabs(x) < eps)
        return 0;
    return x>0?1:-1;
}
typedef struct Point {
    Point() {}
    Point(double x, double y): x(x), y(y) { }
    friend ostream &operator<<(ostream &os, const Point &pt) {
        os << pt.x << ' ' << pt.y;
        return os;
    }
    double x, y;
} Vector;
Vector operator+(const Vector &a, const Vector &b) {
    return Vector(a.x+b.x,a.y+b.y);
}
Vector operator-(const Vector &a, const Vector &b) {
    return Vector(a.x-b.x,a.y-b.y);
}
Vector operator*(double d, const Vector &v) {
    return Vector(d*v.x,d*v.y);
}

double cross(const Vector &a, const Vector &b) {
    return a.x*b.y-a.y*b.x;
}
double area2(const Point &l, const Point &r, const Point &p) {
    return cross(r-l, p-l);
}
double angle(const Vector &v) {
    return atan2(v.y,v.x);
}
struct Line {
    Point l, r;
    double ang;
    Line() {}
    Line(const Point &l, const Point &r): l(l), r(r) {
        ang = angle(r-l);
    }
    void make(double,double,double);
    bool operator<(const Line &t) const {
        return ang<t.ang;
    }
};
Point getIntersection(const Line &l, const Line &m) {
    Vector u = l.r-l.l, v = m.r-m.l, w = l.l-m.l;
    double t = cross(v, w)/cross(u, v);
    return l.l+t*u;
}
bool onLeft(const Line &l, const Point &p) {
    return dblcmp(area2(l.l,l.r,p)) > 0;
}
const int MAXN = 105;
Line lque[MAXN];
Point pque[MAXN];
bool halfPlaneIntersection(Line *pl, int n) {
    sort(pl,pl+n);
    // for (int i = 0; i < n; ++i) {
        // cout << pl[i].l << " and " << pl[i].ang << endl;
    // }
    int first, last;
    lque[first=last=0] = pl[0];
    for (int i = 1; i < n; ++i) {
        while (first<last && !onLeft(pl[i], pque[last-1]))
            --last;
        while (first<last && !onLeft(pl[i], pque[first]))
            ++first;
        lque[++last] = pl[i];
        if (0 == dblcmp(lque[last].ang-lque[last-1].ang)) {
            --last;
            if (onLeft(lque[last], pl[i].l))
                lque[last] = pl[i];
        }
        // cout << "counting " << first << ' ' << last << endl;
        if (first < last)
            pque[last-1] = getIntersection(lque[last-1], lque[last]);
    }
    while (first<last && !onLeft(lque[first], pque[last-1])) {
        // cout << pque[last-1] << endl;
        --last;
    }
    // cout << first << ' ' << last << endl;
    return (last-first) > 1;
}
void Line::make(double a, double b, double c) {
    Vector v(b,-a);
    if (abs(b) > abs(a)) {
        l = Point(0,-c/b);
    } else {
        l = Point(-(c/a),0);
    }
    r = l+v;
    ang = atan2(-a,b);
}

int n;
int u[MAXN], v[MAXN], w[MAXN];
Line plane[MAXN];
void test() {
    plane[0] = Line(Point(0,0),Point(1,0));
    plane[1] = Line(Point(1,0),Point(0,1));
    cout << getIntersection(plane[0], plane[1]) << endl;
}
int main() {
    // test();
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", u+i, v+i, w+i);
    }
    for (int i = 0; i < n; ++i) {
        int ct = 0;
        double len = 10000.0;
        bool flag = true;
        for (int j = 0; j < n; ++j) {
            if (i == j)
                continue;
            if (u[i] <= u[j] && v[i] <= v[j] && w[i] <= w[j]) {
                flag = false;
                break;
            }
            if (u[i] > u[j] && v[i] > v[j] && w[i] > w[j])
                continue;
            double a = (len/u[j]-len/w[j])-(len/u[i]-len/w[i]);
            double b = (len/v[j]-len/w[j])-(len/v[i]-len/w[i]);
            double c = len/w[j]-len/w[i];
            plane[ct++].make(a,b,c);
        }
        plane[ct++] = Line(Point(0,0),Point(1,0));
        plane[ct++] = Line(Point(0,0),Point(0,-1));
        plane[ct++] = Line(Point(1,0),Point(0,1));
        if (flag && halfPlaneIntersection(plane, ct))
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}