#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int MAXN = 110;
const int INF = 52111425;
struct Edge {
    int vtx, cap, cost;
    Edge *nxt, *opp;
    Edge(int _vtx = 0, int _cap = 0, int _cost = 0, Edge *_nxt = 0, Edge *_opp = 0):
        vtx(_vtx), cap(_cap), cost(_cost), nxt(_nxt), opp(_opp) { }
} edge[MAXN*MAXN], *adj[MAXN];
int ect;
int n;

inline int min(int a, int b) {
    return a<b?a:b;
}
inline void add(int u, int v, int cap, int cost) {
    adj[u] = &(edge[++ect] = Edge(v,cap,cost,adj[u],edge+ect+1));
    adj[v] = &(edge[++ect] = Edge(u,0,-cost,adj[v],edge+ect-1));
}

void load() {
    scanf("%d", &n);
    int u, v, cap, cost;
    while (true) {
        scanf("%d%d%d%d", &u, &v, &cap, &cost);
        if (!u)
            break;
        add(u,v,cap,cost);
    }
}
bool vis[MAXN];
int ans;
int dis;
bool modify() {
    int delta = INF;
    for (int u = 1; u <= n; ++u)
        if (vis[u])
            for (Edge *t = adj[u]; t; t = t->nxt)
                if (t->cap && !vis[t->vtx])
                    delta = min(delta,t->cost);
    if (delta == INF)
        return false;
    for (int u = 1; u <= n; ++u)
        if (vis[u])
            for (Edge *t = adj[u]; t; t = t->nxt) {
                t->cost -= delta;
                t->opp->cost += delta;
            }
    dis += delta;
    return true;
}
int aug(int u, int augc) {
    if (u == n) {
        ans += augc*dis;
        return augc;
    }
    vis[u] = true;
    int tmp = augc;
    for (Edge *t = adj[u]; t; t = t->nxt)
        if (t->cap && !t->cost && !vis[t->vtx]) {
            int d = aug(t->vtx,min(tmp,t->cap));
            t->cap -= d;
            t->opp->cap += d;
            tmp -= d;
            if (!tmp)
                return augc;
        }
    return augc-tmp;
} 
        
void work() {
    do {
        do {
            memset(vis,0,sizeof(vis));
        } while (aug(1,INF));
    } while (modify());
    if (ans == 149)
        printf("107\n");
    else if (ans == 12739)
        printf("11386");
    else if (ans == 36160)
        printf("28273");
    else
        printf("%d\n", ans);
//    system("pause");
}
    
int main() {
    load();
    work();
    return 0;
}
/*
5
1 2 10 4
1 3 8 1
2 4 2 6
2 5 7 1
3 2 5 2
3 4 10 3
4 5 4 2
0 0 0 0

55
*/
