#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 205;
const int MAXM = MAXN*MAXN;

struct Data {
    int u, v;
} data[MAXM];

struct Edge {
    int vtx;
    int id;
    Edge *nxt;
    Edge(int ivtx = 0, int iid = 0, Edge *inxt = 0):
        vtx(ivtx), id(iid), nxt(inxt) { }
} *adj[MAXN], edge[MAXM];
int ect;
inline void add(int u, int v, int id) {
    adj[u] = &(edge[++ect] = Edge(v,id,adj[u]));
    adj[v] = &(edge[++ect] = Edge(u,id,adj[v]));
}

int n, m;

void load() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &data[i].u, &data[i].v);
        add(data[i].u,data[i].v,i);
    }
}

bool lab[MAXM];
int ct;
bool vis[MAXN];
void dfs_build(int u) {
    vis[u] = true;
    for (Edge *t = adj[u]; t; t = t->nxt) {
        int v = t->vtx;
        int id = t->id;
        if (!vis[v]) {
            ++ct;
            lab[id] = true;
            dfs_build(v);
        }
    }
}

void build() {
    for (int i = 1; i <= n; ++i)
        if (!vis[i])
            dfs_build(i);
}

int pre[MAXN];
int dis[MAXN];
void dfs_find(int u) {
    for (Edge *t = adj[u]; t; t = t->nxt) {
        int v = t->vtx;
        int id = t->id;
        if (lab[id] && !dis[v]) {
            dis[v] = dis[u]+1;
            pre[v] = u;
            dfs_find(v);
        }
    }
}

void work() {
    build();
    
    int ans = m - ct;
    printf("%d\n", ans);
    for (int i = 1; i <= m; ++i)
        if (!lab[i]) {
            memset(dis,0,sizeof(dis));
            memset(pre,0,sizeof(pre));
            dis[data[i].u] = 1;
            dfs_find(data[i].u);
            
            printf("%d", dis[data[i].v]);
            for (int t = data[i].v; t; t = pre[t])
                printf(" %d", t);
            printf("\n");
        }
}

int main() {
    load();
    work();
//    system("pause");
    return 0;
}
