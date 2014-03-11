/**
 * Source: Usaco 2009 Jan Gold Safe Travel
 * Title: shortest path with deleted edge on tree
 * Description:
 * Given a undirected positive weighted graph, satisfied that for any vertex i,
 * there is only one shortest path exists. And now we can't take the last edge
 * of each shortest path of a particular vertex. In this situation, compute the
 * new shortest path for each vertex.
 * Solution:
 * First of all we compute the SPT(shortest path tree), and then we can find that
 * for an edge (u,v) that not belong to SPT, it can form a loop with path u~lca(u,v)~v.
 * And we denote dist[u]+dist[v]+|(u,v)| by L, then for any vertex x on this loop, its new
 * shortest path's length will be L-dist[x].
 * So our minds formed, we first compute all loops, and note that for a particular vertex x
 * the smaller the loop's length is, the better the answer is. Thus we sort all the loops.
 * And for a loop that computed by edge (u,v), let u and v go upwards until we met their lca,
 * update their answer simultaneously.
 * ANd to optimize this process, we find that, because of the order we sorted, only the first
 * time an answer can be updated. So we build a union-find-set, after we visited vertex u, we
 * let u attach to its father's set. And next time we can just visit u's represent. That will
 * save us a lot of time.
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
const int MAXN = 100005;
const int MAXM = 200005;
const int INF  = 0x3f3f3f3f;
const int MAXV = MAXN;
const int MAXE = MAXM*2;
struct Edge {
    int vtx, len;
    Edge *nxt;
    Edge(int a = 0, int b = 0, Edge *c = 0): vtx(a), len(b), nxt(c) { }
} epool[MAXE], *adj[MAXV], *eptr = epool;
void add(int u, int v, int len) {
    adj[u] = new (eptr++) Edge(v,len,adj[u]);
    adj[v] = new (eptr++) Edge(u,len,adj[v]);
}

struct Data {
    int u;
    int len;
    int v;
    Data(int a = 0, int b = 0, int c = 0): u(a), len(b), v(c) { }
    bool operator<(const Data& a) const {
        return len>a.len;
    }
} data[MAXM], loop[MAXM];
int loopCnt;
bool outq[MAXV];
int dist[MAXV];
void dijkstra() {
    priority_queue<Data> que;
    memset(dist,INF,sizeof(dist));
    dist[1] = 0;
    que.push(Data(1,0));
    while (que.size()) {
        int u, v;
        const Data &cur = que.top();
        u = cur.u;
        que.pop();
        if (outq[u])
            continue;
        outq[u] = true;
        for (Edge *t = adj[u]; t; t = t->nxt) {
            v = t->vtx;
            if (dist[v] > dist[u]+t->len) {
                dist[v] = dist[u]+t->len;
                que.push(Data(v,dist[v]));
            }
        }
    }
}
int tFa[MAXV];
int dep[MAXV];
void makeTree(int u) {
    for (Edge *t = adj[u]; t; t = t->nxt) {
        int v = t->vtx;
        if (dep[v])
            continue;
        if (dist[v] == dist[u]+t->len) {
            tFa[v] = u;
            dep[v] = dep[u]+1;
            makeTree(v);
        } else {
            loop[++loopCnt] = Data(u,dist[u]+dist[v]+t->len,v);
        }
    }
}

void prepare() {
    dep[1] = 1;
    makeTree(1);
    sort(loop+1,loop+1+loopCnt);
}
int fa[MAXV];
int find(int u) {
    int c = u;
    while (fa[c] > 0)
        c = fa[c];
    while (fa[u] > 0) {
        int t = fa[u];
        fa[u] = c;
        u = t;
    }
    return c;
}
void attach(int u, int v) {
    u = find(u), v = find(v);
    if (u == v)
        return ;
    fa[v] = u;
}
int n, m;
int ans[MAXV];
void work() {
    dijkstra();
    prepare();
    for (int i = loopCnt; i; --i) {
        int u = loop[i].u, v = loop[i].v;
        int len = loop[i].len;
        u = find(u), v = find(v);
        while (u != v) {
            int &w = dep[u]>dep[v]?u:v;
            ans[w] = len-dist[w];
            attach(tFa[w],w);
            w = find(w);
        }
    }
    for (int i = 2; i <= n; ++i) {
        if (0 == ans[i])
            puts("-1");
        else
            printf("%d\n", ans[i]);
    }
}
void load() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a,b,c);
    }
}

int main() {
    load();
    work();
    return 0;
}
