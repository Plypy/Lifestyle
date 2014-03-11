// 2-sat问题练习
// 设2i结点为通过i议案，2i-1为不通过i议案 
// note c中的scanf函数对于char类型是不跳过空字符的
// 所以就得自己管理读入了，跳过空格什么的 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int MAXN = 1010;
const int MAXM = 4010;
const int MAXV = MAXN*2;
const int MAXE = MAXM*4*2;
struct Edge {
    Edge *nxt;
    int vtx;
    Edge(int _vtx = 0, Edge *_nxt = 0):
        vtx(_vtx), nxt(_nxt) { }
} edge[MAXE], *adj[MAXV], *tadj[MAXV], *radj[MAXV];
int ect;

inline void add(int u, int v) {
    adj[u] = &(edge[++ect] = Edge(v,adj[u]));
    tadj[v] = &(edge[++ect] = Edge(u,tadj[v]));
}
inline void n_add(int u, int v) {
    radj[u] = &(edge[++ect] = Edge(v,radj[u]));
}
bool vis[MAXV];
int vlist[MAXV];

void dfs(int u) {
    vis[u] = true;
    for (Edge *t = adj[u]; t; t = t->nxt) {
        int v = t->vtx;
        if (!vis[v])
            dfs(v);
    }
    vlist[++vlist[0]] = u;
}

int color[MAXV];

void kosaraju(int u) {
    vis[u] = false;
    color[u] = color[0];
    for (Edge *t = tadj[u]; t; t = t->nxt) {
        int v = t->vtx;
        if (vis[v])
            kosaraju(v);
    }
}
inline int cal(int u) {
    if (u&1)
        return u+1;
    return u-1;
}
int n, m;
inline void load() {
    scanf("%d%d", &n, &m);
    n <<= 1;
    while (m--) {// construct the graph model
        int u, v;
        char p, q;
        char sp;
        while (getchar() != '\n')
            continue;
        scanf("%d%c%c%d%c%c", &u, &sp, &p, &v, &sp, &q);
//        cout << u << ' ' << p << ' ' << v << ' ' << q << endl;
        u <<= 1;
        v <<= 1;
        if (p != 'Y')
            u = cal(u);
        if (q != 'Y')
            v = cal(v);
        add(cal(u),v);
        add(cal(v),u);
    }
}

int opp[MAXV];
bool del[MAXV];
bool unk[MAXV];

void n_dfs(int u) {
    vis[u] = true;
    for (Edge *t = radj[u]; t; t = t->nxt) {
        int v = t->vtx;
        if (!vis[v])
            n_dfs(v);
    }
}
inline void work() {
    // using kosaraju to compute the strongly connected subgraph
    for (int i = 1; i <= n; ++i)
        if (!vis[i])
            dfs(i);
    
    for (int i = n; i; --i)
        if (vis[vlist[i]]) {
            ++color[0];
            kosaraju(vlist[i]);
        }
    // judge the feasibility
    for (int i = 1; i < n; i += 2)
        if (color[i] == color[i+1]) {
            printf("IMPOSSIBLE\n");
            return ;
        }
    // build the new graph
    for (int u = 1; u <= n; ++u) {
        opp[color[u]] = color[cal(u)];
        for (Edge *t = adj[u]; t; t = t->nxt) {
            int v = t->vtx;
            if (color[u] != color[v])
                n_add(color[u],color[v]);
        }
    }
    
    for (int i = color[0]; i; --i) {
        if (!del[i]) {
            del[opp[i]] = true;
            memset(vis,0,sizeof(vis));
            n_dfs(opp[i]);
            if (!vis[i])
                unk[i] = unk[opp[i]] = true;
        }
    }
    
    for (int i = 1; i < n; i += 2) {
        if (unk[color[i]])
            putchar('?');
        else if (del[color[i]])
            putchar('Y');
        else
            putchar('N');
    }
    putchar('\n');
}
int main() {
    load();
    work();
//    system("pause");
    return 0;
} 
/*
sample
3 4

1 Y 2 N

1 N 2 N

1 Y 3 Y

1 Y 2 Y


ans
YN?
*/
