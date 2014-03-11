/**
 * 2008 Asia Beijing Regional
 * Destroying the bus stations
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
#include <cmath>
using namespace std;

const int MAXN = 55;
const int MAXM = 4005;
const int INF  = 0x3F3F3F3F;
const int MAXV = MAXN*2;
const int MAXE = MAXM*2+MAXN*2;
int vs, vt;

struct Edge {
    int vtx, cap;
    Edge *nxt, *rev;
    Edge() { }
    Edge(int a, int b, Edge *c, Edge *d):
        vtx(a), cap(b), nxt(c), rev(d) { }
} epool[MAXE], *adj[MAXV], *eptr = epool, *stae[MAXV], *p[MAXV];
void add(int u, int v, int cap) {
    adj[u] = new (eptr++) Edge(v,cap,adj[u],eptr);
    adj[v] = new (eptr++) Edge(u,0,adj[v],eptr-2);
}
int lv[MAXV], stap[MAXV];
bool label() {
    int st, ed;
    stap[st=ed=0] = vs;
    memset(lv,-1,sizeof(lv));
    lv[vs] = 0;
    while (st <= ed) {
        int u = stap[st++];
        for (Edge *t = adj[u]; t; t = t->nxt) {
            int v = t->vtx;
            if (t->cap && -1 == lv[v]) {
                lv[v] = lv[u]+1;
                if (v == vt)
                    return true;
                stap[++ed] = v;
            }
        }
    }
    return false;
}
int aug() {
    int ret = 0;
    for (int i = vs; i <= vt; ++i)
        p[i] = adj[i];
    int stop;
    stap[stop = 1] = vs;
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
            for (int i = stop; i >= 2; --i) {
                stae[i]->cap -= delta;
                stae[i]->rev->cap += delta;
                if (!stae[i]->cap)
                    stop = i-1;
            }
            ret += delta;
        }
    }
    return ret;
}
int dinic() {
    int ret = 0;
    while (label()) {
        ret += aug();
    }
    return ret;
}

int n, m, k;
int g[MAXN][MAXN];
void floyd() {
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (g[i][k] + g[k][j] < g[i][j])
                    g[i][j] = g[i][k]+g[k][j];
}
void init() {
    memset(adj,0,sizeof(adj));
    eptr = epool;
}
struct Data {
    int a, b;
} data[MAXM];
bool load() {
    init();
    cin >> n >> m >> k;
    if (0 == n && 0 == m && 0 == k)
        return false;
    memset(g,INF,sizeof(g));
    for (int i = 1; i <= n; ++i)
        g[i][i] = 0;
    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        data[i].a = a, data[i].b = b;
        g[a][b] = 1;
    }
    return true;
}
int cal(int u, bool f) {
    if (f)
        return 2*u-1;
    return 2*u;
}
void work() {
    floyd();
    vs = cal(1,false);
    vt = cal(n,true);
    for (int i = 2; i < n; ++i)
        add(cal(i,true),cal(i,false),1);
    for (int i = 1; i <= m; ++i) {
        int u = data[i].a, v = data[i].b;
        if (g[1][u] + g[v][n] < k) {
            add(cal(u,false),cal(v,true),INF);
        }
    }
    int ans = dinic();
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    while (load()) {
        work();
    }
    return 0;
}
