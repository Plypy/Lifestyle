/**
 * Description: Using tarjan to compute lca
 * Note check the boundary carefully
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
const int MAXN = 60005;
const int MAXM = 100000;
const int MAXV = MAXN;
const int MAXE = MAXN*2+MAXM*2;
struct Edge {
    int vtx, len;
    Edge *nxt;
    Edge(int a = 0, int b = 0, Edge *c = 0): vtx(a), len(b), nxt(c) { }
} epool[MAXE], *adj[MAXV], *eptr = epool, *data[MAXV];
void add(int u, int v, int len) {
    adj[u] = new (eptr++) Edge(v,len,adj[u]);
    adj[v] = new (eptr++) Edge(u,len,adj[v]);
}
void addData(int u, int v, int id) {
    data[u] = new (eptr++) Edge(v,id,data[u]);
    data[v] = new (eptr++) Edge(u,id,data[v]);
}

int fa[MAXV];
int find(int a) {
    int c = a;
    while (fa[c] > 0) {
        c = fa[c];
    }
    while (fa[a] > 0) {
        int t = fa[a];
        fa[a] = c;
        a = t;
    }
    return c;
}
void unionSet(int a, int b) {
    a = find(a), b = find(b);
    if (a == b)
        return ;
    if (fa[a] > fa[b]) {
        fa[a] = b;
    } else {
        if (fa[a] == fa[b])
            --fa[a];
        fa[b] = a;
    }
}

int ans[MAXM];

int n, m;
int dist[MAXV];

int stk[MAXV], top;
int col[MAXV];
int last[MAXV];
int ancestor[MAXV];
Edge *p[MAXV];

void tarjan() { // Non recursion version
    for (int i = 1; i <= n; ++i)
        p[i] = adj[i];
    stk[top=1] = 1;
    col[1] = 1;
    dist[1] = 0;
    int u, v;
    while (top) {
        u = stk[top];
        if (last[u]) {
            unionSet(u,last[u]);
        }
        ancestor[find(u)] = u;
        for (; p[u]; p[u] = p[u]->nxt)
            if (0 == col[v=p[u]->vtx])
                break;
        if (p[u]) {
            col[v] = 1;
            last[u] = v;
            dist[v] = dist[u]+p[u]->len;
            stk[++top] = v;
        } else {
            col[u] = 2;
            for (Edge *t = data[u]; t; t = t->nxt) {
                v = t->vtx;
                if (2 == col[v])
                    ans[t->len] = ancestor[find(v)];
            }
            --top;
        }
    }
}
void dfs(int u) {
    ancestor[find(u)] = u;
    col[u] = 1;
    for (Edge *t = adj[u]; t; t = t->nxt) {
        int v = t->vtx;
        if (0 == col[v]) {
            dist[v] = dist[u]+t->len;
            dfs(v);
            unionSet(u,v);
            ancestor[find(u)] = u;
        }
    }
    col[u] = 2;
    for (Edge *t = data[u]; t; t = t->nxt) {
        int v = t->vtx;
        if (2 == col[v])
            ans[t->len] = ancestor[find(v)];
    }
}
void compute() {
    dist[1] = 0;
    dfs(1);
}
int l[MAXM], r[MAXM];
int main() {
    scanf("%d", &n);
//    n = 50000;
    for (int i = 1; i < n; ++i) {
        int a, b, c;
//        a = i-1, b = i, c = 1;
        scanf("%d%d%d", &a, &b, &c);
        ++a,++b;
        add(a,b,c);
    }
    scanf("%d", &m);
//    m = 1;
    for (int i = 1; i <= m; ++i) {
        int a, b;
//        a = 0, b = 1;
        scanf("%d%d", &a, &b);
        ++a, ++b;
        addData(a,b,i);
        l[i] = a, r[i] = b;
    }
    tarjan();
//    compute();
    for (int i = 1; i <= m; ++i) {
        int a = l[i], b = r[i], c = ans[i];
        int val = dist[a]+dist[b]-2*dist[c];
        printf("%d\n", val);
    }
    return 0;
}
