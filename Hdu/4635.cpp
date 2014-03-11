/**
 * Description:
 * Source:
 * Author: Ply_py
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
using namespace std;

const int MAXN = 100005;
const int MAXM = MAXN;
const int MAXV = MAXN;
const int MAXE = MAXM;
struct Edge {
    int vtx;
    Edge *nxt;
    Edge() { };
    Edge(int a, Edge *b): vtx(a), nxt(b) { }
} epool[MAXE], *adj[MAXV], *eptr = epool;
void add(int u, int v) {
    adj[u] = new (eptr++) Edge(v,adj[u]);
}
int dfn[MAXV], low[MAXV];
int stk[MAXV], top;
int col[MAXV], cnt[MAXV];
int ind[MAXV], oud[MAXV];
int sum[MAXV];
int n,m;
void init() {
    eptr = epool;
    memset(adj,0,sizeof(adj));
    memset(low,0,sizeof(low));
    memset(dfn,0,sizeof(dfn));
    memset(col,0,sizeof(col));
    memset(cnt,0,sizeof(cnt));
    memset(ind,0,sizeof(ind));
    memset(oud,0,sizeof(oud));
}
void tarjan(int u) {
    dfn[u] = low[u] = ++dfn[0];
    stk[++top] = u;
    int v = 0;
    for (Edge *t = adj[u]; t; t = t->nxt) {
        v = t->vtx;
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u],low[v]);
        } else if (!col[v]) {
            low[u] = min(low[u],dfn[v]);
        }
    }
    if (low[u] == dfn[u]) {
        ++col[0];
        do {
            v = stk[top--];
            col[v] = col[0];
            ++cnt[col[0]];
        } while (v!=u);
    }
}
int work() {
    for (int i = 1; i <= n; ++i)
        if (!dfn[i])
            tarjan(i);
    if (1 == col[0]) {
        return -1;
    }
    for (int u = 1; u <= n; ++u) {
        for (Edge *t = adj[u]; t; t = t->nxt) {
            int v = t->vtx;
            if (col[u] == col[v])
                continue;
            ++ind[col[v]];
            ++oud[col[u]];
        }
    }
    int ans = 0;
    for (int i = 1; i <= col[0]; ++i) {
        if (ind[i] && oud[i])
            continue;
        int a = cnt[i], b = n-cnt[i];
        ans = max(ans,a*b+a*(a-1)+b*(b-1));
    }
    ans -= m;
    return ans;
}

void load() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u,v);
    }
}
int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        load();
        printf("Case %d: %d\n", i, work());
        init();
    }
    return 0;
}