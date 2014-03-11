/**
 * Description:
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
typedef long long LL;
const LL MAXN = 200005;
const LL MAXM = MAXN;
LL INF = 0x3f3f3f3f3f3f3f3fLL;
const LL MAXV = MAXN;
const LL MAXE = MAXM*2;
int n, m;
int S, T;
struct Edge {
    LL vtx;
    LL len;
    LL id;
    Edge *nxt;
    Edge(int a = 0, LL b = 0, int c = 0, Edge *d = 0):
        vtx(a), len(b), id(c), nxt(d) { }
} epool[MAXE], *adj[MAXV], *eptr = epool;

void add(int u, int v, LL len, int id) {
    adj[u] = new (eptr++) Edge(v,len,id,adj[u]);
    adj[v] = new (eptr++) Edge(u,len,id,adj[v]);
}
struct Node {
    LL vtx;
    LL dis;
    Node(LL a = 0, LL b = 0): vtx(a), dis(b){ };
    bool operator<(const Node &t) const {
        return dis>t.dis;
    }
} ;
LL dist[MAXV];
bool outq[MAXV];
void dijkstra(LL vs) {
    memset(dist,INF,sizeof(dist));
    memset(outq,0,sizeof(outq));
    dist[vs] = 0;
    priority_queue<Node> que;
    que.push(Node(vs,0));
    int u, v;
    while (que.size()) {
        u = que.top().vtx;
        que.pop();
        if (outq[u])
            continue;
        outq[u] = true;
        for (Edge *t = adj[u]; t; t = t->nxt) {
            v = t->vtx;
            if (dist[v] > dist[u]+t->len) {
                dist[v] = dist[u]+t->len;
                que.push(Node(v,dist[v]));
            }
        }
    }
}
LL disS[MAXV], disT[MAXV];
bool used[MAXM];
bool ct[MAXV];
void SPG(int u) {
    ct[u] = true;
    for (Edge *t = adj[u]; t; t = t->nxt) {
        int v = t->vtx;
        if (disS[v] == disS[u]+t->len) {
            used[t->id] = true;
            if (!ct[v])
                SPG(v);
        }
    }
}
void reduce() {
    dijkstra(S);
    memcpy(disS,dist,sizeof(dist));
    dijkstra(T);
    memcpy(disT,dist,sizeof(dist));
    SPG(S);
}

bool bridge[MAXV];
int dfn[MAXV], low[MAXV];
bool tarjan(int u, int fa) {
    bool ret = false;
    if (u == T)
        ret = true;
    low[u] = dfn[u] = ++dfn[0];
    for (Edge *t = adj[u]; t; t = t->nxt) {
        if (used[t->id]) {
            int v = t->vtx;
            if (!dfn[v]) {
                bool d = tarjan(v,u);
                if (d)
                    ret = true;
                low[u] = min(low[u],low[v]);
                if (d && low[v] > low[u]) {
                    bridge[t->id] = true;
                }
            } else if (dfn[v] < dfn[u] && v != fa) {
                low[u] = min(low[u],dfn[v]);
            }
        }
    }
    return ret;
}
int x[MAXM], y[MAXM];
void work() {
    reduce();
}
void load() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int a, b, c;
        scanf("%d%d%lld", &a, &b, &c);
//        ++a,++b;
        add(a,b,c,i);
    }
    scanf("%d%d", &S, &T);
//    ++S, ++T;
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", x+i,y+i);
//        ++x[i], ++y[i];
    }
}
int main() {
    load();
    work();
    return 0;
}
