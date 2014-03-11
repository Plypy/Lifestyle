#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int MAXN = 55;
const int MAXM = 110;
const int MAXV = MAXN*2;
const int MAXE = (MAXM+MAXV)*2;
const int INF = 52111425;
struct Edge {
    int vtx, cap;
    Edge *nxt, *ctr;
    Edge() { }
    Edge(int _vtx, int _cap, Edge *_nxt, Edge *_ctr):
        vtx(_vtx), cap(_cap), nxt(_nxt), ctr(_ctr) { }
} edge[MAXE], *adj[MAXV];
int sour, dest;
int cnt;
void add(int u, int v, int cap) {
    adj[u] = &(edge[++cnt] = Edge(v,cap,adj[u],edge+cnt+1));
    adj[v] = &(edge[++cnt] = Edge(u,0,adj[v],edge+cnt-1));
}
int n, m, k;
int flow;
void eatline() {
    while (getchar() != '\n')
        continue;
}
void load() {
    scanf("%d%d%d", &n, &m, &k);
    sour = 2; dest = 1;
    for (int i = 2; i <= n; ++i) {
        int w;
        scanf("%d", &w);
        add(i*2-1,i*2,w);
    }
    for (int i = 1; i <= k; ++i) {
        int r;
        scanf("%d", &r);
        add(r*2-1,dest,1);
    }
    for (int i = 1; i <= m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x*2,y*2-1,INF);
    }
}
inline int min(int a, int b) {
    return a<b?a:b;
}
bool used[MAXV];
int aug(int u, int augc) {
    if (u == dest) {
        flow += augc;
        return augc;
    }
    used[u] = true;
    for (Edge *t = adj[u]; t; t=t->nxt) {
        int v = t->vtx;
        if (!used[v] && t->cap) {
            int d = aug(v,min(augc,t->cap));
            if (d) {
                t->cap -= d;
                t->ctr->cap += d;
                return d;
            }
        }
    }
    return 0;
}
int maxflow() {
    do {
        memset(used,0,sizeof(used));
    } while (aug(sour,INF));
    return flow;
}
void work() {
    n <<= 1;
    printf("%d\n", maxflow());
//    system("pause");
}

int main() {
    load();
    work();
    return 0;
}
/*
5 5 4
1 0 2 2
2 3 4 5
1 2
1 3
2 4
3 4
4 5


ans 3
*/
