/**
 * Description:
 * ProblemName:
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
#include <vector>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
using namespace std;
#define x first
#define y second
const int MAXN = 100005;

typedef pair<double,double> Pt;

Pt pt[MAXN];
int n;
double sqr(double a) {
    return a*a;
}
double dist(Pt &a, double x) {
    return sqrt(sqr(a.x-x)+sqr(a.y));
}
double eval(double x) {
    double ret = 0;
    for (int i = 0; i < n; ++i)
        ret += dist(pt[i],x);
    return ret;
}
double minx, maxx;

void load() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lf%lf", &pt[i].x, &pt[i].y);
    }
    minx = pt[0].x, maxx = pt[0].x;
    for (int i = 1; i < n; ++i) {
        if (pt[i].x > maxx)
            maxx = pt[i].x;
        if (pt[i].x < minx)
            minx = pt[i].x;
    }
}
const double eps = 1e-7;
double work() {
    double l = minx, r = maxx;
    while (fabs(r-l) > eps) {
        double d = (r-l)/3;
        double m1 = l+d, m2 = l+2*d;
        if (eval(m1) < eval(m2)) {
            r = m2;
        } else {
            l = m1;
        }
    }
    return l;
}
int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; ++t) {
        load();
        printf("Case %d: %.8lf\n", t+1, work());
    }
    return 0;
}