/**
 * Description: ToDo urgent!
 * Source:
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

const double eps = 1e-8;
int dblcmp(double x) {
    if (fabs(x) < eps)
        return 0;
    return x>0?1:-1;
}
double sqr(double x) {
    return x*x;
}
struct Point3 {
    double x, y, z;
    Point3(): x(0), y(0), z(0) {}
    Point3(double a, double b, double c): x(a), y(b), z(c) {}
    Point3 operator+(const Point3 &t) const {
        return Point3(x+t.x,y+t.y,z+t.z);
    }
    Point3 operator-(const Point3 &t) const {
        return Point3(x-t.x,y-t.y,z-t.z);
    }
    Point3 operator*(const double &d) const {
        return Point3(d*x,d*y,d*z);
    }
    friend Point3 operator*(double d, const Point3 &t) {
        return t*d;
    }
    Point3 operator/(const double &d) const {
        return (*this)*(1/d);
    }
    double len() const{
        return sqrt(sqr(x)+sqr(y)+sqr(z));
    }
    Point3 resize(double d) const {
        d /= len();
        return (*this)*d;
    }
    Point3 unit() const {
        return (*this)/len();
    }
    bool same(const Point3 &t) const {
        return dblcmp(x-t.x) == 0 && dblcmp(y-t.y) == 0 && dblcmp(z-t.z) == 0;
    }
    bool read() {
        return 3 == scanf("%lf%lf%lf", &x, &y, &z);
    }
};

double dot(const Point3 &a, const Point3 &b) {
    return a.x*b.x+a.y*b.y+a.z*b.z;
}
Point3 cross(const Point3 &a, const Point3 &b) {
    return Point3(a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x);
}
struct Face {
    Point3 a, b, c;
    Face() {}
    Face(Point3 a, Point3 b, Point3 c): a(a), b(b), c(c) {}
    Point3 norm() const {
        return cross(b-a, c-a);
    }
};
double mix(const Point3 &a, const Point3 &b, const Point3 &c) {
    return dot(a, cross(b,c));
}
double area2(const Point3 &o, const Point3 &a, const Point3 &b) {
    return cross(a-o, b-o).len();
}

double dist(const Point3 &a, const Point3 &b) {
    return (a-b).len();
}
double p2line(const Point3 &l, const Point3 &r, const Point3 &p) {
    return area2(l, r, p)/dist(l,r);
}
Point3 getLineProjection(const Point3 &l, const Point3 &r, const Point3 &p) {
    Point3 v = r-l;
    return l+v*(dot(v,p-l)/dot(v,v));
}
bool onLine(const Point3 &l, const Point3 &r, const Point3 &p) {
    return 0 == dblcmp(area2(l, r, p));
}
bool onSegmentIn(const Point3 &l, const Point3 &r, const Point3 &p) {
    return onLine(l, r, p) && dblcmp((p.x-l.x)*(p.x-r.x)) <= 0
    && dblcmp((p.y-l.y)*(p.y-r.y)) <= 0 && dblcmp((p.z-l.z)*(p.z-r.z)) <= 0;
}
bool onSegmentEx(const Point3 &l, const Point3 &r, const Point3 &p) {
    return onSegmentIn(l, r, p) && !l.same(p) && !r.same(p);
}
Point3 intersect(const Face& f, const Point3 &a, const Point3 &b) {
    Point3 fa = f.norm();
    Point3 v = b-a;
    double t = dot(fa,f.a-a)/ dot(fa,v);
    return a+v*t;
}
Point3 intersect(const Point3 &a, const Point3 &b, const Point3 &c, const Point3 &d) {
    Point3 e = d+cross(a-b, c-d);
    return intersect(Face(c,d,e),a,b);
}
Point3 rotate(const Point3 &l, const Point3 &r, const Point3 &p, double ang) {
    if (onLine(l, r, p))
        return p;
    Point3 ph = getLineProjection(l, r, p);
    Point3 e = (r-l).unit();
    Point3 x = p-ph;
    Point3 y = cross(x,e);
    return ph+x*cos(ang)+y*sin(ang);
}

int main(int argc, char const *argv[]) {
    Point3 O(0,0,0);
    while (true) {
        Point3 a, b;
        if (a.read() && b.read()) {
        } else {
            break;
        }
        double ang;
        scanf("%lf", &ang);
        Point3 ans = rotate(O,b,a,-ang);
        printf("%.3lf %.3lf %.3lf\n", ans.x, ans.y, ans.z);
    }
    return 0;
}