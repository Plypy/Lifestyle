#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 5010;
const int MAXM = 50010;
const int MAXV = MAXN+MAXM;
const int MAXE = 2*(MAXN+MAXM+2*MAXM);
const int INF = 52111425;
struct Edge {
    Edge *nxt, *opp;
    int vtx, cap;
    Edge(int _vtx = 0, int _cap = 0, Edge *_nxt = 0, Edge *_opp = 0):
        vtx(_vtx), cap(_cap), nxt(_nxt), opp(_opp) { }
} edge[MAXE], *adj[MAXV];
int ect;
int sour, dest;
int n, m;
int tot_profit;
inline void add(int u, int v, int cap) {
    adj[u] = &(edge[++ect] = Edge(v,cap,adj[u],edge+ect+1));
    adj[v] = &(edge[++ect] = Edge(u,0,adj[v],edge+ect-1));
}
inline int min(int a, int b) {
    return a<b?a:b;
}
inline void load() {
    scanf("%d%d", &n, &m);
    sour = 0;
    dest = n+m+1;
    for (int i = 1; i <= n; ++i) {
        int p;
        scanf("%d", &p);
        add(i,dest,p);
    }
    for (int i = 1; i <= m; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        tot_profit += c;
        add(i+n,a,INF);
        add(i+n,b,INF);
        add(sour,i+n,c);
    }
}
int ht[MAXV];
int hct[MAXV];
int flow;
int tot_v;

int aug(int u, int augc) {
    if (u == dest)
        return augc;
    int tmp = augc;
    int minht = tot_v;
    for (Edge *t = adj[u]; t; t = t->nxt) {
        if (t->cap > 0) {
            int v = t->vtx;
            minht = min(minht,ht[v]);
            if (ht[v]+1 == ht[u]) {
                int d = aug(v,min(tmp,t->cap));
                if (ht[sour] >= tot_v)
                    return 0;
                if (d) {
                    t->cap -= d;
                    t->opp->cap += d;
                    tmp -= d;
                    if (!tmp)
                        return augc;
                }
            }
        }
    }
    if (tmp == augc) {
        --hct[ht[u]];
        if (!hct[ht[u]])
            ht[sour] = tot_v;
        ht[u] = minht+1;
        ++hct[ht[u]];
    }
    return augc-tmp;
}
inline void work() {
    tot_v = n+m+2;
    hct[0] = tot_v;
    while (ht[sour] < tot_v) {
        flow += aug(sour,INF);
    }
    int ans = tot_profit-flow;
    printf("%d\n", ans);
}

int main() {
//    freopen("profit.in", "r", stdin);
//    freopen("profit.out", "w", stdout);
    load();
//    cerr << "here" << endl;
    work();
//    system("pause");
    return 0;
}
/*
sample
5 5
1 2 3 4 5
1 2 3
2 3 4
1 3 3
1 4 2
4 5 3

ans
4
*/
