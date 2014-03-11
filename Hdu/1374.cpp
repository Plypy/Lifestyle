/**
 * Description: Compute the circumcircle
 * Source:  hdu 1374
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

struct Point {
    double x, y;
    Point() {}
    Point(double a, double b): x(a), y(b) {}
    bool read() {
        return (2 == scanf("%lf%lf", &x, &y));
    }
};

Point circumCenter(const Point &a, const Point &b, const Point &c) {
    Point ret;
    double a1 = b.x-a.x, b1 = b.y-a.y, c1 = (a1*a1+b1*b1)/2;
    double a2 = c.x-a.x, b2 = c.y-a.y, c2 = (a2*a2+b2*b2)/2;
    double d = a1*b2-a2*b1;
    ret.x = a.x+(c1*b2-c2*b1)/d;
    ret.y = a.y+(a1*c2-a2*c1)/d;
    return ret;
}
double sqr(double a) {
    return a*a;
}
double dist(const Point &a, const Point &b) {
    return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}
const double PI = acos(-1.0);
int main(int argc, char const *argv[]) {
    Point a, b, c;
    while (a.read() && b.read() && c.read()) {
        Point m = circumCenter(a, b, c);
        double ans = 2*PI*dist(a,m);
        printf("%.2lf\n", ans);
    }
    return 0;
}
