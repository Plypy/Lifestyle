// Note: 大傻逼。。。
// 只是马虎掉了一个color～，就浪费了大半天 
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAXN 35
#define MAXV MAXN*2
#define MAXE MAXV*MAXV*2

struct Edge {
    int vtx;
    Edge *nxt;
    Edge(int ivtx = 0, Edge *inxt = 0):
        vtx(ivtx), nxt(inxt) { }
} edge[MAXE], *adj[MAXV], *tadj[MAXV];
int ect;
inline void add(int u, int v) {
    adj[u] = &(edge[++ect] = Edge(v,adj[u]));
    tadj[v] = &(edge[++ect] = Edge(u,tadj[v]));
}

int n, m;
inline int pal(int a) {
    if (a&1)
        return a+1;
    return a-1;
}
bool load() {
    scanf("%d%d", &n, &m);
    if (!n)
        return false;
    add(1,2);// groom to bride for bride must being chosen
    for (int i = 1; i <= m; ++i) {//2(i+1)-1 male 2(i+1) female
        int a, b;
        char p, q;
        scanf("%d%c%d%c", &a, &p, &b, &q);
        a = (a+1)<<1;
        if ('h' == p)
            --a;
        b = (b+1)<<1;
        if ('h' == q)
            --b;
        add(pal(a),b);
        add(pal(b),a);
    }
    return true;
}

int color[MAXV];
int table[MAXV];
bool vis[MAXV];
int opp[MAXV];
bool del[MAXV];

inline void recover() {
    ect = 0;
    memset(adj,0,sizeof(adj));
    memset(tadj,0,sizeof(tadj));
    
    memset(color,0,sizeof(color));
    memset(table,0,sizeof(table));
    memset(vis,0,sizeof(vis));
    memset(opp,0,sizeof(opp));
    memset(del,0,sizeof(del));
}

void dfs(int u) {
    vis[u] = true;
    for (Edge *t = adj[u]; t; t = t->nxt) {
        int v = t->vtx;
        if (!vis[v])
            dfs(v);
    }
    table[++table[0]] = u;
}

void kosaraju(int u) {
    vis[u] = false;
    color[u] = color[0];
    for (Edge *t = tadj[u]; t; t = t->nxt) {
        int v = t->vtx;
        if (vis[v])
            kosaraju(v);
    }
}

void work() {
    n <<= 1;
    for (int i = 1; i <= n; ++i)
        if (!vis[i])
            dfs(i);
    for (int i = n; i; --i)
        if (vis[table[i]]) {
            ++color[0];
            kosaraju(table[i]);
        }
    
    for (int i = 1; i < n; i += 2)
        if (color[i] == color[i+1]) {
            printf("bad luck\n");
            return ;
        }
    
    for (int i = 1; i <= n; ++i)
        opp[color[i]] = color[pal(i)];
    for (int i = color[0]; i; --i)
        if (!del[i])
            del[opp[i]] = true;
    
    bool first = true;
    for (int i = 3; i < n; i += 2) {
        if (first)
            first = false;
        else
            putchar(' ');
        printf("%d", i>>1);
        putchar(del[color[i]]?'w':'h');
    }
    putchar('\n');
}

int main() {
    while (load()) {
        work();
        recover();
    }
}
