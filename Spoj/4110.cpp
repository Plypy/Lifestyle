// 仔细读题...
// 时刻注意数据范围
// 选用合适的数据类型
// 要不然溢出了就真悲剧了 
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;
typedef unsigned long long ull;
const ull MAXV = 5005;
const ull MAXE = 30005*2;
const ull INF = ULLONG_MAX;

inline ull min(ull a, ull b) {
    return a<b?a:b;
}

struct Edge {
    ull cap, vtx;
    Edge *nxt, *opp;
    Edge(ull _vtx = 0, ull _cap = 0, Edge *_nxt = 0, Edge *_opp = 0):
        vtx(_vtx), cap(_cap), nxt(_nxt), opp(_opp) { }
} edge[MAXE], *adj[MAXV];
ull ect;

inline void add(ull u, ull v, ull cap) {
    adj[u] = &(edge[++ect] = Edge(v,cap,adj[u],edge+ect+1));
    adj[v] = &(edge[++ect] = Edge(u,cap,adj[v],edge+ect-1));
}
ull n, m;
void load() {
    cin >> n >> m;
    while (m--) {
        ull a, b, c;
        cin >> a >> b >> c;
        add(a,b,c);
    }
}

ull ht[MAXV];
ull hct[MAXV];
ull vtot;
ull vs, vt;
ull aug(ull u, ull augc) {
    if (u == vt)
        return augc;
    ull tmp = augc;
    ull minht = vtot-1;
    for (Edge *t = adj[u]; t; t = t->nxt)
        if (t->cap) {
            ull v = t->vtx;
            if (ht[v]+1 == ht[u]) {
                ull d = aug(v,min(t->cap,tmp));
                tmp -= d;
                t->cap -= d;
                t->opp->cap += d;
                if (ht[vs] >= vtot)
                    return augc-tmp;
                if (!tmp)
                    return augc;
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

ull sap() {
    ull ret = 0;
    vs = 1;
    vt = n;
    vtot = n;
    hct[0] = vtot;
    while (ht[vs] < vtot) {
        ret += aug(vs,INF);
    }
    return ret;
}
ull ans;
void work() {
    ans = sap();
    cout << ans << endl;
}

int main() {
    load();
    work();
//    system("pause");
    return 0;
}
/*
4 6
1 2 3
2 3 4
3 1 2
2 2 5
3 4 3
4 3 3

5
*/
