//未完成
//check部分应该使用先求两圆交点，再求交点是否在另一圆内的方法
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
const double eps = 1e-8;
struct Point {
    double x, y;
} c, s, h;
double dis(Point &a, Point &b) {
    return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}
double t1, t2;
double dcs, dch, dsh;
void load() {
    cin >> t1 >> t2;
    cin >> c.x >> c.y;
    cin >> h.x >> h.y;
    cin >> s.x >> s.y;
    dcs = dis(c,s);
    dch = dis(c,h);
    dsh = dis(s,h);
}

bool check(double r) {
    double r1 = dcs+t1-r;
    double r2 = dch+t2-r;
    if (dsh > r1+r2) {
        return false;
    }
    Point a, b;
    a.x = ; a.y = ;
    b.x = ; b.y = ;
}
void work() {
    if (dcs+dsh <= dch+t2) {
        cout << min(dcs+dsh+t1,dch+t2) << endl;
        return ;
    }
    double l = 0, r = min(dcs+dsh+t1,dch+t2);
    double mid = 0;
    while (r-l > eps) {
        mid = (r+l)/2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    cout << r << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(8);
    load();
    work();
    return 0;
}
