/**
 * Description: Simple geometry. key, perpendicular bisector, line & segment intersection
 * Source: hdu 4643
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

const double EPS = 1e-7;
const double INF = 1e100;
int dblcmp(double x) {
    if (abs(x) < EPS)
        return 0;
    return x>0?1:-1;
}

typedef struct Point {
    double x, y;
    void read() {
        scanf("%lf%lf", &x, &y);
    }
    void write() {
        printf("%lf %lf\n", x, y);
    }
    Point() { };
    Point(double a, double b): x(a), y(b) {}
} Vector;

Vector operator+(Vector a, Vector b) {
    return Vector(a.x+b.x,a.y+b.y);
}
Vector operator-(Vector a, Vector b) {
    return Vector(a.x-b.x,a.y-b.y);
}
Vector operator*(double d, Vector v) {
    return Vector(d*v.x,d*v.y);
}
Vector operator*(Vector v, double d) {
    return d*v;
}
Vector operator/(Vector v, double d) {
    return v*(1/d);
}
Point getMid(Point a, Point b) {
    return (a+b)/2;
}
double dot(Vector a, Vector b) {
    return a.x*b.x+a.y*b.y;
}
double length(Vector v) {
    return sqrt(dot(v,v));
}
double cross(Vector a, Vector b) {
    return a.x*b.y-a.y*b.x;
}
double dist(Point a, Point b) {
    return length(b-a);
}
Vector unit(Vector v) {
    return v/length(v);
}
Vector norm(Vector v) {
    return unit(Vector(-v.y,v.x));
}
bool isParallel(Vector a, Vector b) {
    return (0 == dblcmp(cross(a,b)));
}
Point getIntersection(Point a, Point b, Point c, Point d) {
    Vector u = b-a, v = d-c, w = c-a;
    double t = cross(w, v)/cross(u, v);
    return a+t*u;
}
bool checkOnSegment(Point l, Point r, Point p) {
    return (dblcmp((p.x-l.x)*(p.x-r.x)) <= 0 && dblcmp((p.y-l.y)*(p.y-r.y)) <= 0);
}

int cnt;
const int MAXN = 55;
const int MAXM = 55;
struct Intersection {
    double dis;
    int a, b;
    bool operator<(const Intersection &t) const {
        return dis<t.dis;
    }
} plis[MAXM*MAXM];
int ans[MAXN][MAXN];
Point station[MAXM], city[MAXN];
int n, m;
void init() {
    memset(ans,-1,sizeof(ans));
}
void work() {
    int k;
    scanf("%d", &k);
    while (k--) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a > b)
            swap(a,b);
        if (ans[a][b] != -1) {
            printf("%d\n", ans[a][b]);
            continue;
        }
        double st = 1, mdist = dist(station[1],city[a]);
        cnt = 0;
        for (int i = 1; i <= m; ++i) {
            double tmp;
            if ((tmp = dist(station[i],city[a])) < mdist) {
                st = i;
                mdist = tmp;
            }
            for (int j = i+1; j <= m; ++j) {
                Point ta = getMid(station[j], station[i]);
                Vector tu = norm(station[j]-station[i]);
                if (isParallel(tu, city[b]-city[a]))
                    continue;
                tu = ta+tu;
                Point tp = getIntersection(ta, tu, city[a], city[b]);
                if (!checkOnSegment(city[a],city[b],tp))
                    continue;
                plis[cnt].dis = dist(tp,city[a]);
                plis[cnt].a = i, plis[cnt].b = j;
                ++cnt;
            }
        }
        sort(plis,plis+cnt);
        int k = 0, cur = st;
        ans[a][b] = 0;
        for (; k < cnt; ++k) {
            if (plis[k].a == cur) {
                cur = plis[k].b;
                ++ans[a][b];
            } else if (plis[k].b == cur) {
                cur = plis[k].a;
                ++ans[a][b];
            }
        }
        printf("%d\n", ans[a][b]);
    }
}
bool load() {
    if (EOF ==scanf("%d%d", &n, &m))
        return false;
    for (int i = 1; i <= n; ++i)
        city[i].read();
    for (int i = 1; i <= m; ++i)
        station[i].read();
    return true;
}
int main(int argc, char const *argv[]) {
    init();
    while (load()) {
        work();
        init();
    }
    return 0;
}