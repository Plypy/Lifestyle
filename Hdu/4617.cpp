/**
 * Description: Simple 3-d geometry problem. The main problem is to compute two line's distance.
 * Source: Hdu 4617
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

const double EPS = 1e-8;
const double INF = 1e100;
int dblcmp(double x) {
    if (abs(x) < EPS)
        return 0;
    return x>0?1:-1;
}

typedef struct Point {
    double x, y, z;
    void read() {
        scanf("%lf%lf%lf", &x, &y, &z);
    }
    Point() {}
    Point(double a, double b, double c): x(a), y(b), z(c) {}
} Vector;

Vector operator*(double d, Vector v) {
    return Vector(d*v.x,d*v.y,d*v.z);
}

Vector operator*(Vector v, double d) {
    return d*v;
}

Vector operator/(Vector v, double d) {
    return v*(1/d);
}

Vector operator-(Vector a, Vector b) {
    return Vector(a.x-b.x,a.y-b.y,a.z-b.z);
}

Vector cross(Vector a, Vector b) {
    return Vector(a.y*b.z-a.z*b.y,b.x*a.z-b.z*a.x,a.x*b.y-a.y*b.x);
}

double dot(Vector a, Vector b) {
    return a.x*b.x+a.y*b.y+a.z*b.z;
}

double length(Vector a) {
    return sqrt(dot(a,a));
}

double dist(Point a, Point b) {
    return length(a-b);
}

bool parallel(Vector a, Vector b) {
    return (0 == dblcmp(length(cross(a, b))));
}

Vector unit(Vector v) {
    return v/length(v);
}

struct Cylinder {
    Point m;
    Vector n;
    double r;
};

void get(Point a, Point b, Point c, Cylinder &t) {
    t.m = a;
    t.n = unit(cross(b-a,c-a));
    t.r = dist(b,a);
}

double dist(Cylinder a, Cylinder b) {
    Vector v = a.m-b.m;
    if (parallel(a.n, b.n)) {
        double l1 = length(v);
        double l2 = dot(v,a.n);
        return sqrt(l1*l1-l2*l2);
    } else {
        Vector u = cross(a.n,b.n);
        double d = abs(dot(u,v));
        d = d/(length(u))-a.r-b.r;
        if (dblcmp(d) <= 0)
            return 0;
        return d;
    }
}
const int MAXN = 35;
Cylinder cy[MAXN];
int n;
int main(int argc, char const *argv[]) {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            Point a, b, c;
            a.read(), b.read(), c.read();
            get(a,b,c,cy[i]);
        }
        double mlen = INF;
        for (int i = 1; i < n; ++i)
            for (int j = i+1; j <= n; ++j) {
                double d = dist(cy[i],cy[j]);
                mlen = min(d,mlen);
            }
        if (mlen == 0) {
            printf("Lucky\n");
        } else {
            printf("%.2lf\n", mlen);
        }
    }
    return 0;
}