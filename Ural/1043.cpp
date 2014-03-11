/**
 * Description: Given an arc, find a rectangle with minimum area, which vertices' coordinates are integers.
 * And all items must in the given field.
 * Source: Ural1043
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

const double PI = M_PI;
const double eps = 1e-8;
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

Point intersection(const Point &P, const Vector &u, const Point &Q, const Vector &v) {
	Vector w = P-Q;
	double t = cross(v,w)/cross(u,v);
	return P+u*t;
}

Point mid(const Point &a, const Point &b) {
	return 0.5*(a+b);
}
Vector rotate(const Vector &a, double ang) {
	return Vector(a.x*cos(ang)-a.y*sin(ang),a.x*sin(ang)+a.y*cos(ang));
}
Point getCentre(const Point &a, const Point &b, const Point &c) {
	Point m1 = mid(a,b);
	Point v1 = rotate(b-a,PI/2);
	Point m2 = mid(b,c);
	Point v2 = rotate(c-b,PI/2);

	return intersection(m1,v1,m2,v2);
}
double getAng(const Point &cen, const Point &p) {
	Vector v = p-cen;
	return atan2(p.y,p.x);
}
const double LB = -1000, RB = 1000, UB = 1000, DB = -1000;
Point centre;
double radius;
Point l, r, m;
double mleft, mright, upper, lower;

int main() {
	cin >> l >> r >> m;
	if (l.x > r.x)
		swap(l,r);
	centre = getCentre(l,r,m);
	double radius = dist(l,centre);
	bool side = notRight(l,r,m);
	mleft = l.x, mright = r.x;
	lower = min(l.y,r.y), upper = max(l.y,r.y);
	Point tmp = Point(centre.x-radius,centre.y);
	if (side == notRight(l,r,tmp)) {
		mleft = max(LB,tmp.x);
		mleft = floor(mleft+eps);
	}
	tmp = Point(centre.x,centre.y-radius);
	if (side == notRight(l,r,tmp)) {
		lower = max(DB,tmp.y);
		lower = floor(lower+eps);
	}
	tmp = Point(centre.x+radius,centre.y);
	if (side == notRight(l,r,tmp)) {
		mright = min(RB,tmp.x);
		mright = ceil(mright-eps);
	}
	tmp = Point(centre.x,centre.y+radius);
	if (side == notRight(l,r,tmp)) {
		upper = min(UB,tmp.y);
		upper = ceil(upper-eps);
	}
	int ans = (mright-mleft)*(upper-lower);
	cout << ans << endl;
	return 0;
}