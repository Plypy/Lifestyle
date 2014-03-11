#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

const int MAXN = 100005;
const int MAXE = MAXN*2;
const int MAXV = MAXN;
struct Edge {
    int vtx, id;
    Edge *nxt;
    Edge(int ivtx = 0, int iid = 0, Edge *inxt = 0):
        vtx(ivtx), id(iid), nxt(inxt) { }
} epool[MAXE], *adj[MAXV], *eptr = epool;
inline void add(int u, int v, int id) {
    adj[u] = new (eptr++) Edge(v,id,adj[u]);
    adj[v] = new (eptr++) Edge(u,id,adj[v]);
}
int n;
int st[MAXV], ed[MAXV];
void load() {
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        scanf("%d%d", st+i, ed+i);
        add(st[i],ed[i],i);
    }
}
int del[MAXV];
bool used[MAXV];
int dis[MAXV];
int farthest;
void dfs(int u) {
    used[u] = true;
    for (Edge *t = adj[u]; t; t = t->nxt) {
        int v = t->vtx;
        int id = t->id;
        if (del[id] || used[v])
            continue;
        dis[v] = dis[u]+1;
        if(dis[v] > dis[farthest])
            farthest = v;
        dfs(v);
    }
}
inline void init() {
    memset(dis,0,sizeof(dis));
    memset(used,0,sizeof(used));
}
void work() {
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        del[i] = true;
        init();
        farthest = st[i];
        dfs(st[i]);
        init();
        dfs(farthest);
        int tans = dis[farthest];

        farthest = ed[i];
        dfs(ed[i]);
        init();
        dfs(farthest);
        tans *= dis[farthest];
        if (tans > ans)
            ans = tans;
        del[i] = false;
    }
    printf("%d\n", ans);
}
int main() {
    load();
    work();
    return 0;
}
