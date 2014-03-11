// 悲剧啊 已经把做法想出来了，结果还是写撮了 

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int MAXN = 1005;
const int MAXV = MAXN;
const int MAXE = MAXV*2;
bool used[MAXV];
struct Edge {
    int vtx;
    int id;
    Edge *nxt;
    Edge(int ivtx = 0, int iid = 0, Edge *inxt = 0):
        vtx(ivtx), id(iid), nxt(inxt) { }
} edge[MAXE], *adj[MAXV];
int ect;

void add(int u, int v, int id) {
    adj[u] = &(edge[++ect] = Edge(v,id,adj[u]));
    adj[v] = &(edge[++ect] = Edge(u,id,adj[v]));
}


int n, st;
void load() {
    scanf("%d%d", &n, &st);
    for (int i = 1; i < n; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a,b,i);
    }
}

bool valid[MAXV];
int pre[MAXV];

void make_tree(int u) {
    for (Edge *t = adj[u]; t; t = t->nxt)
        if (!used[t->id]) {
            used[t->id] = true;
            pre[t->vtx] = u;
            make_tree(t->vtx);
        }
}

void dfs(int u, int dep) {
    valid[u] = dep&1;
    for (Edge *t = adj[u]; t; t = t->nxt) {
        int v = t->vtx;
        if (pre[v] == u) {
            dfs(v,dep+1);
            if (dep&1)
                valid[u] &= valid[v];
            else
                valid[u] |= valid[v];
        }
    }
}
void work() {
    make_tree(st);
    dfs(st,0);
    
    
    if (!valid[st]) {
        printf("First player loses\n");
        return ;
    }
    int ans = MAXN;
    for (Edge *t = adj[st]; t; t = t->nxt)
        if (valid[t->vtx] && t->vtx < ans) {
            ans = t->vtx;
        }
    printf("First player wins flying to airport %d\n", ans);
}
            

int main() {
    load();
    work();
//    system("pause");
    return 0;
}
