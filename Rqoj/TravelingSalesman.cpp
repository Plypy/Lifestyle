/*
 * 欧几里德旅行商问题简化版
 * 设状态f[i][j]为走得快的那个人走到i走得慢的那个人走到[j]时的最短路径 
 * sort默认由小到大排序 
 */
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <ctime>
using namespace std;
class Problem {
private:
    static const int MAXN = 1010;
    static const double INF = 1e30;
    struct point {
        double x, y;
        friend bool operator<(const point &a, const point &b) {
            return a.x<b.x;
        }
    } pt[MAXN];
    inline double min(double a, double b) {
        return a<b?a:b;
    }
    int n;
    double f[MAXN][MAXN];
    double dist[MAXN][MAXN];
public:
    void load() {
        scanf("%d", &n);
        double tx, ty;
        for (int i = 1; i <= n; ++i) {
            scanf("%lf%lf", &tx, &ty);
            pt[i].x = tx;
            pt[i].y = ty;
        }
    }
    void work() {
        sort(pt+1,pt+n+1);
        for (int i = 2; i <= n; ++i)
            for (int j = 1; j <= i; ++j)
                f[i][j] = INF;
        for (int i = 1; i < n; ++i)
            for (int j = i+1; j <= n; ++j)
                dist[i][j] = hypot(pt[i].x-pt[j].x,pt[i].y-pt[j].y);
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                f[i][j] = min(f[i][j],f[i-1][j]+dist[i-1][i]);
                f[i][i-1] = min(f[i][i-1], f[i-1][j]+dist[j][i]);
            }
        }
        double ans = INF;
        for (int i = 1; i < n; ++i)
            ans = min(ans, f[n][i]+dist[i][n]);
        printf("%.2f\n", ans);
//        system("pause");
    }
    int run() {
        load();
        work();
        return 0;
    }
} prob;
int main() {
    return prob.run();
}
