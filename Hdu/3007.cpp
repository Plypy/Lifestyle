/**
 * Description: Minimum covering circle
 * Source: HDU 3007
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
Point circumCenter(const Point &a, const Point &b) {
    return Point((a.x+b.x)/2,(a.y+b.y)/2);
}
Point center;
double radius;
bool checkInCircle(const Point &p) {
    return dblcmp(dist(p,center)-radius) == -1;
}
void minCover(Point pt[], int n) {
    radius = 0;
    center = pt[0];
    for (int i = 1; i < n; ++i) {
        if (!checkInCircle(pt[i])) {
            center = pt[i];
            radius = 0;
            for (int j = 0; j < i; ++j)
                if (!checkInCircle(pt[j])) {
                    center = circumCenter(pt[i], pt[j]);
                    radius = dist(pt[i],center);
                    for (int k = 0; k < j; ++k) {
                        if (!checkInCircle(pt[k])) {
                            center = circumCenter(pt[i], pt[j], pt[k]);
                            radius = dist(pt[i],center);
                        }
                    }
                }
        }
    }
}
void shuffle(int ar[], int n) {
    srand(time(0));
    for (int i = 0; i < n; ++i) {
        int a = rand()%n, b = rand()%n;
        swap(ar[a],ar[b]);
    }
}
const int MAXN = 505;
int n;
Point pt[MAXN];
int ord[MAXN];
int main(int argc, char const *argv[]) {
    while (true) {
        scanf("%d", &n);
        if (!n)
            break;
        for (int i = 0; i < n; ++i)
            ord[i] = i;
        shuffle(ord,n);
        for (int i = 0; i < n; ++i)
            pt[ord[i]].read();
        minCover(pt, n);
        printf("%.2lf %.2lf %.2lf\n", center.x, center.y, radius);
    }
    return 0;
}
