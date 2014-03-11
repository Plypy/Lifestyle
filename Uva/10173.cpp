/**
 * Description: These are my code for computational geometry.
 *************************************************************************************
 * There might be some errors, if you find any, please acknowledge me, please!!!
 * Note these codes use too many function calls, which make them look pretty, but slow.
 * So sometimes,for the sake of efficiency, I recommand you to write your own code,
 * based on the principles behind these codes.
 * But in most cases, these codes perform pretty like I said.
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
const double PI  = acos(-1.0);
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
    void read() {
        scanf("%lf%lf", &x, &y);
    }
    void write() const {
        printf("%lf %lf", x, y);
    }
    bool operator==(const Vector &t) const {
        if (0 == dblcmp(x-t.x) && 0 == dblcmp(y-t.y))
            return true;
        return false;
    }
    Vector operator-(const Vector &t) const {
        return Vector(x-t.x,y-t.y);
    }
    Vector operator+(const Vector &t) const {
        return Vector(x+t.x,y+t.y);
    }
    Vector operator*(double d) const {
        return Vector(d*x,d*y);
    }
    friend Vector operator*(double d, const Vector &v) {
        return v*d;
    }
    Vector operator/(double d) const{
        return *this*(1/d);
    }
} Point;

double length(const Vector &v) { //求向量的模长
    return sqrt(v.x*v.x+v.y*v.y);
}

Vector unit(const Vector &v) { //求单位向量
    return v/length(v);
}

Vector rotate(const Vector &a, double rad) {//求一个向量逆时针旋转后的向量
    return Vector(a.x*cos(rad)-a.y*sin(rad),a.x*sin(rad)+a.y*cos(rad));
}

Vector normal(const Vector &v) {//求向量的单位法向量
    return unit(Vector(-v.y,v.x));
}

Point middle(const Point &a, const Point &b) {//求两点之中点
    return (a+b)/2;
}

double dist(const Point &a, const Point &b) {//求两点之距离
    return length(a-b);
}

double cross(const Vector &a, const Vector &b) {//求两向量之叉积
    return a.x*b.y-b.x*a.y;
}

double dot(const Vector &a, const Vector &b) {//点积
    return a.x*b.x+a.y*b.y;
}

double area2(const Point &l, const Point &r, const Point &p) {  //求三点构成的三角形面积的二倍，
    return cross(r-l,p-l);                                      //前两个点为直线之端点
}

double angle(const Vector &u, const Vector &v) { //求两向量间夹角
    return dot(u,v)/length(u)/length(v);
}

double angle(const Vector &v) { // 求向量与x轴所成夹角
    return atan2(v.y,v.x);
}

Point getLineProjection(const Point &l, const Point &r, const Point &p) { //求点在直线上之投影
    Vector v = r-l;
    return l+v*(dot(v,p-l)/dot(v,v));
}

double p2line(const Point &l, const Point &r, const Point &p) { //求点到直线的距离
    Vector v = r-l;
    double len = length(v);
    if (0 == dblcmp(len))
        return dist(p,l);
    return abs(cross(v,p-l)/len);
}

double p2segment(const Point &l, const Point &r, const Point &p) { //求点到线段的距离
    double len = length(r-l);
    if (dblcmp(len) == 0)
        return length(p-l);
    Vector v1 = r-l, v2 = p-l, v3 = p-r;
    if (dblcmp(dot(v1,v2)) < 0)
        return length(v2);
    if (dblcmp(dot(v1,v3)) > 0)
        return length(v3);
    return abs(cross(v1,v2)/len);
}

bool onLine(const Point &l, const Point &r, const Point &p) { //判断点与直线是否共线
    return (0 == dblcmp(cross(r-l,p-l)));
}

bool checkOnSegment(const Point &l, const Point &r, const Point &p) { //当点与线段共线时，判断点是否在线段上（包括端点）
    return (dblcmp((p.x-l.x)*(p.x-r.x)) <= 0 && dblcmp((p.y-l.y)*(p.y-r.y)) <= 0);
}

bool onSegment(const Point &l, const Point &r, const Point &p) { //判断点是否在线段上（包括端点）
    return (onLine(l,r,p) && checkOnSegment(l,r,p));
}

Point getIntersection(const Point &P, const Point &p, const Point &Q, const Point &q) {//保证两直线相交的情况下，求交点
    Vector u = p-P, v = q-Q, w = P-Q;
    double t = cross(v,w)/cross(u,v);
    return P+u*t;
}

bool isProperIntersect(const Point &a, const Point &b, const Point &c, const Point &d) {//判断两线段是否规范相交ab，cd分别为两直线端点
    int d1 = dblcmp(area2(a,b,c));
    int d2 = dblcmp(area2(a,b,d));
    int d3 = dblcmp(area2(c,d,a));
    int d4 = dblcmp(area2(c,d,b));
    return (d1*d2 < 0 && d3*d4 < 0);
}

bool isIntersect(const Point &a, const Point &b, const Point &c, const Point &d) {//判断两线段是否相交
    int d1 = dblcmp(area2(a,b,c));
    int d2 = dblcmp(area2(a,b,d));
    int d3 = dblcmp(area2(c,d,a));
    int d4 = dblcmp(area2(c,d,b));
    if (d1*d2 < 0 && d3*d4 < 0)
        return true;
    if (0 == d1 && checkOnSegment(a,b,c))
        return true;
    if (0 == d2 && checkOnSegment(a,b,d))
        return true;
    if (0 == d3 && checkOnSegment(c,d,a))
        return true;
    if (0 == d4 && checkOnSegment(c,d,b))
        return true;
    return false;
}

//以下为线段类，和为线段类提供的一些重载函数
typedef struct Segment {
    Point l, r;
} Line;//用两点也能确定一条直线

double length(const Segment &s) {
    return length(s.l-s.r);
}

double angle(const Segment &s, const Segment &t) {
    double d = angle(s.r-s.l,t.r-t.l);
    if (d > PI/2)
        return PI-d;
    return d;
}

Point middle(const Segment &s) {
    return middle(s.l,s.r);
}

double p2line(const Line &l, const Point &p) {
    return p2line(l.l,l.r,p);
}

double p2segment(const Segment &s, const Point &p) {
    return p2segment(s.l,s.r,p);
}

Point getLineProjection(const Line &l, const Point &p) {
    return getLineProjection(l.l,l.r,p);
}

bool checkOnSegment(const Segment &s, const Point &p) {
    return checkOnSegment(s.l,s.r,p);
}

bool onSegment(const Segment &s, const Point &p) {
    return onSegment(s.l,s.r,p);
}

bool isProperIntersect(const Segment &a, const Segment &b) {
    return isProperIntersect(a.l,a.r,b.l,b.r);
}

bool isIntersect(const Segment &a, const Segment &b) {
    return isIntersect(a.l,a.r,b.l,b.r);
}

Point getIntersection(const Line &a, const Line &b) {
    return getIntersection(a.l,a.r,b.l,b.r);
}

// 圆相关的东西
struct Circle {//圆类
    Point c;
    double r;
    Circle(Point c, double r): c(c), r(r) { }
    Point point(double ang) const {//通过圆心角，求圆上一点
        return Point(c.x+r*cos(ang),c.y+r*sin(ang));
    }
};

int relation(const Circle &c, const Point &p) { //判断点与圆关系，1圆外，0圆上，-1圆内
    return dblcmp(dist(c.c,p)-c.r);
}

bool isTangent(const Circle &c, const Line &l) { //判断直线是否与圆相切
    double d = p2line(l,c.c);
    return (0 == dblcmp(d-c.r));
}

bool isIntersect(const Circle &c, const Line &l) { //判断直线是否与圆相交
    double d = p2line(l,c.c);
    return (dblcmp(d-c.r) <= 0);
}

int relation(const Circle &c, const Line &l) { //判断直线与圆关系，1相离，0相切，-1相交
    double d = p2line(l,c.c);
    return dblcmp(d-c.r);
}

int relation(const Circle &a, const Circle &b) { //判断两圆关系，2外离，1内离，0相交，-1内切，-2外切
    double d = dist(a.c,b.c);
    int t = dblcmp(d-a.r-b.r);
    if (t > 1)
        return 2;
    if (0 == t)
        return -2;
    double tmp = fabs(a.r-b.r);
    t = dblcmp(d-tmp);
    if (t > 1)
        return 0;
    if (0 == t)
        return -1;
    return 1;
}

void getIntersection(const Line &l, const Circle &c, vector<Point> &ans) {//求直线与圆交点，ans存储交点
    double d = p2line(l,c.c);
    Point proj = getLineProjection(l,c.c);
    if (0 == dblcmp(d-c.r)) {
        ans.push_back(proj);
        return ;
    }
    double len = sqrt(d*d-c.r*c.r);
    Vector v = unit(l.r-l.l);
    ans.push_back(proj+v*len);
    ans.push_back(proj-v*len);
}

void getIntersection(const Circle &a, const Circle &b, vector<Point> &ans) {//求两圆交点，ans存储交点
    double d = dist(a.c,b.c);
    double ang1 = angle(b.c-a.c);
    double ang2 = acos((a.r*a.r+d*d-b.r*b.r)/(2*a.r*d));
    if (0 == dblcmp(ang2)) {
        ans.push_back(a.point(ang1));
        return ;
    }
    ans.push_back(a.point(ang1-ang2));
    ans.push_back(a.point(ang1+ang2));
}


// 多边形相关
double polygonLen(const Point *poly, int n) { //周长
    double ret = 0;
    for (int i = 0; i < n; ++i)
        ret += dist(poly[i],poly[(i+1)%n]);
    return ret;
}

double polygonArea(const Point *poly, int n) {//多边形面积
    double ret = 0;
    for (int i = 1; i < n-1; ++i)
        ret += area2(poly[0],poly[i],poly[i+1]);
    return ret/2;
}

Point getCentre(const Point *poly, int n) { //对多边形进行三角剖分求重心
    Point ret(0,0);
    double area = 0;
    for (int i = 1; i < n-1; ++i) {
        double t = area2(poly[0],poly[i],poly[i+1]);
        area += t;
        Point pt = (poly[0]+poly[i]+poly[i+1]);
        ret = ret+pt*t;
        ret = ret+(poly[i]+poly[(i+1)%n])*(cross(poly[i],poly[(i+1)%n]));
    }
    ret = ret/(3*area);
    return ret;
}

int onPolygon(const Point *poly, int n, const Point &p) { //判断点与任意多边形的关系，1在内部，0在边上，-1在外部
    int wn = 0;
    for (int i = 0; i < n; ++i) {
        if (onSegment(poly[i],poly[(i+1)%n],p))
            return 0;
        int t = dblcmp(area2(poly[i],poly[(i+1)%n],p));
        int d1 = dblcmp(poly[i].y-p.y);
        int d2 = dblcmp(poly[(i+1)%n].y-p.y);
        if (t > 0 && d1 <= 0 && d2 > 0) ++wn;
        if (t < 0 && d2 <= 0 && d1 > 0) --wn;
    }
    if (wn != 0)
        return 1;
    return -1;
}

bool ptCmp(const Point &a, const Point &b) {//Andrew算法所需的水平序
    if (a.x != b.x)
        return a.x<b.x;
    return a.y<b.y;
}

int andrew(Point *p, int n, Point *ch) { //使用Andrew算法求凸包，ch数组逆时针保存凸包，返回凸包大小
    sort(p, p+n,ptCmp);
    int top = 0;
    for (int i = 0; i < n; ++i) {
        while (top > 1 && dblcmp(area2(ch[top-2],ch[top-1],p[i])) <= 0)
            --top;
        ch[top++] = p[i];
    }
    int k = top;
    for (int i = n-2; i >= 0; --i) {
        while (top>k && dblcmp(area2(ch[top-2],ch[top-1],p[i])) <= 0)
            --top;
        ch[top++] = p[i];
    }
    if (n>1)
        --top;
    return top;
}

double convexDiameter(const Point *ch, int n) { //用旋转卡壳求凸多边形直径
    double ret = 0;
    int j = 1;
    for (int i = 0; i < n; ++i) {
        while (area2(ch[i],ch[(i+1)%n],ch[(j+1)%n]) > area2(ch[i],ch[(i+1)%n],ch[j]))
            j = (j+1)%n;
        ret = max(ret,max(dist(ch[i],ch[j]),dist(ch[(i+1)%n],ch[(j+1)%n])));
    }
    return ret;
}

int onConvex(const Point *ch, int n, const Point &p) { //判断点是否在凸多边形上，1在，0在边上，-1外部
    int ret = 1;
    for (int i = 0; i < n; ++i) {
        int t = dblcmp(area2(ch[i],ch[(i+1)%n],p));
        if (-1 == t)
            return -1;
        if (0 == t)
            ret = 0;
    }
    return ret;
}

const double INF = 1E100;
double compute(const Point *ch, int n) {
    if (1 == n)
        return 0;
    double ret = INF;
    int j = 1, l = 0, r = 0;
    for (int i = 0; i < n; ++i) {
        while (area2(ch[i], ch[(i+1)%n], ch[(j+1)%n]) > area2(ch[i], ch[(i+1)%n], ch[j]))
            j = (j+1)%n;
        l = i, r = j;

        Point proj = getLineProjection(ch[i], ch[(i+1)%n], ch[j]);
        while (area2(ch[j], proj, ch[(l+1)%n]) > area2(ch[j], proj, ch[l]))
            l = (l+1)%n;
        while (area2(proj, ch[j], ch[(r+1)%n]) > area2(proj, ch[j], ch[r]))
            r = (r+1)%n;
        double h = p2line(ch[i], ch[(i+1)%n], ch[j]);
        double w = p2line(ch[j],proj,ch[l])+p2line(ch[j],proj,ch[r]);
        ret = min(ret,h*w);
    }
    return ret;
}
const int MAXN = 1005;
Point pt[MAXN];
Point ch[MAXN];
int n;

int main() {
    while (true) {
        cin >> n;
        if (!n)
            break;
        for (int i = 0; i < n; ++i)
            pt[i].read();
        int m = andrew(pt,n,ch);
        double ans = compute(ch,m);
        printf("%.4lf\n", ans);
    }
    return 0;
}