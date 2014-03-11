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


const int MAXN = 1005;
typedef pair<double,double> point;
#define x first
#define y second
double sqr(double a) {
    return a*a;
}
double dis(point a, point b) {
    return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}
point pt[MAXN];
double dsum[MAXN];
int n;
bool load() {
    if (EOF == scanf("%d", &n))
        return false;
    n <<= 1;
    for (int i = 1; i <= n; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        pt[i].x = a, pt[i].y = b;
    }
    return true;
}

void work() {
    memset(dsum,0,sizeof(dsum));
    double tot = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = i+1; j <= n; ++j) {
            double tmp = dis(pt[i],pt[j]);
            tot += tmp;
            dsum[i] += tmp;
            dsum[j] += tmp;
        }
    sort(dsum+1,dsum+1+n);
    double sub = 0;
    for (int i = 1; i <= n; i += 2)
        sub += dsum[i];
    double ans = tot-sub;
    printf("%.3lf\n", ans);
}

int main(int argc, char const *argv[]) {
    while (load()) {
        work();
    }
    return 0;
}