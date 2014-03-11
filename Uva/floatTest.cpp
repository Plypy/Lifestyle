/**
 * Description:
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

typedef struct Point
{
    double x, y;
    Point(double x = 0, double y = 0): x(x), y(y) { }
    friend istream &operator>>(istream &is, Point &t) {
        is >> t.x >> t.y;
        return is;
    }
    friend ostream &operator<<(ostream &os, const Point &t) {
        os << t.x << ' ' <<  t.y;
        return os;
    }
} Vector;
Point operator*(const Point &t, double mult) {
    return Point(t.x*mult,t.y*mult);
}
Point operator*(double mult, const Point &t) {
    return t*mult;
}
Point operator-(const Point &a, const Point &b) {
    return Point(a.x-b.x,a.y-b.y);
}
Point operator+(const Point &a, const Point &b) {
    return Point(a.x+b.x,a.y+b.y);
}
double cross(const Vector &a, const Vector &b) {
    return a.x*b.y-a.y*b.x;
}
double area2(const Point &l, const Point &r, const Point &p) {
    return cross(r-l,p-l);
}
bool notRight(const Point &l, const Point &r, const Point &p) {
    return area2(l,r,p)>=0;
}
double norm(const Vector &v) {
    return sqrt(v.x*v.x+v.y*v.y);
}
double dist(const Point &a, const Point &b) {
    return norm(b-a);
}

typedef struct Vector {
    double x, y;
    Vector(double x=0,double y=0): x(x), y(y) { }
} Point; //因为点和向量差不多，两点相减能得一向量，所以就起个别名

Point operator+(const Vector &a, const Vector &b) {//加法
    return Vector(a.x+b.x,a.y+b.y);
}

Point operator-(const Vector &a, const Vector &b) {//减法
    return Vector(a.x-b.x,a.y-b.y);
}

const double eps = 1e-10;
int dblcmp(double d) {
    if (fabs(d) < eps)
        return 0;
    return (d>0)?1:-1;
}