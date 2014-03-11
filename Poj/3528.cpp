/**
 * Description: 3-d convex hull, using package wrapping method
 * Source: poj 3528
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
const int MAXN = 1005;
typedef pair<int,int> pi;
typedef pair<int ,pi> pii;
struct Point {
    double x, y, z;
    Point() {}
    Point(double a, double b, double c): x(a), y(b), z(c) {}
};
Point operator-(const Point &a, const Point &b) {
    return Point(a.x-b.x,a.y-b.y,a.z-b.z);
}
double operator*(const Point &a, const Point &b) {
    return a.x*b.x+a.y*b.y+a.z*b.z;
}
Point operator^(const Point &a, const Point &b) {
    return Point(a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x);
}
double volume(const Point &a, const Point &b, const Point &c, const Point &d) {
    return ((b-a)^(c-a))*(d-a);
}
set<pi> Set;
vector<pii> faces;
Point p[MAXN];
int n;
void wrap(int a, int b) {
    if (Set.find(make_pair(a,b)) == Set.end()) {
        int c = -1;
        for (int i = 0; i < n; ++i) if (i != a && i != b) {
            if (c == -1 || volume(p[c], p[a], p[b], p[i])>0)
                c = i;
        }
        if (c != -1) {
            faces.push_back(make_pair(a,make_pair(b,c)));
            Set.insert(make_pair(a,b));
            Set.insert(make_pair(b,c));
            Set.insert(make_pair(c,a));
            wrap(c,b);
            wrap(a,c);
        }
    }
}

double sqr(double x) {
    return x*x;
}
double dis(const Point &p, const Point &q) {
    return sqrt(sqr(p.x-q.x)+sqr(p.y-q.y)+sqr(p.z-q.z));
}
double area(const Point &p, const Point &q, const Point &r) {
    double a=dis(p,q), b=dis(p,r), c=dis(q,r), t=(a+b+c)/2;
    return sqrt(t*(t-a)*(t-b)*(t-c));
}
// void write(int pos) {
//     cout << p[pos].x << ' ' << p[pos].y << ' ' << p[pos].z << endl;
// }
double ans;
int main(int argc, char const *argv[]) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%lf%lf%lf", &p[i].x, &p[i].y, &p[i].z);
    for (int i = 1; i < n; ++i)
        if (p[i].x<p[0].x)
            swap(p[0],p[i]);
    for (int i = 2; i < n; ++i)
        if ((p[i].x-p[0].x)*(p[1].y-p[0].y) > (p[i].y-p[0].y)*(p[1].x-p[0].x))
            swap(p[1],p[i]);
    // write(0);
    // write(1);
    wrap(0,1);
    ans = 0;
    for (int i = 0; i < faces.size(); ++i)
        ans += area(p[faces[i].first],p[faces[i].second.first],p[faces[i].second.second]);
    printf("%.3lf\n", ans);
    return 0;
}