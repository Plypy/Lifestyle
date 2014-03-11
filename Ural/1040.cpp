
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int MAXN = 55;
const int MAXM = 2*MAXN*MAXN;

int col[MAXM];
int ct;
struct Edge {
    int vtx;
    int id;
    Edge *nxt;
    Edge(int ivtx = 0, int iid = 0, Edge *inxt = 0):
        vtx(ivtx), id (iid), nxt(inxt) { }
} edge[MAXM*2], *adj[MAXN];
int ect;

void add(int u, int v, int id) {
    adj[u] = &(edge[++ect] = Edge(v,id,adj[u]));
    adj[v] = &(edge[++ect] = Edge(u,id,adj[v]));
}

bool used[MAXN];
void dfs(int u) {
    used[u] = true;
    for (Edge *t = adj[u]; t; t = t->nxt) {
        int v = t->vtx;
        if (!col[t->id])
            col[t->id] = ++ct;
        if (!used[v]) {
            dfs(v);
        }
    }
}

int n, m;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int a, b;
        scanf("%d%d", &a,&b);
        add(a,b,i);
    }
    for (int i = 1; i <= n; ++i)
        if (!used[i])
            dfs(i);
    
    printf("YES\n");
    for (int i = 1; i <= m; ++i) {
        if (i != 1)
            putchar(' ');
        printf("%d", col[i]);
    }
    printf("\n");
//    system("pause");
    return 0;
}
