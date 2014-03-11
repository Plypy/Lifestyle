/**
 * Description:
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

const double eps = 1e-6;
const double pi  = acos(-1.0);
double dblcmp(double x) {
    if (fabs(x) < eps)
        return 0;
    return (x>0?1:-1);
}
struct Point {
    double x, y;
    Point() {}
    Point(double a, double b): x(a), y(b) {}
    Point operator-(const Point &t) const {
        return Point(x-t.x,y-t.y);
    }
};

struct Circle {
    Point m;
    double r;
    Circle(){}
    Circle(const Point &a, const double b): m(a), r(b) {}
};

double dot(const Point &a, const Point &b) {
    return a.x*b.x+a.y*b.y;
}
double len(const Point &a) {
    return sqrt(dot(a,a));
}
double getAng(const Point &a, const Point &b) {
    return acos(dot(a,b)/len(a)/len(b));
}
double dist(const Point &a, const Point &b) {
    return len(a-b);
}
double sqr(double x) {
    return x*x;
}
double getAng(double a, double b, double c) {//get Angle C
    return acos((sqr(a)+sqr(b)-sqr(c))/(2*a*b));
}
double intersect(const Circle &a, const Circle &b) {
    double d = dist(a.m,b.m);
    if (d >= a.r+b.r)
        return 0;
    if (d <= fabs(a.r-b.r))
        return pi*sqr(min(a.r,b.r));
    double a1 =getAng(a.r, d, b.r), a2 = getAng(b.r, d, a.r);
    return (a1*a.r*a.r+a2*b.r*b.r-d*a.r*sin(a1));
}
int n;
const int MAXN = 25;
Circle cir[MAXN];
bool check(const Circle &c) {
    for (int i = 0; i < n; ++i) {
        if (dblcmp(2*intersect(c, cir[i])-pi*sqr(cir[i].r)) < 0) {
            return false;
        }
    }
    return true;
}
void load() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lf%lf%lf", &cir[i].m.x, &cir[i].m.y, &cir[i].r);
    }
}
bool test(double r) {
    for (int i = 0; i < n; ++i) {
        if (check(Circle(cir[i].m,r)))
            return true;
    }
    return false;
}
void work() {
    double l = 0, r = 20000;
    while (r-l > eps) {
        double m = (r+l)/2;
        if (test(m)) {
            r = m;
        } else {
            l = m;
        }
    }
    printf("%.4lf\n", l);
}
int main(int argc, char const *argv[]) {
    int T;
    scanf("%d", &T);
    for (int cas = 0; cas < T; ++cas) {
        load();
        work();
    }
    return 0;
}
