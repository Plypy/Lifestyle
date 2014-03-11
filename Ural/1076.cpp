/* 二分图最大权匹配变形
 * 用KM（Kuhn-Munkres)算法求解
 * Note: 该算法只能给可以完美匹配的二分图使用
 * 否则就必须用最小费用最大流了 
 */
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int MAXN = 155;
const int INF = 52111425;
int g[MAXN][MAXN];
int tot[MAXN];
int n;

inline int min(int a, int b) {
    return a<b?a:b;
}
inline int max(int a, int b) {
    return a>b?a:b;
}

void load() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &g[i][j]);
            tot[i] += g[i][j];
        }
}

int lx[MAXN], ly[MAXN];
int pal[MAXN];
bool visx[MAXN], visy[MAXN];
int slack[MAXN];

bool find(int x) {
    visx[x] = true;
    for (int y = 1; y <= n; ++y)
        if (!visy[y]) {
            int t = lx[x]+ly[y]-g[x][y];
            if (0 == t) {
                visy[y] = true;
                if (!pal[y] || find(pal[y])) {
                    pal[y] = x;
                    return true;
                }
            } else
                slack[y] = min(slack[y],t);
        }
    return false;
}

void Kuhn_Munkres() {
    for (int x = 1; x <= n; ++x)
        for (int y = 1; y <= n; ++y)
            lx[x] = max(lx[x],g[x][y]);
    for (int x = 1; x <= n; ++x) {
        for (int y = 1; y <= n; ++y)
            slack[y] = INF;
        while (true) {
            memset(visx,0,sizeof(visx));
            memset(visy,0,sizeof(visy));
            if (find(x))
                break;
            int d = INF;
            for (int y = 1; y <= n; ++y)
                if (!visy[y])
                    d = min(d,slack[y]);
            for (int t = 1; t <= n; ++t)
                if (visx[t])
                    lx[t] -= d;
            for (int y = 1; y <= n; ++y) {
                if (visy[y])
                    ly[y] += d;
                else
                    slack[y] -= d;
            }
        }
    }
}

void work() {
    int ans = 0;
    Kuhn_Munkres();
    for (int i = 1; i <= n; ++i)
        ans += tot[pal[i]]-g[pal[i]][i];
    printf("%d\n", ans);
}

int main() {
    load();
    work();
//    system("pause");
    return 0;
}
