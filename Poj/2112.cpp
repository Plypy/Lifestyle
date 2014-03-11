#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int INF = 1<<28;
const int MAXV = 250;
const int MAXE = MAXV*MAXV;
int vs, vt;
struct Edge {
    int vtx, cap;
    Edge *nxt, *rev;
    Edge() { }
    Edge(int iv, int ic, Edge *in, Edge *ir):
        vtx(iv), cap(ic), nxt(in), rev(ir) { }
} epool[MAXE], *adj[MAXV], *p[MAXV], *stae[MAXV], *eptr = epool;
inline void add(int u, int v, int cap) {
    adj[u] = new (eptr++) Edge(v,cap,adj[u],eptr);
    adj[v] = new (eptr++) Edge(u,0,adj[v],eptr-2);
}
int stap[MAXV], lv[MAXV];
bool label() {
    memset(lv,-1,sizeof(lv));
    lv[vs] = 0;
    int head, tail;
    stap[head=tail=0] = vs;
    while (head <= tail) {
        int u = stap[head++];
        for (Edge *t = adj[u]; t; t = t->nxt) {
            int v = t->vtx;
            if (t->cap && -1 == lv[v]) {
                lv[v] = lv[u]+1;
                if (v == vt)
                    return true;
                stap[++tail] = v;
            }
        }
    }
    return false;
}
int aug() {
    for (int i = vs; i <= vt; ++i)
        p[i] = adj[i];
    int ret = 0;
    int stop = 1;
    stap[stop] = vs;
    int u, v;
    while (stop) {
        u = stap[stop];
        if (u != vt) {
            for (; p[u]; p[u] = p[u]->nxt)
                if (p[u]->cap && lv[u]+1 == lv[v=p[u]->vtx])
                    break;
            if (p[u]) {
                stap[++stop] = v;
                stae[stop] = p[u];
            } else
                --stop, lv[u] = -1;
        } else {
            int delta = INF;
            for (int i = stop; i >= 2; --i)
                if (stae[i]->cap < delta)
                    delta = stae[i]->cap;
            ret += delta;
            for (int i = stop; i >= 2; --i) {
                stae[i]->cap -= delta;
                stae[i]->rev->cap += delta;
                if (!stae[i]->cap)
                    stop = i-1;
            }
        }
    }
    return ret;
}
int dinic() {
    int ret = 0;
    while (label())
        ret += aug();
    return ret;
}

int K, C, M, n;
int g[MAXV][MAXV];
void load() {
    scanf("%d%d%d", &K, &C, &M);
    n = K+C;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &g[i][j]);
            if (!g[i][j])
                g[i][j] = INF;
        }
}
int dis[MAXV][MAXV];
void floyd() {
    memcpy(dis,g,sizeof(g));
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            if (i != k)
                for (int j = 1; j <= n; ++j)
                    if (j != i && j != k)
                        if (dis[i][k]+dis[k][j] < dis[i][j])
                            dis[i][j] = dis[i][k]+dis[k][j];
}
void build(int ubd) {
    memset(adj,0,sizeof(adj));
    eptr = epool;
    vs = 0;
    vt = n+1;
    for (int i = 1; i <= K; ++i)
        add(vs,i,M);
    for (int i = 1; i <= C; ++i)
        add(K+i,vt,1);
    for (int i = 1; i <= K; ++i)
        for (int j = K+1; j <= n; ++j)
            if (dis[i][j] <= ubd)
                add(i,j,1);
}
void work() {
    floyd();
    int l = 0, r = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (dis[i][j] != INF && dis[i][j] > r)
                r = dis[i][j];
    while (l+1 < r) {
        int mid = (l+r)>>1;
        build(mid);
        if (dinic() == C)
            r = mid;
        else
            l = mid;
    }
    printf("%d\n", r);
}
int main() {
    load();
    work();
    return 0;
}
