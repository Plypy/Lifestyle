#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int MAXN = 5010;
const double INF = 1e50;
const int MAXD = 10;
struct Point {
    double x, y, z;
} pt[MAXN];

inline double sqr(double t) {
    return t*t;
}

inline double dis(const Point &a, const Point &b) {
    return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)+sqr(a.z-b.z));
}

int ct[MAXD];
int main() {
    int n = 0;
    while (true) {
        scanf("%lf%lf%lf", &pt[n].x, &pt[n].y, &pt[n].z);
        if (0 == pt[n].x && 0 == pt[n].y && 0 == pt[n].z)
            break;
        ++n;
    }
    ++n;
    for (int i = 0; i < n; ++i) {
        double mdis = INF;
        for (int j = 0; j < n; ++j)
            if (i != j)
                mdis = min(mdis,dis(pt[i],pt[j]));
        int t = int(mdis);
        if (t < MAXD)
            ++ct[t];
    }
    for (int i = 0; i < MAXD; ++i)
        printf("%4d", ct[i]);
    printf("\n");
//    system("pause");
    return 0;
}
