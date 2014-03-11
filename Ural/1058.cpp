#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 55;
const double INFS = 1e-6;
const double INF = 1e6;
int n;
int dcomp(double a, double b) {
    if (abs(a-b) < INFS)
        return 0;
    return a>b?1:-1;
}
double sqr(double a) {
    return a*a;
}
struct Point {
    double x, y;
    Point(){ }
    Point(double ix, double iy): x(ix), y(iy) { }
    
} pt[MAXN];
struct Segment {
    Point s, t;
    Segment() { }
    Segment(Point is, Point it): s(is), t(it) { }
} seg[MAXN];
struct Vector {
    double x, y;
    Vector(){ }
    Vector(double ix, double iy): x(ix), y(iy) { }
};

Vector operator-(const Point &a, const Point &b) {
    return Vector(a.x-b.x,a.y-b.y);
}
double cross(const Vector &a, const Vector &b) {
    return a.x*b.y-b.x*a.y;
}
double dot(const Vector &a, const Vector &b) {
    return a.x*b.x+a.y*b.y;
}
double norm(const Vector &a) {
    return sqrt(sqr(a.x)+sqr(a.y));
}
double getcos(const Vector &a, const Vector &b) {
    return dot(a,b)/(norm(a)*norm(b));
}
void load() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> pt[i].x >> pt[i].y;
    for (int i = 1; i < n; ++i)
        seg[i].s = pt[i], seg[i].t = pt[i+1];
    seg[n].s = pt[n], seg[n].t = pt[1];
}

double area[MAXN][MAXN];
void init() {
    for (int i = 1; i < n; ++i)
        for (int j = i+1; j <= n; ++j)
            area[i][j] = area[i][j-1]+0.5*cross(seg[j].s-seg[i].s,seg[j].t-seg[i].s);
}

void test() {
    for (int i = 1; i < n; ++i)
        for (int j = i+1; j <= n; ++j)
            cout << i << ' ' << j << ' ' << area[i][j] << endl;
    double a = 1;
    printf("%.4lf\n", a);
}
void work() {
    init();
//    test();
    
    double ans = INF;
    for (int i = 1; i < n; ++i)
        for (int j = i+1; j <= n; ++j) {
            double part1 = area[i+1][j-1];
            double rest = area[1][n]-area[i][j];
            double part2 = area[i][j]-part1;
//            cout << i << ' ' << j << ' ' << part1 << ' ' << part2 << ' ' << rest << endl;
            if (dcomp(part2,abs(part1-rest))>=0) {
//                cout << i << ' ' << j << ' ' << "here" << endl;
                double wanted = 0.5*(part2-part1+rest);
                double l = INF;
                if (j == i+1) {
                    double theta = acos(getcos(seg[i].s-seg[i].t,seg[j].t-seg[j].s));
                    double t = sqrt(2*wanted/sin(theta));
                    l = 2*t*sin(0.5*theta);
                } else {
                    double angle1 = acos(getcos(seg[i].s-seg[i].t,seg[j].s-seg[i].t));
                    double angle2 = acos(getcos(seg[i].t-seg[j].s,seg[j].t-seg[j].s));
                    double d = 0, theta = 0;
                    if (dcomp(angle1,angle2) < 0)
                        swap(angle1,angle2);
                    double e = norm(seg[j].s-seg[i].t);
                    theta = 0.5*(angle1+angle2);
                    double angle3 = theta-angle2;
                    d = e/sin(theta)*sin(angle1);
                    wanted += 0.5*sin(angle3)*e*d;
                    
                    double a = sin(theta)*cos(theta);
                    double b = -d*sin(theta);
                    double c = wanted;
                    double x1 = (-b+sqrt(sqr(b)-4*a*c))/(2*a);
                    double x2 = (-b-sqrt(sqr(b)-4*a*c))/(2*a);
                    x1 = d-2*cos(theta)*x1;
                    x2 = d-2*cos(theta)*x2;
                    if (x1 > 0)
                        l = x1;
                    else
                        l = x2;
                    
//                    cout << i << ' ' << j << ' ' << x1 << ' ' << x2 << endl;
//                    cout << theta << endl;
                }
                if (ans > l)
                    ans = l;
            }
        }
    printf("%.6lf\n", ans);
}

int main() {
    load();
    work();
//    system("pause");
    return 0;
}
