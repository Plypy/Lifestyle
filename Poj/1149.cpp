#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int MAXN = 105;;
const int MAXM = 1005;
const int MAXV = MAXN;
const int MAXE = MAXV*MAXV;
const int INF = 1<<28;
int vs, vt;
struct Edge {
    int vtx, cap;
    Edge *nxt, *rev;
    Edge() { }
    Edge(int iv, int ic, Edge *in, Edge *ir):
        vtx(iv), cap(ic), nxt(in), rev(ir) { }
} epool[MAXE], *adj[MAXV], *ptr[MAXV], *stae[MAXV], *eptr = epool;
inline void add(int u, int v, int cap) {
    adj[u] = new (eptr++) Edge(v,cap,adj[u],eptr);
    adj[v] = new (eptr++) Edge(u,0,adj[v],eptr-2);
}
int stap[MAXV], lv[MAXV];
bool label() {
    int head, tail;
    stap[head=tail=0] = vs;
    memset(lv,-1,sizeof(lv));
    lv[vs] = 0;
    while (head<=tail) {
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
    return false;;
}
int aug() {
    int ret = 0;
    for (int i = vs; i <= vt; ++i)
        ptr[i] = adj[i];
    int stop = 1;
    stap[stop] = vs;
    int u, v;
    while (stop) {
        u = stap[stop];
        if (u != vt) {
            for (; ptr[u]; ptr[u] = ptr[u]->nxt)
                if (ptr[u]->cap && lv[u]+1 == lv[v=ptr[u]->vtx])
                    break;
            if (ptr[u]) {
                stap[++stop] = v;
                stae[stop] = ptr[u];
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

int m, n;
int pigs[MAXM];
int wanted[MAXN];
int last[MAXM];
int in[MAXV];
bool g[MAXV][MAXV];
void load() {
    scanf("%d%d", &m, &n);
    vs = 0;
    vt = n+1;
    for (int i = 1; i <= m; ++i)
        scanf("%d", pigs+i);
    for (int i = 1; i <= n; ++i) {
        int tmp;
        scanf("%d", &tmp);
        for (int j = 1; j <= tmp; ++j) {
            int t;
            scanf("%d", &t);
            if (last[t]) {
                g[last[t]][i] = true;
            } else {
                in[i] += pigs[t];
            }
            last[t] = i;
        }
        scanf("%d", wanted+i);
    }
}
void build() {
    for (int i = 1; i <= n; ++i) {
        add(vs,i,in[i]);
        add(i,vt,wanted[i]);
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (g[i][j])
                add(i,j,INF);
}
void work() {
    build();
 //   cout << "hello" << endl;
    printf("%d\n", dinic());
}

int main() {
    load();
    work();
    return 0;
}
