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

double pi = acos(-1);
struct Point {
    double x, y, z;
    Point() {}
    Point(double x, double y, double z): x(x), y(y), z(z) { }
    void read() {
        scanf("%lf%lf%lf", &x, &y, &z);
    }
};
double len(Point &v) {
    return sqrt(v.x*v.x+v.y*v.y+v.z*v.z);
}
double calc(double h, double r) {
    return 2*pi*r*(r-h);
}
double solve(double d, double r) {
    double l = sqrt(d*d-r*r);
    double x = r*l/d;
    return sqrt(r*r-x*x);
}

int main(int argc, char const *argv[]) {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        Point a, b;
        double r;
        scanf("%lf", &r);
        a.read();
        b.read();

        double l1 = len(a), l2 = len(b);
        double h1 = solve(l1,r), h2 = solve(l2,r);
        double tot = 4*pi*r*r;
        double sum = calc(h1,r)+calc(h2,r);
        double ans = sum/tot*100;
        printf("Case #%d: %.5lf%%\n",i , ans);
    }
    return 0;
}