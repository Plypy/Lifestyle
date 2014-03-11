/**
 * Description: Check whether a point is in a convex polygon
 * Source: sgu 253
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
struct Point {
    double x, y;
    Point(): x(0), y(0) {}
    Point(double a, double b): x(a), y(b) {}
    void scan() {
        scanf("%lf%lf", &x, &y);
    }
};

double cross(const Point &a, const Point &b, const Point &c) {
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
bool checkIn(Point *poly, int n, const Point &pt) {
    int l = 1, r = n-1;
    if (dblcmp(cross(poly[0], poly[1], pt)) < 0)
        return false;
    // puts("pass 1");
    if (dblcmp(cross(poly[0], pt, poly[n-1])) < 0)
        return false;
    // puts("pass 2");
    while (l+1 < r) {
        int mid = (l+r)/2;
        if (dblcmp(cross(poly[0], poly[mid], pt)) >= 0) {
            l = mid;
        } else {
            r = mid;
        }
    }
    // cout << l << ' ' << r << endl;
    return (dblcmp(cross(poly[l], poly[l+1], pt)) >= 0);
}
const int MAXN = 100005;
Point poly[MAXN];
int n, m, k;
int main(int argc, char const *argv[]) {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i) {
        poly[i].scan();
    }
    Point pt;
    for (int i = 0; i < m; ++i) {
        pt.scan();
        if (checkIn(poly, n, pt)) {
            --k;
            // cout << i << " in" << endl;
        }
    }
    if (k <= 0)
        puts("YES");
    else
        puts("NO");
    return 0;
}