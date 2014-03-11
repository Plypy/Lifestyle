/**
 * Description: On a plane, given a set of points. The size is odd and greater than or equal to 5
 * Source: Ural 1103
 * Solution: Supposing that a circle's angle of circumference is alpha
 * then if a point is outside the circle, we will have its angle will be smaller than alpha.
 * if it is in, then its angle will be larger than alpha
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
const double eps = 1e-18;
inline int dblcmp(double x) {
    if (fabs(x) < eps)
        return 0;
    return (x>0)?1:-1;
}
typedef struct Vector {
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
    bool operator<(const Vector& t) const {
        if (x != t.x)
            return x<t.x;
        return y<t.y;
    }
} Point;
Vector operator-(const Vector &a, const Vector &b) {
    return Vector(a.x-b.x,a.y-b.y);
}
Vector operator+(const Vector &a, const Vector &b) {
    return Vector(a.x+b.x,a.y+b.y);
}
double dot(const Vector &a, const Vector &b) {
    return a.x*b.x+a.y*b.y;
}
double cross(const Vector &a, const Vector &b) {
    return a.x*b.y-a.y*b.x;
}
double area2(const Point &l, const Point &r, const Point &p) {
    return cross(r-l,p-l);
}
bool notLeft(const Point &l, const Point &r, const Point &p) {
    return dblcmp(area2(l,r,p)) <= 0;
}
double length(const Vector &v) {
    return sqrt(v.x*v.x+v.y*v.y);
}
double dist(const Point &a, const Point &b) {
    return length(b-a);
}
double angle(const Vector &a, const Vector &b) {
    return acos(dot(a,b)/length(a)/length(b));
}
int convexHull(Point *pset, int n, int *ch) {
    sort(pset,pset+n);
    int top = 0;
    for (int i = 0; i < n; ++i) {
        while (top > 1 && notLeft(pset[ch[top-2]],pset[ch[top-1]],pset[i]))
            --top;
        ch[top++] = i;
    }
    int tmp = top;
    for (int i = n-2; i >= 0; --i) {
        while (top > tmp && notLeft(pset[ch[top-2]],pset[ch[top-1]],pset[i]))
            --top;
        ch[top++] = i;
    }
    if (n>1)
        --top;
    return top;
}
const int MAXN = 5005;
Point p[MAXN];
int ch[MAXN];
int n;
struct Data {
    double ang;
    int id;
    bool operator<(const Data &t) const {
        return ang<t.ang;
    }
} data[MAXN];
int ct;
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    int m = convexHull(p,n,ch);
    // for (int i = 0; i < m; ++i)
    //     cout << ch[i] << endl;
    // cout << "ConvexHull" << endl;
    Point a = p[ch[0]], b = p[ch[1]];
    for (int i = 1; i < n; ++i) {
        if (i == ch[1])
            continue;
        double ang = angle(a-p[i],b-p[i]);
        data[ct].ang = ang;
        data[ct].id  = i;
        ++ct;
    }
    sort(data,data+ct);
    // for (int i = 0; i < ct; ++i)
    //     cout << data[i] << endl;
    cout << fixed << setprecision(0);
    cout << a << endl;
    cout << b << endl;
    cout << p[data[ct/2].id]  << endl;
    return 0;
}