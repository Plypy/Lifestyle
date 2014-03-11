//×î¶ÌÂ·+dp 
#include <iostream>
#include <cstdlib>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 110;
const int MAXM = 25;
const int INF = 52111425;
int g[MAXM][MAXM];
int banned[MAXM][MAXN];
int n, m, mcost;
inline int min(int a, int b) {
    return a<b?a:b;
}
void load() {
    int e;
    scanf("%d%d%d%d",&n,&m,&mcost,&e);
    for (int i = 1; i < m; ++i)
        for (int j = i+1; j <= m; ++j)
            g[i][j] = g[j][i] = INF;
    int a, b, c;
    while (e--) {
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = g[b][a] = min(g[a][b],c);
    }
    scanf("%d", &e);
    while (e--) {
        scanf("%d%d%d", &a, &b, &c);
        for (int i = b; i <= c; ++i)
            banned[a][i] = true;
    }
}
bool used[MAXM];
int cost[MAXN][MAXN];
int dis[MAXM];
bool inq[MAXM];
int f[MAXN];
void spfa(int st, int ed) {
    for (int i = 2; i <= m; ++i)
        dis[i] = INF;
    queue<int> que;
    que.push(1);
    inq[1] = true;
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (int v = 1; v <= m; ++v)
            if (!used[v] && dis[v]>dis[u]+g[u][v]) {
                dis[v] = dis[u]+g[u][v];
                if (!inq[v]) {
                    inq[v] = true;
                    que.push(v);
                }
            }
        inq[u] = false;
    }
    if (dis[m] == INF)
        cost[st][ed] = INF;
    else
        cost[st][ed] = dis[m]*(ed-st+1);
}
void work() {
    for (int i = 1; i <= n; ++i) {
        memset(used,0,sizeof(used));
        for (int j = i; j <= n; ++j) {
            for (int k = 1; k <= m; ++k)
                used[k] = used[k]|banned[k][j];
            spfa(i,j);
        }
    }
    for (int i = 1; i <= n; ++i) {
        f[i] = cost[1][i];
        for (int j = 1; j < i; ++j)
            f[i] = min(f[i],f[j]+cost[j+1][i]+mcost);
    }
    printf("%d\n", f[n]);
//    system("pause");
}
int main() {
    load();
    work();
    return 0;
}
