//还是脑残错误，程序框架还有具体的小细节一开始并没有想好，
//在实现的过程中处理这些问题就带来了一些麻烦
//导致编程效率低下
#include <queue>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
const int INF = 1<<28;
const int MAXN = 1005;
int f[MAXN], b[MAXN];
int dest;
int n;

int dis[MAXN];
int pre[MAXN];
int ans = INF;;
int dend = -1;
void bfs(int st) {
    int tans =  INF;
    int tpre[MAXN] = {0};
    int tend = -1;
    memset(dis,-1,sizeof(dis));
    dis[0] = 0;
    queue<int> que;
    que.push(0);
    dis[0] = 0;
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (int v = 1; v <= n; ++v)
            if (-1 == dis[v] && f[v] == b[u]) {
                que.push(v);
                dis[v] = dis[u]+1;
                tpre[v] = u;
                if (b[v] == dest && -1 == tend) {
                    tend = v;
                    tans = dis[v];
                }
            }
    }
    if (tans < ans) {
        ans = tans;
        dend = tend;
        memcpy(pre,tpre,sizeof(pre));
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", f+i, b+i);
    scanf("%d%d%d", &dest, f, b);
    bfs(0);
    swap(f[0],b[0]);
    bfs(0);
    if (ans != INF) {
        printf("%d\n", ans);
        int anslist[MAXN] = {0};
        for (int t = dend; t; t = pre[t])
            anslist[++anslist[0]] = t;
        for (int i = anslist[0]; i; --i)
            printf("%d\n", anslist[i]);
        puts("");
    } else {
        printf("IMPOSSIBLE\n");
    }
    return 0;
}
