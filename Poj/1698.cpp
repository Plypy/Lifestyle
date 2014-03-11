#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 25;
const int MAXW = 50;

const int MAXV = MAXN+MAXW*7;
const int MAXE = MAXV*MAXV;
const int INF = 1<<28;
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
                if (0 == stae[i]->cap)
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
int sum;
void init() {
    sum = 0;
    memset(adj,0,sizeof(adj));
    eptr = epool;
}
void load() {
    int n;
    scanf("%d", &n);
    vs = 0, vt = 351+n;
    int bd = 7*MAXW;
    for (int j = 1; j <= bd; ++j)
        add(n+j,vt,1);
    int work[7] = {0};
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 7; ++j) {
            scanf("%d", work+j);
        }
        int d, w;
        scanf("%d%d", &d, &w);
        sum += d;
        add(vs,i,d);
        int tmp = n;
        for (int j = 0; j < w; ++j)
            for (int k = 0; k < 7; ++k) {
                ++tmp;
                if (work[k])
                    add(i,tmp,1);
            }
    }
}
void work() {
    int ans = dinic();
//    cout << sum << ' ' << ans << endl;
    if (ans == sum)
        puts("Yes");
    else
        puts("No");
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        load();
        work();
        init();
    }
    return 0;
}
