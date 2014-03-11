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
    Edge(int a = 0, int b = 0, Edge *c = 0):
        vtx(a), id(b), nxt(c) { }
} epool[MAXE], *eptr = epool, *adj[MAXV];

void add(int u, int v, int id) {
    adj[u] = new (eptr++) Edge(v,id,adj[u]);
    adj[v] = new (eptr++) Edge(u,id,adj[v]);
}
int dfn[MAXV], low[MAXV], ct;
bool visv[MAXV], vise[MAXE];
int ans[MAXE], act;
void init() {
    vs = vt = 0;
    memset(adj,0,sizeof(adj));
    eptr = epool;
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(visv,0,sizeof(visv));
    memset(vise,0,sizeof(vise));
    memset(ans,0,sizeof(ans));
    act = ct = 0;
}
bool tarjan(int u) {
    bool ret = false;
    visv[u] = true;
    if (vt == u) {
        ret = true;
    }
    low[u] = dfn[u] = ++ct;
    for (Edge *t = adj[u]; t; t = t->nxt) {
        int v = t->vtx;
        int id = t->id;
        bool flag = false;
        if (!vise[id] && !visv[v]) {
            vise[id] = true;
            if (tarjan(v))
                flag = ret = true;
            low[u] = min(low[u],low[v]);
        } else if (!vise[id]) {
            low[u] = min(low[u],dfn[v]);
        }
        if (low[v] > dfn[u] && flag)
            ans[++act] = id;
    }
    return ret;
}
int n, m;
int main() {
    while (2 == scanf("%d%d", &n, &m)) {
        init();
        int a, b;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &a, &b);
            ++a, ++b;
            add(a,b,i);
        }
        vs = 1, vt = n;
        tarjan(vs);

        sort(ans+1,ans+act+1);
        printf("%d\n", act);
        for (int i = 1; i <= act; ++i) {
            if (i > 1)
                putchar(' ');
            printf("%d", ans[i]);
        }
        puts("");
    }
    return 0;
}
