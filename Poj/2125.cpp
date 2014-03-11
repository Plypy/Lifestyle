//二分图的最小点权覆盖集
//转换成最小割模型，使用最大流求解
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;

const int MAXN = 105;
const int MAXM = 5005;
const int INF = 1<<28;
int n, m;

const int MAXV = MAXN*2;
const int MAXE = MAXM*2+MAXV*4;

struct Edge {
    int vtx, cap;
    Edge *nxt, *rev;
    Edge() { }
    Edge(int iv, int ic, Edge *in, Edge *ir):
        vtx(iv), cap(ic), nxt(in), rev(ir) { }
} epool[MAXE], *adj[MAXV];
Edge *eptr = epool;
int vs, vt, vtot;
void add(int u, int v, int cap) {
    adj[u] = new (eptr++) Edge(v,cap,adj[u],eptr);
    adj[v] = new (eptr++) Edge(u,0,adj[v],eptr-2);
}

bool vis[MAXV];
void dfs(int u) {
    vis[u] = true;
    for (Edge *t = adj[u]; t; t = t->nxt)
        if (t->cap && !vis[t->vtx])
            dfs(t->vtx);
}

int ht[MAXV];
int hct[MAXV];
int aug(int u, int augc) {
    if (vt == u)
        return augc;
    int rem = augc;
    int minht = vtot-1;
    for (Edge *t = adj[u]; t; t = t->nxt) {
        if (t->cap) {
            int v = t->vtx;
            if (ht[v]+1 == ht[u]) {
                int d = aug(v,min(rem,t->cap));
                rem -= d;
                t->cap -= d;
                t->rev->cap += d;
                if (!rem)
                    return augc;
                if (ht[vs] >= vtot)
                    return augc-rem;
            }
            minht = min(minht,ht[v]);
        }
    }
    if (rem == augc) {
        --hct[ht[u]];
        if (!hct[ht[u]])
            ht[vs] = vtot;
        ht[u] = minht+1;
        ++hct[ht[u]];
    }
    return augc-rem;
}
int sap() {
    int ret = 0;
    hct[0] = vtot;
    while (ht[vs] < vtot)
        ret += aug(vs,INF);
    return ret;
}

void load() {
    scanf("%d%d", &n, &m);
    vs = 0;
    vt = 2*n+1;
    vtot = vt+1;
    for (int i = 1; i <= n; ++i) {
        int t;
        scanf("%d", &t);
        add(i+n,vt,t);
    }
    for (int i = 1; i <= n; ++i) {
        int t;
        scanf("%d", &t);
        add(vs,i,t);
    }
    for (int i = 1; i <= m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a,b+n,INF);
    }
}

int moves = 0;
void work() {
    printf("%d\n", sap());
    dfs(vs);
    for (int i = 1; i <= n; ++i)
        moves += (!vis[i])+(vis[i+n]);
    printf("%d\n", moves);
    for (int i = 1; i <= n; ++i) {
        if (!vis[i])
            printf("%d -\n", i);
        if (vis[i+n])
            printf("%d +\n", i);
    }
}

int main() {
    load();
    work();
    return 0;
}
