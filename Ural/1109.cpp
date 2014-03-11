#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
const int MAXN = 1005;
int n, m, k;
bool g[MAXN][MAXN];

void load() {
    scanf("%d%d%d", &n, &m, &k);
    while (k--) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a][b] = true;
    }
}

bool vis[MAXN];
int pal[MAXN];
bool find(int u) {
    for (int v = 1; v <= m; ++v)
        if (g[u][v] && !vis[v]) {
            vis[v] = true;
            if (!pal[v] || find(pal[v])) {
                pal[v] = u;
                return true;
            }
        }
    return false;
}
void work() {
    int ans = n+m;
    for (int i = 1; i <= n; ++i) {
        memset(vis,0,sizeof(vis));
        if (find(i)) {
            --ans;
        }
    }
    printf("%d\n", ans);
}
int main() {
    load();
    work();
    return 0;
}
