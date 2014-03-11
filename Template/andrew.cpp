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
const double PI = acos(-1);
const int MAXN = 1005;
typedef struct Point {
    double x, y;
    Point(double x = 0, double y = 0):x(x), y(y) { }
    bool operator<(const Point &t) const {
        if (x != t.x)
           return x<t.x;
        return y<t.y;
    }
    Point operator-(const Point &t) const{
        return Point(x-t.x,y-t.y);
    }
    friend istream &operator>>(istream &is, Point &t) {
        is >> t.x >> t.y;
        return is;
    }
    friend ostream &operator<<(ostream &os, const Point &t) {
        os << t.x << ' ' << t.y;
        return os;
    }
} Vector;
double norm(const Point &a) {
    return sqrt(a.x*a.x+a.y*a.y);
}
double dist(const Point &a, const Point &b) {
    return norm(a-b);
}
double cross(const Vector &a, const Vector &b) {
    return a.x*b.y-a.y*b.x;
}
double notLeft(const Vector &a, const Vector &b) {
    return cross(a,b)<=0;
}

int convex(Point *p, int n, Point *ch) {
    sort(p, p+n);
    int top = 0;
    for (int i = 0; i < n; ++i) {
        while (top > 1 && notLeft(ch[top-1]-ch[top-2],p[i]-ch[top-2]))
            --top;
        ch[top++] = p[i];
    }
    int k = top;
    for (int i = n-2; i >= 0; --i) {
        while (top>k && notLeft(ch[top-1]-ch[top-2],p[i]-ch[top-2]))
            --top;
        ch[top++] = p[i];
    }
    if (n>1)
        --top;
    return top;
}
double polyLen(Point *polygon, int n) {
    double ret = 0;
    for (int i = 0; i < n; ++i) {
        ret += dist(polygon[i],polygon[(i+1)%n]);
    }
    return ret;
}