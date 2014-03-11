#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
using namespace std;
const int MAXN = 50;
const int INF = INT_MAX;
int n, m;
int vs, vt;
inline int min(int a, int b) {
    return a<b?a:b;
}
struct Edge {
    int vtx, cap;
    Edge *nxt, *rev;
    Edge() { }
    Edge(int iv, int ic, Edge *in, Edge *ir): 
        vtx(iv), cap(ic), nxt(in), rev(ir) { }
} epool[MAXN*(MAXN+1)*2], *adj[MAXN+MAXN];
int ect;
inline void add(int u, int v, int cap) {
    adj[u] = (new (epool+ect++) Edge(v,cap,adj[u],epool+ect));
    adj[v] = (new (epool+ect++) Edge(u,0,adj[v],epool+ect-2));
}
int ht[MAXN+MAXN];
int hct[MAXN+MAXN];
int vtot;
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
                t->rev->cap += d;
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
    vtot = n+m+2;
    hct[0] = vtot;
    while (ht[vs] < vtot)
        ret += aug(vs,INF);
    return ret;
}

void show(Edge *ptr) {
    cout << ptr->vtx << ' ' << ptr->cap << endl;
}
bool use[MAXN*2];
void dfs(int u) {
    use[u] = true;
    for (Edge *t = adj[u]; t; t = t->nxt)
        if (t->cap && !use[t->vtx])
            dfs(t->vtx);
}
int main() {
    freopen("shut.in", "r", stdin);
    freopen("shut_revise.out", "w", stdout);
    
    scanf("%d%d", &n, &m);
    vs = 0, vt = n+m+1;
    int tot = 0;
    for (int i = 1, e; i <= n; ++i) {
        scanf("%d", &e);
        tot += e;
        add(vs,i,e);
        while (getchar() != '\n') {
            cin >> e;
            add(i,e+n,INF);
        }
    }
    for (int i = 1, e; i <= m; ++i) {
        scanf("%d", &e);
        add(n+i,vt,e);
    }
    tot -= sap();
    dfs(vs);
    
    bool first = true;
    for (int i = 1; i <= n; ++i)
        if (use[i]) {
            if (first)
                first = false;
            else
                putchar(' ');
            printf("%d", i);
        }
    putchar('\n');
    first = true;
    for (int i = 1; i <= m; ++i)
        if (use[n+i]) {
            if (first)
                first = false;
            else
                putchar(' ');
            printf("%d", i);
        }
    putchar('\n');
    printf("%d\n", tot);
    return 0;
}
