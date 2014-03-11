/* Todo：NOI 2009 Pvz 一题，网络流练习题
 */
 
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int MAXN = 25;
const int MAXM = 35;
const int MAXV = MAXN*MAXM;
const int MAXE = MAXV*MAXV*2;
const int INF  = 52111425;
inline int min(int a, int b) {
    return a<b?a:b;
}
struct Edge {
    int vtx, cap;
    Edge *nxt, *opp;
    Edge(int _vtx = 0, int _cap = 0, Edge *_nxt = 0, Edge *_opp = 0):
        vtx(_vtx), cap(_cap), nxt(_nxt), opp(_opp) { }
} edge[MAXE], *adj[MAXV];
int ect;
inline void add(int u, int v, int cap) {
    adj[u] = &(edge[++ect] = Edge(v,cap,adj[u],edge+ect+1));
    adj[v] = &(edge[++ect] = Edge(u,0,adj[v],edge+ect-1));
}
int id[MAXN][MAXM];
int sc[MAXV];
int oud[MAXV];
int idct;
int n, m;
int vs, vt;
int ans;
inline void load() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            id[i][j] = ++idct;
    vs = ++idct;
    vt = ++idct;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            int u = id[i][j];
            int v;
            if (j+1 < m) {
                v = id[i][j+1];
                add(u,v,INF);
                ++oud[u];
            }
            scanf("%d", sc+u);
            int k;
            scanf("%d", &k);
            while (k--) {
                int r, c;
                scanf("%d%d", &r, &c);
                v = id[r][c];
                ++oud[v];
                add(v,u,INF);
            }
        }
}

bool valid[MAXV];
int stack[MAXV];
inline void topsort() {
    for (int i = 1; i < vs; ++i)
        if (0 == oud[i])
            stack[++stack[0]] = i;
    while (stack[0]) {
        int u = stack[stack[0]--];
        valid[u] = true;
        for (Edge *t = adj[u]; t; t = t->nxt)
            if (0 == t->cap) {
                int v = t->vtx;
                --oud[v];
                if (!oud[v])
                    stack[++stack[0]] = v;
            }
    }
}
int vtot = 2;
inline void build() {
    for (int i = 1; i < vs; ++i)
        if (valid[i]) {
            ++vtot;
            if (sc[i] > 0) {
                add(vs,i,sc[i]);
                ans += sc[i];
            } else
                add(i,vt,-sc[i]);
        }
}

int hct[MAXV];
int ht[MAXV];
int ret;
int aug(int u, int augc) {
    if (u == vt)
        return augc;
    int minht = vtot-1;
    int tmp = augc;
    for (Edge *t = adj[u]; t; t = t->nxt) {
        int v = t->vtx;
        if (t->cap && valid[v]) {
            if (ht[v]+1 == ht[u]) {
                int d = aug(v,min(tmp,t->cap));
                tmp -= d;
                t->cap -= d;
                t->opp->cap += d;
                if (!tmp)
                    return augc;
                if (ht[vs] >= vtot)
                    return augc-tmp;
            }
            minht = min(minht,ht[v]);
        }
    }
    if (augc == tmp) {
        --hct[ht[u]];
        if (hct[ht[u]] == 0) {
            ht[vs] = vtot;
        }
        ht[u] = minht+1;
        ++hct[ht[u]];
    }
    return augc-tmp;
}
            
inline int sap() {
    ret = 0;
    hct[0] = vtot;
    while (ht[vs] < vtot)
        ret += aug(vs,INF);
    return ret;
}
int mcut;
inline void work() {
    topsort();
    valid[vs] = valid[vt] = true;
    build();
    
    mcut = sap();
    ans -= mcut;
    printf("%d\n", ans);
}
int main() {
//    freopen("pvz.in", "r", stdin);
//    freopen("pvz.out", "w", stdout);
    load();
    work();
    return 0;
}
/*
3 2
10 0
20 0
-10 0
-5 1 0 0
100 1 2 1
100 0

ans 25
*/

