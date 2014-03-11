#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXR = 105, MAXC = 105;
const int MAXN = 105;
const int INF = 1<<28;
int g[MAXN][MAXN];
int n;
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

int KM() {
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
    int ret = 0;
    for (int y = 1; y <= n; ++y)
        ret += g[pal[y]][y];
    return ret;
}
void init() {
    memset(pal,0,sizeof(pal));
    memset(lx,0,sizeof(lx));
    memset(ly,0,sizeof(ly));
}
int r, c;
int r1[MAXN], c1[MAXN];
int r2[MAXN], c2[MAXN];
bool load() {
    scanf("%d%d", &r, &c);
    if (0 == r && 0 == c)
        return false;
    int ct1 = 0, ct2 = 0;
    for (int i = 1; i <= r; ++i) {
        getchar();
        for (int j = 1; j <= c; ++j) {
            char ch = getchar();
            if ('H' == ch) {
                r2[++ct2] = i;
                c2[ct2] = j;
            } else if ('m' == ch) {
                r1[++ct1] = i;
                c1[ct1] = j;
            }
        }
    }
    n = ct1;
    return true;
}
void work() {
    for (int i = 1; i <= n; ++i)
        for (int j =1; j <= n; ++j)
            g[i][j] = -(abs(r1[i]-r2[j])+abs(c1[i]-c2[j]));
    printf("%d\n", -KM());
}
int main() {
    while (load()) {
        work();
        init();
    }
    return 0;
}
