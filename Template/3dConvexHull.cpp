/**
 * Description: This algo havn't considered the situation of 4 points in one plane.
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

#define MAXN 1005
#define px first
#define py second.first
#define pz second.second
#define mp(x,y) make_pair((x), (y))

typedef pair<int, int> pi;
typedef pair<int, pi> pii;
struct Point {
    double x, y, z;
    Point() {}
    Point(double a, double b, double c): x(a), y(b), z(c) {}
};
Point operator-(const Point &a, const Point &b) {
    return Point(a.x-b.x,a.y-b.y,a.z-b.z);
}
double dot(const Point &a, const Point &b) {
    return a.x*b.x+a.y*b.y+a.z*b.z;
}
Point cross(const Point &a, const Point &b) {
    return Point(a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x);
}
double volume(const Point &a, const Point &b, const Point &c, const Point &d) {
    return dot(cross(b-a, c-a),d-a);
}
set<pi> edges;
vector<pii> faces;
Point pt[MAXN];
int n;
void wrap(int a, int b) {
    if (0 == edges.count(mp(a, b))) {
        int c = -1;
        for (int i = 0; i < n; ++i)
            if (i != a && i != b) {
                if (c == -1 || volume(pt[c],pt[a],pt[b],pt[i]) > 0)
                    c = i;
            }
        if (-1 != c) {
            faces.push_back(mp(a, mp(b, c)));
            edges.insert(mp(a, b));
            edges.insert(mp(b, c));
            edges.insert(mp(c, a));
            wrap(c,b);
            wrap(a,c);
        }
    }
}
double length(const Point &a) {
    return sqrt(dot(a,a));
}
double dis(const Point &p, const Point &q) {
    return length(p-q);
}
double area(const Point &a, const Point &b, const Point &c) {
    return length(cross(b-a, c-a))/2;
}
// double area(const Point &p, const Point &q, const Point &r) {
//     double a=dis(p,q), b=dis(p,r), c=dis(q,r), t=(a+b+c)/2;
//     return sqrt(t*(t-a)*(t-b)*(t-c));
// }
// void write(int pos) {
//     cout << pt[pos].x << ' ' << pt[pos].y << ' ' << pt[pos].z << endl;
// }
double ans = 0;
int main(int argc, char const *argv[]) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%lf%lf%lf", &pt[i].x, &pt[i].y, &pt[i].z);
    for (int i = 1; i < n; ++i)
        if (pt[i].x < pt[0].x)
            swap(pt[i],pt[0]);
    for (int i = 2; i < n; ++i)
        if ((pt[i].x-pt[0].x)*(pt[1].y-pt[0].y) > (pt[i].y-pt[0].y)*(pt[1].x-pt[0].x))
            swap(pt[i],pt[1]);
    // write(0);
    // write(1);
    wrap(0,1);
    for (int i = 0; i < faces.size(); ++i)
        ans += area(pt[faces[i].px], pt[faces[i].py], pt[faces[i].pz]);
    printf("%.3lf\n", ans);
    return 0;
}