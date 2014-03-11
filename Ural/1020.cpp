/**
 * Description: All the arcs add up to a circle exactly
 * Source: Ural 1020
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

const double eps = 1e-10; //阙值
const double PI  = acos(-1);
int dblcmp(double x) {//为回避误差，所用的比较函数
    if (fabs(x) < eps)
        return 0;
    return x>0?1:-1;
}

typedef struct Vector { //二维向量（点）类，以及一些操作符重载
    double x, y;
    Vector(double x = 0, double y = 0): x(x), y(y) { }
    friend istream &operator>>(istream &is, Vector &v) {
        is >> v.x >> v.y;
        return is;
    }
    friend ostream &operator<<(ostream &os, const Vector &v) {
        os << v.x << ' ' << v.y;
        return os;
    }
    Vector operator-(const Vector &t) const {
        return Vector(x-t.x,y-t.y);
    }
} Point;

double length(const Vector &v) {
    return sqrt(v.x*v.x+v.y*v.y);
}

double dist(const Point &a, const Point &b) {
    return length(a-b);
}

double polygonLen(const Point *poly, int n) {
    double ret = 0;
    for (int i = 0; i < n; ++i)
        ret += dist(poly[i],poly[(i+1)%n]);
    return ret;
}

const int MAXN = 105;
Point pt[MAXN];
int n;
double l;
int main() {
    cin >> n >> l;
    for (int i = 0; i < n; ++i)
        cin >> pt[i];
    double ans = polygonLen(pt,n)+2*PI*l;
    cout << fixed << setprecision(2);
    cout << ans << endl;
    return 0;
}