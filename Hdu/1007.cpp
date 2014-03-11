/**
 * Description: Fingding a pair of Points with minimum distance
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
const double eps = 1e-4;
int dblcmp(double x) {
    if (fabs(x) < eps) {
        return 0;
    }
    return x>0?1:-1;
}
struct Point {
    double x, y;
    Point() {}
    Point(double a, double b): x(a), y(b) {}
} ;
double sqr(double a) {
    return a*a;
}
double dist(const Point &a, const Point &b) {
    return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}
const int MAXN = 100005;

Point a[MAXN];
int n, s[MAXN];

bool cmpx(int i, int j) {
    return dblcmp(a[i].x-a[j].x) < 0;
}
bool cmpy(int i, int j) {
    return dblcmp(a[i].y-a[j].y) < 0;
}

double min_dist(Point a[], int s[], int l, int r) {
    double ans = 1e100;
    if (r-l<20) {
        for (int q = l; q < r; ++q)
            for (int w = q+1; w < r; ++w)
                ans = min(ans,dist(a[s[q]],a[s[w]]));
        return ans;
    }
    int tl, tr, m = (l+r)/2;
    ans = min(min_dist(a,s,l,m),min_dist(a,s,m,r));
    for (tl = l; a[s[tl]].x < a[s[m]].x-ans; ++tl) continue;
    for (tr = r-1; a[s[tr]].x > a[s[m]].x+ans; --tr) continue;
    sort(s+tl,s+tr,cmpy);
    for (int q = tl; q < tr; ++q) {
        for (int w = q+1; w < min(tr,q+6); ++w) {
            ans = min(ans,dist(a[s[q]],a[s[w]]));
        }
    }
    sort(s+tl,s+tr,cmpx);
    return ans;
}
double solve(Point a[], int s[], int n) {
    for (int i = 0; i < n; ++i)
        s[i] = i;
    sort(s,s+n,cmpx);
    return min_dist(a,s,0,n);
}
int main(int argc, char const *argv[]) {
    while (true) {
        scanf("%d", &n);
        if (0 == n)
            break;
        for (int i = 0; i < n; ++i) {
            scanf("%lf%lf", &a[i].x, &a[i].y);
        }
        double ans = solve(a,s,n)/2;
        printf("%.2lf\n", ans);
    }
    return 0;
}