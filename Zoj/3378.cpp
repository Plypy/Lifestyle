/**
 * Author: Ply_py
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iomanip>
#include <queue>
using namespace std;

const int MAXN = 10005;
const int MAXM = 100005;

const int MAXV = MAXN;
const int MAXE = MAXM*2;
int vs, vt;
struct Edge {
    int vtx;
    int id;
    Edge *nxt;
    Edge(int v = 0, int d = 0, Edge *n = 0):
        vtx(v), id (d), nxt(n) { }
} epool[MAXE], *adj[MAXV], *eptr = epool;


void add(int u, int v, int id) {
    adj[u] = new (eptr++) Edge(v,id,adj[u]);
    adj[v] = new (eptr++) Edge(u,id,adj[v]);
}
int n, m;
int dfn[MAXV], low[MAXV];
bool vis[MAXE];
int ans[MAXE];
int num, idx;
void init() {
    memset(adj,0,sizeof(adj));
    eptr = epool;
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(vis,0,sizeof(vis));
    memset(ans,0,sizeof(ans));
    num = idx = 0;
}
bool tarjan(int u) {
    bool ret = false;
    if (vt == u)
        ret = true;
    dfn[u] = low[u] = ++idx;
    for (Edge *t = adj[u]; t; t = t->nxt) {
        int v = t->vtx;
        int id = t->id;
        bool flag = false;
        if (!vis[id] && !dfn[v]) {
            vis[id] = true;
            if (tarjan(v))
                ret = flag = true;
            low[u] = min(low[u],low[v]);
        } else if (!vis[id])
            low[u] = min(low[u],dfn[v]);
        if (low[v] > dfn[u] && flag)
            ans[++num] = id;
    }
    return ret;
}

bool load() {
    init();
    if (2 != scanf("%d%d", &n, &m))
        return false;
    vs = 1, vt = n;
    for (int i = 1; i <= m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a == b)
            continue;
        add(a+1,b+1,i-1);
    }
    return true;
}
void work() {
    tarjan(vs);
    sort(ans+1,ans+num+1);
    printf("%d\n", num);
    for (int i = 1; i <= num; ++i) {
        if (i > 1)
            putchar(' ');
        printf("%d", ans[i]);
    }
    puts("");
}
int main() {
    while (load()) {
        work();
    }
    return 0;
}
