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

inline double sqr(double a) {
    return a*a;
}
const double eps = 1e-5;
struct Point {
    double x, y;
    Point():x(0), y(0) {}
    Point(double a, double b): x(a), y(b) { }
    void read() {
        scanf("%lf%lf", &x, &y);
    }
} ;
double dis(const Point &a, const Point &b) {
    return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}
const int MAXN = 1005;
Point pt[MAXN];
int n;
double eval(const Point &p) {
    double ret = 0;
    for (int i = 1; i <= n; ++i)
        ret = max(ret,dis(p,pt[i]));
    return ret;
}
double mlen;
Point G;
double D;
bool load() {
    if (EOF == scanf("%lf%lf%lf", &G.x, &G.y, &D))
        return false;

    scanf("%d", &n);
    mlen = 0;
    for (int i = 1; i <= n; ++i) {
        pt[i].read();
        mlen = max(mlen, dis(pt[i],G));
    }
    return true;
}
void work()
{
    double t = mlen;//初始温度，可以看作是搜索半径
    Point ip(G.x,G.y);
    double ans = eval(ip);
    while (t > eps) {
        double nans = INF;
        Point np;
        for (int i = 0; i < 50; ++i) {
            double dx = t*(double(rand())/double(RAND_MAX))*(2*(rand()%2)-1);
            double dy = sqrt(sqr(t)-sqr(dx))*(2*(rand()%2)-1)+iy;
        }
    }
}

int main(int argc, char const *argv[]) {
    srand(time(0));
    while (load()) {
        work();
    }
    return 0;
}