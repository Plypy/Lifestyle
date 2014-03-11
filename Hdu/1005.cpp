
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <cstring>
using namespace std;
const int MAXN = 205;
const int MAXM = 20005;
const int MAXV = MAXN*4;
const int MAXE = MAXV*MAXV;
const int INF = 1<<30;

inline int min(int a, int b) {
    return a<b?a:b;
}

struct Edge {
    int cap, vtx;
    Edge *nxt, *opp;
    Edge(int _vtx = 0, int _cap = 0, Edge *_nxt = 0, Edge *_opp = 0):
        vtx(_vtx), cap(_cap), nxt(_nxt), opp(_opp) { }
} edge[MAXE], *adj[MAXV];
int ect;
inline void add(int u, int v, int cap) {
    adj[u] = &(edge[++ect] = Edge(v,cap,adj[u],edge+ect+1));
    adj[v] = &(edge[++ect] = Edge(u,0,adj[v],edge+ect-1));
}

int n, f, d;//1~2n 2n+1~2n+f 2n+f+1~2n+f+d
int vs, vt, vtot;
bool load() {
    if (scanf("%d%d%d", &n, &f, &d) == EOF)
        return false;
    vtot = n*2+f+d+2;
    vs = 0;
    vt = n*2+f+d+1;
    for (int i = 1; i <= n; ++i)
        add(i,i+n,1);
    for (int i = 1; i <= f; ++i) {
        int t;
        scanf("%d", &t);
        add(vs,2*n+i,t);
    }
    for (int i = 1; i <= d; ++i) {
        int t;
        scanf("%d", &t);
        add(2*n+f+i,vt,t);
    }
    for (int i = 1; i <= n; ++i) {
        while (getchar() != '\n')
            continue;
        for (int j = 1; j <= f; ++j) {
            char ch = getchar();
            if ('Y' == ch)
                add(2*n+j,i,1);
        }
    }
    for (int i = 1; i <= n; ++i) {
        while (getchar() != '\n')
            continue;
        for (int j = 1; j <= d; ++j) {
            char ch = getchar();
            if ('Y' == ch)
                add(i+n,2*n+f+j,1);
        }
    }
    return true;
}

int hct[MAXV];
int ht[MAXV];
int aug(int u, int augc) {
    if (u == vt)
        return augc;
    int tmp = augc;
    int minht = vtot-1;
    for (Edge *t = adj[u]; t; t = t->nxt)
        if (t->cap) {
            int v = t->vtx;
            if (ht[v]+1 == ht[u]) {
                int d = aug(v,min(t->cap,tmp));
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
    if (tmp == augc) {
        --hct[ht[u]];
        if (!hct[ht[u]])
            ht[vs] = vtot;
        ht[u] = minht+1;
        ++hct[ht[u]];
    }
    return augc-tmp;
}
int sap() {
    int ret = 0;
    hct[0] = vtot;
    while (ht[vs] < vtot)
        ret += aug(vs,INF);
    return ret;
}
void work() {
    printf("%d\n", sap());
}
void init() {
    ect = 0;
    memset(adj,0,sizeof(adj));
    memset(ht,0,sizeof(ht));
    memset(hct,0,sizeof(hct));
}
int main() {
    while (load()) {
        work();
        init();
    }
    return 0;
}
