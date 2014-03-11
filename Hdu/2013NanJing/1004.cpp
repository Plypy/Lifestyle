/**
 * Description: ToDo urgent!
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

const double eps = 1e-8;
int dblcmp(double x) {
    if (fabs(x) < eps)
        return 0;
    return x>0?1:-1;
}
double sqr(double x) {
    return x*x;
}
struct Point3 {
    double x, y, z;
    Point3(): x(0), y(0), z(0) {}
    Point3(double a, double b, double c): x(a), y(b), z(c) {}
    Point3 operator+(const Point3 &t) const {
        return Point3(x+t.x,y+t.y,z+t.z);
    }
    Point3 operator-(const Point3 &t) const {
        return Point3(x-t.x,y-t.y,z-t.z);
    }
    Point3 operator*(const double &d) const {
        return Point3(d*x,d*y,d*z);
    }
    friend Point3 operator*(double d, const Point3 &t) {
        return t*d;
    }
    Point3 operator/(const double &d) const {
        return (*this)*(1/d);
    }
    double len() const{
        return sqrt(sqr(x)+sqr(y)+sqr(z));
    }
    Point3 resize(double d) const {
        d /= len();
        return (*this)*d;
    }
    Point3 unit() const {
        return (*this)/len();
    }
    bool same(const Point3 &t) const {
        return dblcmp(x-t.x) == 0 && dblcmp(y-t.y) == 0 && dblcmp(z-t.z) == 0;
    }
    void read() {
        scanf("%lf%lf%lf", &x, &y, &z);
    }
    void write() {
        printf("%lf %lf %lf\n", x, y, z);
    }
};

double dot(const Point3 &a, const Point3 &b) {
    return a.x*b.x+a.y*b.y+a.z*b.z;
}
Point3 cross(const Point3 &a, const Point3 &b) {
    return Point3(a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x);
}
struct Face {
    Point3 a, b, c;
    Face() {}
    Face(Point3 a, Point3 b, Point3 c): a(a), b(b), c(c) {}
    Point3 norm() const {
        return cross(b-a, c-a);
    }
};
double mix(const Point3 &a, const Point3 &b, const Point3 &c) {
    return dot(cross(a,b),c);
}
double area2(const Point3 &o, const Point3 &a, const Point3 &b) {
    return cross(a-o, b-o).len();
}
double vol6(const Point3 &o, const Point3 &a, const Point3 &b, const Point3 &c) {
    return fabs(mix(a-o, b-o, c-o));
}
double angle(const Point3 &a, const Point3 &b) {
    return acos(dot(a,b)/a.len()/b.len());
}

bool isPara(const Point3 &a, const Point3 &b, const Point3 &c, const Point3 &d) {
    return 0 == dblcmp(cross(b-a, d-c).len());
}
bool isPara(const Face &f, const Point3 &a, const Point3 &b) {
    return 0 == dblcmp(dot(f.norm(),b-a));
}
bool isPara(const Face &f1, const Face &f2) {
    return 0 == dblcmp(cross(f1.norm(), f2.norm()).len());
}
bool isPerp(const Point3 &a, const Point3 &b, const Point3 &c, const Point3 &d) {
    return 0 == dblcmp(dot(b-a,d-c));
}
bool isPerp(const Face &f, const Point3 &a, const Point3 &b) {
    return 0 == dblcmp(cross(f.norm(), b-a).len());
}
bool isPerp(const Face &f1, const Face &f2) {
    return 0 == dblcmp(dot(f1.norm(), f2.norm()));
}

double dist(const Point3 &a, const Point3 &b) {
    return (a-b).len();
}
double dist(const Point3 &l, const Point3 &r, const Point3 &p) {
    return area2(l, r, p)/dist(l,r);
}
double dist(const Point3 &a, const Point3 &b, const Point3 &c, const Point3 &d) {
    Point3 fa = cross(b-a, d-c);
    if (fa.len() == 0) {
        return area2(a, b, c)/dist(a,b);
    } else {
        return fabs(dot(c-a,fa)/fa.len());
    }
}
double dist(const Face &f, const Point3 &p) {
    Point3 fa = f.norm();
    return fabs(dot(fa,f.a-p)/fa.len());
}
Point3 getLineProjection(const Point3 &l, const Point3 &r, const Point3 &p) {
    Point3 v = r-l;
    return l+v*(dot(v,p-l)/dot(v,v));
}
bool onLine(const Point3 &l, const Point3 &r, const Point3 &p) {
    return 0 == dblcmp(area2(l, r, p));
}
bool onSegmentIn(const Point3 &l, const Point3 &r, const Point3 &p) {
    return onLine(l, r, p) && dblcmp((p.x-l.x)*(p.x-r.x)) <= 0
    && dblcmp((p.y-l.y)*(p.y-r.y)) <= 0 && dblcmp((p.z-l.z)*(p.z-r.z)) <= 0;
}
bool onSegmentEx(const Point3 &l, const Point3 &r, const Point3 &p) {
    return onSegmentIn(l, r, p) && !l.same(p) && !r.same(p);
}
bool onFace(const Point3 &a, const Point3 &b, const Point3 &c, const Point3 &d) {
    return 0 == dblcmp(vol6(a, b, c, d));
}
bool inTriangle(const Point3 &a, const Point3 &b, const Point3 &c, const Point3 &p) {
    double s = area2(a, b, c);
    double s1 = area2(a, b, p);
    double s2 = area2(b, c, p);
    double s3 = area2(c, a, p);
    return 0 == dblcmp(s-s1-s2-s3);
}
Point3 intersect(const Face &f, const Point3 &a, const Point3 &b) {
    Point3 fa = f.norm();
    Point3 v = b-a;
    double t = dot(fa,f.a-a)/ dot(fa,v);
    return a+v*t;
}
// compute the intersection betweeen (a-b) and (c-d)
Point3 intersect(const Point3 &a, const Point3 &b, const Point3 &c, const Point3 &d) {
    Point3 e = d+cross(a-b, c-d);
    return intersect(Face(c,d,e),a,b);
}
// compute the coordination of p after rotate ang angle anti-clockwise by (l->r) vector
Point3 rotate(const Point3 &l, const Point3 &r, const Point3 &p, double ang) {
    if (onLine(l, r, p))
        return p;
    Point3 ph = getLineProjection(l, r, p);
    Point3 e = (r-l).unit();
    Point3 x = p-ph;
    Point3 y = cross(x,e);
    return ph+x*cos(ang)+y*sin(ang);
}
// common perpendicular
void commonPerp(const Point3 &a, const Point3 &b, const Point3 &c, const Point3 &d, Point3 &p1, Point3 &p2) {
    Point3 e = d+cross(b-a, c-d);
    p1 = intersect(Face(c,d,e), a, b);
    p2 = getLineProjection(c, d, p1);
}

const int MAXN = 100005;
Point3 S, T, V;
Face sface;
Face tri[MAXN];
int n;
void init() {

}
bool load() {
    if (EOF ==scanf("%d", &n))
        return false;
    init();
    S.read(), T.read(), V.read();
    for (int i = 0; i < n; ++i) {
        Point3 a, b, c;
        a.read(), b.read(), c.read();
        tri[i] = Face(a,b,c);
    }
    return true;
}
double slen;
void fix(const Point3 &l, const Point3 &r, Point3 &p) {
    Point3 v1 = p-l, v2 = p-r;
    if (dot(v1,v2) <= 0)
        return;
    if (v1.len() < v2.len())
        p = l;
    else
        p = r;
}
bool lineXseg(const Point3 &l, const Point3 &r, const Point3 &sl, const Point3 &sr) {
    if (isPara(l, r, sl, sr))
        return false;
    Point3 pt = intersect(l, r, sl, sr);
    return onSegmentIn(sl, sr, pt);
}
bool check(const Point3 &l, const Point3 &r, const Face &tr) {
    if (isPara(tr, l, r)) {
        if (onFace(tr.a, tr.b, tr.c, l)) {
            if (lineXseg(l,r,tr.a,tr.b))
                return true;
            if (lineXseg(l, r, tr.b, tr.c))
                return true;
            if (lineXseg(l, r, tr.c, tr.a))
                return true;
        }
    } else {
        Point3 pt = intersect(tr, l, r);
        if (inTriangle(tr.a, tr.b, tr.c, pt))
            return true;
    }
    return false;
}
bool crossTri(const Point3 &l, const Point3 &r, const Face &f) {
    return true;
}
bool onFace(const Face &f, const Point3 &pt) {
    return onFace(f.a, f.b, f.c, pt);
}
void work() {
    double ans = 0;
    sface = Face(S,T,S+V);
    slen = (S-T).len();
    if (S.same(T)) {
        while (true) { }
        V = S+V;
        for (int i = 0; i < n; ++i) {
            if (check(S,V,tri[i]))
                ans += 1;
        }
        printf("%.8lf\n", ans);
        return ;
    }
    if (V.same(Point3(0,0,0))) {
        return ;
        for (int i = 0; i < n; ++i) if (onFace(tri[i], S) && onFace(tri[i], T)) {
            Point3 l, r;
            int flag = 0;
            Point3 tmp;
            if (!isPara(S, T, tri[i].a, tri[i].b)) {
                tmp = intersect(S, T, tri[i].a, tri[i].b);
                if (onSegmentIn(tri[i].a, tri[i].b, tmp)) {
                    l = tmp;
                    flag = 1;
                }
            }
            if (!isPara(S, T, tri[i].b, tri[i].c)) {
                tmp = intersect(S, T, tri[i].b, tri[i].c);
                if (onSegmentIn(tri[i].b, tri[i].c, tmp)) {
                    if (1 == flag) {
                        flag = 2;
                        r = tmp;
                    } else {
                        l = tmp;
                        flag = 1;
                    }
                }
            }
            if (!isPara(S, T, tri[i].c, tri[i].a)) {
                tmp = intersect(S, T, tri[i].c, tri[i].a);
                if (onSegmentIn(tri[i].c, tri[i].a, tmp)) {
                    if (1 == flag) {
                        r = tmp;
                    } else if (2 == flag) {
                        if (!tmp.same(l))
                            r = tmp;
                    }
                }
            }
            fix(S, T, l);
            fix(S, T, r);
            ans += (l-r).len()/slen;
        }
        printf("%.8lf\n", ans);
        return ;
    }
    if (dblcmp(cross(V, S-T).len()) == 0) {
        while (true) {}
        for (int i = 0; i < n; ++i) {
            if (crossTri(S,T,tri[i]))
                ans += 1;
        }
        printf("%.8lf\n", ans);
        return ;
    }
    for (int i = 0; i < n; ++i) {
        Point3 l, r;
        if (isPara(sface, tri[i])) {
            if (onFace(sface.a, sface.b, sface.c, tri[i].a)) {
                Point3 a = intersect(S, T, tri[i].a, tri[i].a+V);
                Point3 b = intersect(S, T, tri[i].b, tri[i].b+V);
                Point3 c = intersect(S, T, tri[i].c, tri[i].c+V);
                // Point3 a = getLineProjection(S, T, tri[i].a);
                // Point3 b = getLineProjection(S, T, tri[i].b);
                // Point3 c = getLineProjection(S, T, tri[i].c);
                l = a, r = b;
                if ((b-c).len() > (l-r).len())
                    l = b, r =c;
                if ((a-c).len() > (l-r).len())
                    l = a, r = c;
            }
        } else {
            int flag = 0;
            Point3 a = intersect(sface, tri[i].b, tri[i].c);
            if (onSegmentIn(tri[i].b, tri[i].c,a)) {
                a = intersect(S, T, a, a+V);
                // a = getLineProjection(S, T, a);
                l = a;
                flag = 1;
            }
            Point3 b = intersect(sface, tri[i].a, tri[i].c);
            if (onSegmentIn(tri[i].a, tri[i].c,b)) {
                b = intersect(S, T, b, b+V);
                // b = getLineProjection(S, T, b);
                if (1 == flag) {
                    r = b;
                    flag = 2;
                } else {
                    flag = 1;
                    l = b;
                }
            }
            Point3 c = intersect(sface, tri[i].a, tri[i].b);
            if (onSegmentIn(tri[i].a, tri[i].b,c)) {
                c = intersect(S, T, c, c+V);
                // c = getLineProjection(S, T, c);
                if (2 == flag) {
                    if (!c.same(l))
                        r = c;
                } else if (1 == flag) {
                    r = c;
                } else {

                }
            }
        }
        fix(S,T,l);
        fix(S,T,r);
        ans += (r-l).len()/slen;
    }
    printf("%.8lf\n", ans);
}
void test() {
    while (true) {
        Point3 a, b, c, d, e;
        a.read(), b.read(), c.read(), d.read(), e.read();
        cout << check(a,b,Face(c,d,e)) << endl;
    }
}
int main(int argc, char const *argv[]) {
    // test();
    while (load()) {
        work();
    }
    return 0;
}