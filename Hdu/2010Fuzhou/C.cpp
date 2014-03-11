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
double dblcmp(double x) {
    if (x < eps)
        return 0;
    if (x > 0)
        return 1;
    return -1;
}
typedef struct Point3 {
    double x, y, z;
    void scan() {
        scanf("%lf%lf%lf", &x, &y, &z);
    }
    Point3() {}
    Point3(double a, double b, double c): x(a), y(b), z(c) {}
    Point3 operator+(const Point3 &t) const {
        return Point3(x+t.x, y+t.y, z+t.z);
    }
    Point3 operator-(const Point3 &t) const {
        return Point3(x-t.x, y-t.y, z-t.z);
    }
    Point3 operator*(double d) const {
        return Point3(x*d,y*d,z*d);
    }
} Vector3;
double dot(const Point3 &a, const Point3 &b) {
    return a.x*b.x+a.y*b.y+a.z*b.z;
}
struct Plane {
    Vector3 norm;
    Point3 p0;
};
Point3 intersect(const Point3 &a, const Point3 &b, const Plane &f) {
    Vector3 l = b-a;
    double t = dot(f.p0-a,f.norm)/dot(l,f.norm);
    return a+l*t;
}
const int MAXN = 205;
double A, B, C, D;
Plane ground;
Point3 rock[MAXN];
int n;
bool load() {
    scanf("%lf%lf%lf%lf", &A, &B, &C, &D);
    if (0 == A && 0 == B && 0 == C && 0 == D)
        return false;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        rock[i].scan();
    rock[0].scan();
    return true;
}
double calc(const Point3 &p) {
    return A*p.x+B*p.y+C*p.z-D;
}
void adjust() {
    double t = calc(rock[0]);
    D += t;
}
void getPlane() {
    ground.norm = Vector3(A,B,C);
    if (A != 0) {
        ground.p0 = Point3(D/A,0,0);
    } else if (B != 0) {
        ground.p0 = Point3(0,D/B,0);
    } else if (C != 0) {
        ground.p0 = Point3(0,0,D/C);
    }
}
void prepare() {
    getPlane();
    adjust();
}
struct Point2 {
    double x, y;
    Point2() {}
    Point2(double a, double b): x(a), y(b) {}
};
Point3 interp[MAXN];
bool judge() {
    double tt = calc(ground.p0);
    for (int i = 1; i <= n; ++i) {
        double tmp = calc(ground.p0);
        if (0 == dblcmp(tmp) || tmp*tt < 0) {
            return true;
        }
    }
    return false;
}
void rotate() {

}
void work() {
    prepare();
    if (judge()) {
        puts("Infi");
        return ;
    }
}
int main(int argc, char const *argv[]) {
    while (load()) {
        work();
    }
    return 0;
}