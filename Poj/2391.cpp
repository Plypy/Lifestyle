#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
typedef long long lld;
const lld MAXN = 205;

const lld MAXV = 2*MAXN;
const lld MAXE = MAXV*MAXV*2;
const lld INF = (1LL)<<60;
lld vs, vt;
struct Edge {
    lld vtx, cap;
    Edge *nxt, *rev;
    Edge() { }
    Edge(lld iv, lld ic, Edge *in, Edge *ir):
        vtx(iv), cap(ic), nxt(in), rev(ir) { }
} epool[MAXE], *adj[MAXV], *stae[MAXV], *p[MAXV], *eptr = epool;
inline void add(lld u, lld v, lld cap) {
    adj[u] = new (eptr++) Edge(v,cap,adj[u],eptr);
    adj[v] = new (eptr++) Edge(u,0,adj[v],eptr-2);
}
lld stap[MAXV], lv[MAXV];
bool label() {
    memset(lv,-1,sizeof(lv));
    lv[vs] = 0;
    lld head, tail;
    stap[head=tail=0] = vs;
    while (head <= tail) {
        lld u = stap[head++];
        for (Edge *t = adj[u]; t; t = t->nxt) {
            lld v = t->vtx;
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
lld aug() {
    lld ret = 0;
    for (lld i = vs; i <= vt; ++i)
        p[i] = adj[i];
    lld stop = 1;
    stap[stop] = vs;
    lld u, v;
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
            lld delta = INF;
            for (lld i = stop; i >= 2; --i)
                if (stae[i]->cap < delta)
                    delta = stae[i]->cap;
            ret += delta;
            for (lld i = stop; i >= 2; --i) {
                stae[i]->cap -= delta;
                stae[i]->rev->cap += delta;
                if (!stae[i]->cap)
                    stop = i-1;
            }
        }
    }
    return ret;
}
lld dinic() {
    lld ret = 0;
    while (label())
        ret += aug();
    return ret;
}

int n, m;
lld dis[MAXV][MAXV];
int now[MAXV], hold[MAXV];
void load() {
    scanf("%d%d", &n, &m);
    vs = 0;
    vt = 2*n+1;
    for (lld i = 1; i <= n; ++i) {
        scanf("%d%d", now+i, hold+i);
        now[0] += now[i];
    }
    for (lld i = 1; i <= n; ++i)
        for (lld j = 1; j <= n; ++j)
            dis[i][j] = INF;
    for (lld i = 1; i <= m; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if (c < dis[a][b])
            dis[a][b] = dis[b][a] = c;
    }
}

void floyd() {
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            if (i != k)
                for (int j = 1; j <= n; ++j)
                    if (i != j && j != k)
                        if (dis[i][k]+dis[k][j] < dis[i][j])
                            dis[i][j] = dis[i][k]+dis[k][j];
}
void build(lld ubd) {
    memset(adj,0,sizeof(adj));
    eptr = epool;
    for (int i = 1; i <= n; ++i) {
        add(vs,i,now[i]);
        add(i+n,vt,hold[i]);
        add(i,i+n,INF);
    }
    for (int i = 1; i < n; ++i)
        for (int j = i+1; j <= n; ++j)
            if (dis[i][j] != INF && dis[i][j] <= ubd) {
                add(i,j+n,INF);
                add(j,i+n,INF);
            }
}
void work() {
    floyd();
    lld l = 0, r = 0;
    for (int i = 1; i < n; ++i)
        for (int j = i+1; j <= n; ++j)
            if (dis[i][j] != INF && r < dis[i][j])
                r = dis[i][j];
    build(r);
    if (dinic() != now[0]) {
        printf("-1\n");
        return;
    }

    while (l+1 < r) {
        lld mid = (l+r)>>1;
        build(mid);
        if (dinic() == now[0])
            r = mid;
        else
            l = mid;
    }
    cout << r << endl;
}
int main() {
    ios::sync_with_stdio(false);
    load();
    work();
    return 0;
}
