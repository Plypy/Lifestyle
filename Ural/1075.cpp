/**
 * Description: Simple geomtry problem, given a sphere and two points outside this sphere
 * find a curve with minimum length connects these two points and not cross over the sphere
 * Source: Ural 1075
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
	double x, y, z;
	Point(double x = 0, double y = 0, double z = 0): x(x), y(y), z(z) { }
	friend istream &operator>>(istream &is, Point &t) {
		is >> t.x >> t.y >> t.z;
		return is;
	}
	friend ostream &operator<<(ostream &os, const Point &t) {
		os << t.x << ' ' <<  t.y << ' ' << t.z;
		return os;
	}
} Vector;
Point operator-(const Point &a, const Point &b) {
	return Point(a.x-b.x,a.y-b.y,a.z-b.z);
}
double norm(const Vector &v) {
	return sqrt(v.x*v.x+v.y*v.y+v.z*v.z);
}
double cross(const Vector &a, const Vector &b) {
	return norm(Point(a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x));
}
double dot(const Vector &a, const Vector &b) {
	return a.x*b.x+a.y*b.y+a.z*b.z;
}
double area2(const Point &l, const Point &r, const Point &p) {
	return cross(r-l,p-l);
}
double dist(const Point &a, const Point &b) {
	return norm(b-a);
}
double p2line(const Point &l, const Point &r, const Point &p) {
	double len = norm(l-r);
	if (0 == len)
		return norm(p-l);
	Vector v1 = r-l, v2 = p-l, v3 = p-r;
	if (dot(v1,v2) < 0)
		return norm(v2);
	if (dot(v1,v3) > 0)
		return norm(v3);
	return abs(area2(l,r,p)/len);
}

Point a, b, c;
double radius;
int main() {
	cin >> a >> b >> c;
	cin >> radius;
	double dab = dist(a,b);
	double dac = dist(a,c);
	double dbc = dist(b,c);
	double dpc = p2line(a,b,c);

	double ans = 0;
	if (dpc >= radius) {
		ans = dab;
	} else {
		double l1 = sqrt(dac*dac-radius*radius);
		double l2 = sqrt(dbc*dbc-radius*radius);
		double ang1 = acos(radius/dac);
		double ang2 = acos(radius/dbc);
		double tang = acos(dot(b-c,a-c)/(norm(b-c)*norm(a-c)));
		double ang3 = tang-ang1-ang2;
		double l3 = radius*ang3;
		ans = l1+l2+l3;
	}
	cout << fixed << setprecision(6);
	cout << ans << endl;
	return 0;
}