/**
 * Description:
 * ProblemName:
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

const int MAXN = 105;
int T;
int n, m;
int mat[MAXN][MAXN];

void load() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int *adr = n<=m? (&mat[i][j]) : (&mat[j][i]);
            scanf("%d", adr);
        }
    }
    if (n > m)
        swap(n,m);
    for (int i = 1; i <= m; ++i) {
        int minc = mat[1][i];
        for (int j = 2; j <= n; ++j)
            minc = min(minc, mat[j][i]);
        for (int j = n+1; j <= m; ++j) {
            mat[j][i] = minc;
        }
    }
}

const int INF = 0x3f3f3f3f;
int N;
int g[MAXN][MAXN];
int lx[MAXN], ly[MAXN];
int pal[MAXN];
bool visx[MAXN], visy[MAXN];
int slack[MAXN];
void init() {
    memset(g,0,sizeof(g));
    memset(lx,0,sizeof(lx));
    memset(ly,0,sizeof(ly));
    memset(pal,0,sizeof(pal));
    memset(visx,0,sizeof(visx));
    memset(visy,0,sizeof(visy));
    memset(slack,0,sizeof(slack));
}
bool find(int x) {
    visx[x] = true;
    for (int y = 1; y <= N; ++y) {
        if (!visy[y]) {
            int t = lx[x]+ly[y]-g[x][y];
            if (0 == t) {
                visy[y] = true;
                if (!pal[y] || find(pal[y])) {
                    pal[y] = x;
                    return true;
                }
            } else {
                slack[y] = min(slack[y],t);
            }
        }
    }
    return false;
}

void KM() {
    for (int x = 1; x <= N; ++x) {
        for (int y = 1; y <= N; ++y) {
            lx[x] = max(lx[x],g[x][y]);
        }
    }
    for (int x = 1; x <= N; ++x) {
        for (int y = 1; y <= N; ++y) {
            slack[y] = INF;
        }
        while (true) {
            memset(visx,0,sizeof(visx));
            memset(visy,0,sizeof(visy));

            if (find(x))
                break;
            int d = INF;
            for (int y = 1; y <= N; ++y) {
                if (!visy[y])
                    d = min(d,slack[y]);
            }

            for (int t = 1; t <= N; ++t) {
                if (visx[t])
                    lx[t] -= d;
            }

            for (int y = 1; y <= N; ++y) {
                if (visy[y])
                    ly[y] += d;
                else
                    slack[y] -= d;
            }
        }
    }
}
int work() {
    N = m;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j) {
            g[i][j] = -mat[i][j];
        }
    KM();
    int ret = 0;
    for (int i = 1; i <= N; ++i) {
        ret -= g[pal[i]][i];
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        init();
        load();
        printf("Case %d: %d\n", i, work());
    }
    return 0;
}