#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <queue>
using namespace std;
const int MAXN = 1005;
const int MAXM = 100005;

struct Edge {
    int vtx;
    Edge *nxt;
    Edge(int ivtx = 0, Edge *inxt = 0): vtx(ivtx), nxt(inxt) { }
} edge[MAXM], *adj[MAXN];
int ect;
inline void addedge(int u, int v) {
    adj[u] = &(edge[++ect] = Edge(v,adj[u]));
}

struct Data {
    int u, v;
} data[MAXM];
int pos[MAXN];
int n, m;

void load() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &data[i].u, &data[i].v);
        addedge(data[i].u,data[i].v);
    }
    for (int i = 1; i <= n; ++i) {
        int t;
        scanf("%d", &t);
        pos[t] = i;
    }
}

bool loop;
int color[MAXN];
const int WHITE = 0;
const int GREY = 1;
const int BLACK = 2;
void dfs(int u) {
    color[u] = GREY;
    for (Edge *t = adj[u]; t; t = t->nxt) {
        int v = t->vtx;
        if (WHITE == color[v])
            dfs(v);
        else if (GREY == color[v])
            loop = true;
    }
    color[u] = BLACK;
}
bool check_loop() {
    for (int u = 1; u <= n; ++u)
        if (WHITE == color[u]) {
            dfs(u);
            if (loop)
                break;
        }
    return loop;
}
void work() {
    if (!check_loop()) {
        bool suc = true;
        for (int i = 1; i <= m; ++i)
            if (pos[data[i].u] > pos[data[i].v]) {
                suc = false;
                break;
            }
        if (suc)
            printf("YES\n");
        else
            printf("NO\n");
    } else {
        printf("NO\n");
    }
}
int main() {
    load();
    work();
//    system("pause");
    return 0;
}
