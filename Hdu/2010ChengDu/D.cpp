#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 1e-8;
const double INF = 1E100;
const double PI = acos(-1.0);
int dblcmp(double x) {
    if (fabs(x) < eps)
        return 0;
    return x>0?1:-1;
}
struct Point {
    double x, y;
    Point():x(0), y(0) {}
    Point(double a, double b): x(a), y(b) {}
    void scan() {
        scanf("%lf%lf", &x, &y);
    }
    void write() const {
        printf("%lf %lf\n", x, y);
    }
};

Point operator-(const Point &a, const Point &b) {
    return Point(a.x-b.x,a.y-b.y);
}
Point operator+(const Point &a, const Point &b) {
    return Point(a.x+b.x,a.y+b.y);
}
Point operator*(const Point &a, const double d) {
    return Point(d*a.x,d*a.y);
}
double operator*(const Point &a, const Point &b) {
    return a.x*b.x+a.y*b.y;
}
double operator^(const Point &a, const Point &b) {
    return a.x*b.y-a.y*b.x;
}
double sqr(double a) {
    return a*a;
}
double length(const Point &a) {
    return sqrt(sqr(a.x)+sqr(a.y));
}
double dist(const Point &a, const Point &b) {
    return length(a-b);
}
Point rotate(const Point &a, const double ang) {
    return Point(a.x*cos(ang)-a.y*sin(ang),a.x*sin(ang)+a.y*cos(ang));
}
bool intersect(const Point &a, const Point &b, const Point &p, const Point &q, Point &pt) {
    if (dblcmp((b-a)^(q-p)) == 0)
        return false;
    double s1 = (a-p)^(q-p);
    double s2 = (b-p)^(q-p);
    pt = (b*s1-a*s2)*(1/(s1-s2));
    return true;
}
bool PointOnSegment(const Point &p, const Point &s, const Point &t) {
    return dblcmp((p-s)^(t-s)) == 0 && dblcmp((p-s)*(p-t)) <= 0;
}
double getAngle(const Point &a, const Point &b) {
    return acos((a*b)/length(a)/length(b));
}
double getTanAngle(const Point &a, const Point &b) {
    double t1 = getAngle(a,b);
    if (PI-t1 < t1)
        t1 = PI-t1;
    return PI/2-t1;
}
bool sameDirection(const Point &a, const Point &b) {
    return dblcmp(a*b) > 0;
}
bool onLeft(const Point &a, const Point &b) {//b is on the left location of a
    return dblcmp(a^b) > 0;
}
Point turn(const Point &line, const Point &laser, double r) { // inside r radius
    Point norm = rotate(line, PI/2);
    if (!sameDirection(norm, laser))
        norm = norm*-1;
    // laser.write();
    // norm.write();
    // cout << onLeft(norm, laser) << endl;
    if (onLeft(norm,laser))
        return rotate(laser, -r);
    return rotate(laser,r);
}
Point laser1, laser2;
Point prism[3];
double refl;
void output(const Point &a, const Point &b) {
    // a.write();
    // b.write();
    Point sect;
    if (intersect(a,b,Point(0,0), Point(5,0), sect)) {
        if (sameDirection(sect-a, b-a)) {
            printf("%.3lf\n", sect.x);
        } else {
            puts("Error");
        }
    } else {
        puts("Error");
    }
}
int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        laser1.scan();
        laser2.scan();
        for (int j = 0; j < 3; ++j)
            prism[j].scan();
        scanf("%lf", &refl);
        Point sect;
        double dis = INF;
        int fst = -1;
        for (int i = 0; i < 3; ++i) {
            Point tmp;
            if (intersect(laser1,laser2,prism[i],prism[(i+1)%3],tmp) && PointOnSegment(tmp, prism[i], prism[(i+1)%3])) {
                if (sameDirection(tmp-laser1, laser2-laser1))
                    if (dist(tmp,laser1) < dis) {
                        dis = dist(tmp,laser1);
                        sect = tmp;
                        fst = i;
                    }
            }
        }
        if (dis == INF) {
        } else {
            Point line = prism[(fst+1)%3]-prism[fst];
            double r1 = getTanAngle(laser2-laser1,line);
            double r2 = asin(sin(r1)/refl);
            // cout << "r1 r2 " << r1 << ' ' << r2 << endl;
            Point ndir = turn(line, laser2-laser1, r1-r2);
            // cout << "radius " << endl;
            // cout << r1 << ' ' << r2 << endl;
            // cout << getTanAngle(laser2-laser1, line) << ' ' << getTanAngle(ndir, line) << endl;
            laser1 = sect;
            laser2 = laser1+ndir;
            // (laser2-laser1).write();
            // output(laser1,laser2);
            for (int i = 0; i < 3; ++i) {
                if (i != fst) {
                    Point tmp;
                    if (intersect(laser1, laser2, prism[i], prism[(i+1)%3], tmp) && PointOnSegment(tmp, prism[i], prism[(i+1)%3])) {
                        if (sameDirection(tmp-laser1, laser2-laser1)) {
                            line = prism[i]-prism[(i+1)%3];
                            r1 = getTanAngle(laser2-laser1,line);
                            r2 = asin(sin(r1)*refl);
                            line = prism[(i+1)%3]-prism[i];
                            ndir = turn(line, laser2-laser1, r1-r2);
                            // cout << "radius" << endl;
                            // cout << r1 << ' ' << r2 << endl;
                            // cout << getTanAngle(laser2-laser1, line) << ' ' << getTanAngle(ndir, line) << endl;
                            laser1 = tmp;
                            laser2 = laser1+ndir;
                            break;
                        }
                    }
                }
            }
        }
        // (laser2-laser1).write();
        output(laser1,laser2);
    }
}

