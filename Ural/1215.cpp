/**
 * Description:
 * Author: Ply_py
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iomanip>
#include <queue>
#include <cmath>
using namespace std;

const int MAXN = 105;
int n;

typedef struct Vector {
	double x, y;
	Vector(double x = 0, double y = 0):x(x), y(y) { }
	Vector operator-(const Vector &a) const {
		return Vector(x-a.x,y-a.y);
	}
} Point;
double cross(const Vector &a, const Vector &b) {
	return a.x*b.y-a.y*b.x;
}
double dot(const Vector &a, const Vector &b) {
	return a.x*b.x+a.y*b.y;
}
double area2(const Point &a, const Point &b, const Point &c) {
	return cross(b-a,c-a);
}
double norm(const Vector &t) {
	return sqrt(t.x*t.x+t.y*t.y);
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
double isRight(const Point &l, const Point &r, const Point &p) {
	return area2(l,r,p)<0;
}
typedef vector<Point> Polygon;
bool inPoly(const Polygon &a, const Point &p) {
	int len = a.size();
	for (int i = 0; i < len; ++i) {
		if (isRight(a[i],a[(i+1)%len],p))
			return false;
	}
	return true;
}
Point p;
Polygon poly;
void load() {
	cin >> p.x >> p.y;	
	cin >> n;
	double x, y;
	for (int i = 1; i <= n; ++i) {
		cin >> x >> y;
		poly.push_back(Point(x,y));
	}
}

void work() {
	if (inPoly(poly,p)) {
		cout << 0.0 << endl;
	} else {
		double ans = 10000000;
		for (int i = 0; i < n; ++i) {
			ans = min(ans,p2line(poly[i],poly[(i+1)%n],p));
		}
		ans *= 2;
		cout << ans << endl;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(4);
	load();
	work();
	return 0;
}
