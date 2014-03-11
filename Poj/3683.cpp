// 依然是丑陋的时间与空间- - 不过是1A就好～ 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAXN 1005
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

struct Wedding {
    int bg, ed;
    Wedding(int ibg = 0, int ied = 0):
        bg(ibg), ed(ied) { }
    friend bool conflict(const Wedding &a, const Wedding &b) {
        if (a.bg >= b.ed || b.bg >= a.ed)
            return false;
        return true;
    }
} wedding[MAXV];
inline int get_other(int a) {
    if (a&1)
        return a+1;
    return a-1;
}

int n;
void build() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int a, b, c, d, e;
        scanf("%d:%d%d:%d%d", &a, &b, &c, &d, &e);
        a = a*60+b;
        c = c*60+d;
        wedding[2*i-1] = Wedding(a,a+e);
        wedding[2*i] = Wedding(c-e,c);
    }
    n <<= 1;
    for (int i = 1; i < n; ++i)
        for (int j = i+1; j <= n; ++j)
            if (conflict(wedding[i],wedding[j])) {
                add(i,get_other(j));
                add(j,get_other(i));
            }
}

int table[MAXV];
bool vis[MAXV];
int color[MAXV];
int opp[MAXV];
bool del[MAXV];

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
            printf("NO\n");
            return;
        }
    printf("YES\n");
    for (int i = 1; i <= n; ++i)
        opp[color[i]] = color[get_other(i)];
    
    for (int i = color[0]; i; --i)
        if (!del[i])
            del[opp[i]] = true;
    
    for (int i = 1; i < n; i += 2) {
        int a, b, c, d;
        int choice;
        if (del[color[i]]) {
            choice = i+1;
        } else {
            choice = i;
        }
        a = wedding[choice].bg/60;
        b = wedding[choice].bg%60;
        c = wedding[choice].ed/60;
        d = wedding[choice].ed%60;
        printf("%02d:%02d %02d:%02d\n", a,b,c,d);
    }
//    system("pause");
}
int main() {
    build();
    work();
    return 0;
}
/*
2
08:00 09:00 30
08:15 09:00 20


YES
08:00 08:30
08:40 09:00
*/
