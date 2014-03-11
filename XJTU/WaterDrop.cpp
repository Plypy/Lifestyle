#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 105;
int n;
struct Vector {
    int x, y;
    Vector(int ix = 0, int iy = 0): x(ix), y(iy) { }
    int operator*(const Vector &t) const{
        return x*t.y-t.x*y;
    }
} ;
struct Point {
    int x, y;
    Point(int ix = 0, int iy = 0): x(ix), y(iy) { }
    Vector operator-(const Point &t) const{
        return Vector(x-t.x,y-t.y);
    }
} pt[MAXN][3];
bool isup(const Point &t, int i) {
    if (pt[i][0].x <= t.x && t.x <= pt[i][1].x && (pt[i][1]-pt[i][0])*(t-pt[i][1]) > 0)
        return true;
    if (pt[i][0].x < t.x && t.x < pt[i][1].x && (pt[i][1]-pt[i][0])*(t-pt[i][1]) >= 0)
        return true;
    return false;
}
double dis(const Point &t, int i) {
    double x1 = pt[i][0].x, y1 = pt[i][0].y, x2 = pt[i][1].x, y2 = pt[i][1].y;
    double yonline = ((y1-y2)*t.x+x1*y2-x2*y1)/(x1-x2);
    return t.y-yonline;
}
Point find(const Point &t) {
    int mem = 0;
    for (int i = 1; i <= n; ++i)
        if (isup(t,i)) {
            if (!mem)
                mem = i;
            else if (dis(t,mem) > dis(t,i))
                mem = i;
        }
    if (mem) {
        return pt[mem][2];
    } else
        return Point(t.x,0);
}
int main() {
    cin >> n;
    int x1, y1, x2, y2;
    for (int i = 1; i <= n; ++i) {
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2) {
            swap(x1,x2);
            swap(y1,y2);
        }
        pt[i][0] = Point(x1,y1);
        pt[i][1] = Point(x2,y2);
        if (y1 < y2)
            pt[i][2] = pt[i][0];
        else
            pt[i][2] = pt[i][1];
    }
    int m;
    cin >> m;
    while (m--) {
        Point t, tmp;
        cin >> t.x >> t.y;
        while (true) {
            tmp = find(t);
            if (!tmp.y)
                break;
            t = tmp;
        }
        cout << tmp.x << endl;
    }
    return 0;
}
