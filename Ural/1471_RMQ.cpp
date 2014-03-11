/**
 * LCA problems
 * Transform LCA into RMQ, then use segment tree to compute;
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
const int MAXN = 50005;

const int MAXV = MAXN;
const int MAXE = MAXN*2;
struct Edge {
    int vtx, len;
    Edge *nxt;
    Edge(int a = 0, int b = 0, Edge *c = 0): vtx(a), len(b), nxt(c) { }
} epool[MAXE], *adj[MAXV], *eptr = epool;
void add(int u, int v, int l) {
    adj[u] = new (eptr++) Edge(v,l,adj[u]);
    adj[v] = new (eptr++) Edge(u,l,adj[v]);
}
LL dist[MAXN];
int n, m;

int fst[MAXN], dep[MAXN];
int dar[MAXN<<1], var[MAXN<<1], cnt;
int tr[MAXN<<3];
int stk[MAXN], top;
Edge *p[MAXN];
int M;
void dfs() {
    stk[top=1] = 1;
    dep[1] = 1;
    dist[1] = 0;
    for (int i = 1; i <= n; ++i)
        p[i] = adj[i];
    int u, v;
    while (top) {
        u = stk[top];
        dar[++cnt] = dep[u];
        if (0 == fst[u])
            fst[u] = cnt;
        var[cnt]   = u;
        for (; p[u]; p[u] = p[u]->nxt)
            if (0 == dep[v=p[u]->vtx])
                break;
        if (p[u]) {
            dep[v] = dep[u]+1;
            dist[v] = dist[u]+p[u]->len;
            stk[++top] = v;
        } else
            --top;
    }
}
void update(int fa) {
    int l = fa<<1;
    int r = l+1;
    if (dep[tr[l]] < dep[tr[r]])
        tr[fa] = tr[l];
    else
        tr[fa] = tr[r];
}
void build() {
    for (M = 1; M <= cnt; M <<= 1)
        continue;
    for (int i = 1; i <= cnt; ++i)
        tr[i+M] = var[i];
    for (int i = M-1; i; --i)
        update(i);
}
int query(int l, int r) {
    dep[0] = n+1;
    int ret = 0;
    for (l = l-1+M, r = r+1+M; l^r^1; l >>= 1, r >>= 1) {
        if (~l&1)
            if (dep[ret] > dep[tr[l^1]])
                ret = tr[l^1];
        if (r&1)
            if (dep[ret] > dep[tr[r^1]])
                ret = tr[r^1];
    }
    return ret;
}
int lca(int u, int v) {
    int a = min(fst[u],fst[v]);
    int b = max(fst[u],fst[v]);
    return query(a,b);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a+1,b+1,c);
    }

    dfs();
    build();
//    for (int i = 1; i <= cnt; ++i) {
//        cout << var[i] << ' ';
//    }
//    cout << endl;
//    while (true) {
//        int a, b;
//        cin >> a >> b;
//        cout << fst[a] << ' ' << fst[b] << endl;
//        cout << lca(a,b) << endl;
//    }
    int q;
    scanf("%d", &q);
    while (q--) {
        int a, b;
        scanf("%d%d", &a, &b);
        ++a, ++b;
        int c = lca(a,b);
        LL ans = dist[a]+dist[b]-2*dist[c];
        printf("%lld\n", ans);
    }
    return 0;
}
