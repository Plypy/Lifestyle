#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 205;
const int MAXP = 40005;

const int MAXV = MAXN;
const int MAXE = MAXP*4;
const int INF = 1<<28;
int vs, vt;
struct Edge {
    int vtx, cap;
    Edge *nxt, *rev;
    Edge() { }
    Edge(int iv, int ic, Edge *in, Edge *ir):
        vtx(iv), cap(ic), nxt(in), rev(ir) { }
} epool[MAXE], *adj[MAXV], *stae[MAXV], *p[MAXV], *eptr = epool;
void add(int u, int v, int cap) {
    adj[u] = new (eptr++) Edge(v,cap,adj[u],eptr);
    adj[v] = new (eptr++) Edge(u,0,adj[v],eptr-2);
}
int stap[MAXV], lv[MAXV];
bool label() {
    int head, tail;
    stap[head=tail=0] = vs;
    memset(lv,-1,sizeof(lv));
    lv[vs] = 0;
    while (head <= tail) {
        int u = stap[head++];
        for (Edge *t = adj[u]; t; t = t->nxt) {
            int v = t->vtx;
            if (t->cap && -1 == lv[v]) {
                lv[v] = lv[u]+1;
                if (vt == v)
                    return true;
                stap[++tail] = v;
            }
        }
    }
    return false;
}
int aug() {
    int ret = 0;
    for (int i = vs; i <= vt; ++i)
        p[i] = adj[i];
    int stop = 1;
    stap[stop] = vs;
    int u, v;
    while (stop) {
        int u = stap[stop];
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

struct Dat {
    int u, v, l;
    bool operator<(const Dat& T) const {
        return l<T.l;
    }
} dat[MAXP];
int N, P, T;
void load() {
    scanf("%d%d%d", &N, &P, &T);
    for (int i = 1; i <= P; ++i)
        scanf("%d%d%d", &dat[i].u, &dat[i].v, &dat[i].l);
}
void build(int ubd) {
    memset(adj,0,sizeof(adj));
    eptr = epool;

    add(vs,1,T);
    add(N,vt,T);
    for (int i = 1; i <= P; ++i) {
        if (dat[i].l > ubd)
            break;
        add(dat[i].u,dat[i].v,1);
        add(dat[i].v,dat[i].u,1);
    }
}
void work() {
    vs = 0, vt = N+1;
    sort(dat+1,dat+P+1);
    int l = 0, r = dat[P].l;
    while (l+1 < r) {
        int mid = (l+r)>>1;
        build(mid);
        if (dinic() == T)
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
