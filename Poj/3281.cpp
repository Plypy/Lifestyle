#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 105;

const int MAXV = MAXN*4;
const int MAXE = MAXV*MAXV;
const int INF = 1<<28;
int vs, vt;
struct Edge {
    int vtx, cap;
    Edge *nxt, *rev;
    Edge() { }
    Edge(int iv, int ic, Edge *in, Edge *ir):
        vtx(iv), cap(ic), nxt(in), rev(ir) { }
} epool[MAXE], *adj[MAXV], *stae[MAXV], *p[MAXV], *eptr = epool;
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
    int u, v;
    while (head <= tail) {
        u = stap[head++];
        for (Edge *t = adj[u]; t; t = t->nxt)
            if (t->cap && -1 == lv[v=t->vtx]) {
                lv[v] = lv[u]+1;
                if (v == vt)
                    return true;
                stap[++tail] = v;
            }
    }
    return false;
}
int aug() {
    int ret = 0;
    for (int i = vs; i <= vt; ++i)
        p[i] = adj[i];
    int stop;
    stap[stop=1] = vs;
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
   while (label()) {
//        printf("%d\n", ret);
        ret += aug();
//        printf("%d\n", ret);
    }
    return ret;
}
int n, f, d;
void load() {
    scanf("%d%d%d", &n, &f, &d);
    vs = 0;
    vt = 2*n+f+d+1;
    for (int i = 1; i <= n; ++i)
        add(i,i+n,1);
    for (int i = 1; i <= f; ++i)
        add(vs,2*n+i,1);
    for (int i = 1; i <= d; ++i)
        add(2*n+f+i,vt,1);
    for (int i = 1; i <= n; ++i) {
        int a, b, c;
        scanf("%d%d", &a, &b);
        for (int j = 1; j <= a; ++j) {
            scanf("%d", &c);
            add(2*n+c,i,1);
        }
        for (int j = 1; j <= b; ++j) {
            scanf("%d", &c);
            add(i+n,2*n+f+c,1);
        }
    }
}
void work() {
    printf("%d\n", dinic());
}
int main() {
    load();// load&build
    work();
    return 0;
}
