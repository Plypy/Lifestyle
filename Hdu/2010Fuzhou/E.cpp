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

const double eps = 1e-8;
const double pi = acos(-1);
int dblcmp(double x) {
    if (fabs(x) < eps)
        return 0;
    return x>0?1:-1;
}
struct Point {
    double x, y;
    void scan() {
        scanf("%lf%lf", &x, &y);
    }
    Point(double a = 0, double b = 0): x(a), y(b) { }
} p[4];
double sqr(double a) {
    return a*a;
}
double dist(const Point &a, const Point &b) {
    return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}
double eval(const Point &pt) {
    double ret = 0;
    for (int i = 0; i < 4; ++i)
        ret += dist(pt,p[i]);
    return ret;
}
Point operator-(const Point &a, const Point &b) {
    return Point(a.x-b.x,a.y-b.y);
}
Point operator+(const Point &a, const Point &b) {
    return Point(a.x+b.x,a.y+b.y);
}
Point operator*(const Point &v, double t) {
    return Point(v.x*t,v.y*t);
}
double cross(const Point &a, const Point &b) {
    return a.x*b.y-a.y*b.x;
}
double area2(const Point &a, const Point &b, const Point &c) {
    return cross(b-a,c-a);
}
Point getIntersection(const Point &P, const Point &p, const Point &Q, const Point &q) {//保证两直线相交的情况下，求交点
    Point u = p-P, v = q-Q, w = P-Q;
    double t = cross(v,w)/cross(u,v);
    return P+u*t;
}

int main(int argc, char const *argv[]) {
    while (true) {
        for (int i = 0; i < 4; ++i)
            p[i].scan();
        if (p[0].x < 0)
            break;
        for (int i = 1; i < 4; ++i)
            for (int j = i+1; j < 4; ++j) {
                if (area2(p[0],p[i],p[j]) <= 0)
                    swap(p[i],p[j]);
            }
        Point ansp = p[0];
        double ans = eval(ansp);
        for (int i = 1; i < 4; ++i) {
            double tmp = eval(p[i]);
            if (tmp < ans) {
                ans = tmp;
                ansp = p[i];
            }
        }
        if (dblcmp(cross(p[0]-p[2],p[1]-p[3])) != 0) {
            Point tp = getIntersection(p[0], p[2], p[1], p[3]);
            double tmp = eval(tp);
            if (tmp < ans) {
                ans = tmp;
                ansp = tp;
            }
        }
        // cout << ansp.x << ' ' << ansp.y << endl;
        printf("%.4lf\n", ans);
    }
    return 0;
}
