// 2-sat 我的空间消耗怎么就那么丑陋... 
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;
#define MAXN 1005
#define MAXM 1000005
#define MAXV MAXN*2
#define MAXE MAXM*4

struct Edge {
    int vtx;
    Edge *nxt;
    Edge(int ivtx = 0, Edge *inxt = 0):
        vtx(ivtx), nxt(inxt) { }
} edge[MAXE], *adj[MAXV];
int ect;
inline void add(int u, int v) {
    adj[u] = &(edge[++ect] = Edge(v,adj[u]));
}


int n, m;
void build() {
    scanf("%d%d", &n, &m);
    while (m--) {// 2*i-1 represents 0, while 2*i represents 1
        int a, b, c;
        char type[4];
        scanf("%d%d%d%s", &a, &b, &c, type);
        ++a, ++b;
        if ('A' == type[0]) {// and
            if (c) {
                add(2*a-1,2*a);
                add(2*b-1,2*b);
            } else {
                add(2*a,2*b-1);
                add(2*b,2*a-1);
            }
        } else if ('O' == type[0]) {// or
            if (c) {
                add(2*a-1,2*b);
                add(2*b-1,2*a);
            } else {
                add(2*a,2*a-1);
                add(2*b,2*b-1);
            }
        } else {// xor
            if (c) {
                add(2*a-1,2*b);
                add(2*b-1,2*a);
                add(2*a,2*b-1);
                add(2*b,2*a-1);
            } else {
                add(2*a-1,2*b-1);
                add(2*b,2*a);
                add(2*a,2*b);
                add(2*b-1,2*a-1);
            }
        }
    }
}

int dfn[MAXV];
int low[MAXV];
int stack[MAXV];
bool ins[MAXV];
int color[MAXV];

void tarjan(int u) {
    dfn[u] = low[u] = ++dfn[0];
    stack[++stack[0]] = u;
    ins[u] = true;
    for (Edge *t = adj[u]; t; t = t->nxt) {
        int v = t->vtx;
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u],low[v]);
        } else if (ins[v])
            low[u] = min(low[u],dfn[v]);
    }
    if (dfn[u] == low[u]) {
        ++color[0];
        int v;
        do {
            v = stack[stack[0]--];
            ins[v] = false;
            color[v] = color[0];
        } while (u != v);
    }
}

bool solve() {
    int vtot = 2*n;
    for (int i = 1; i <= vtot; ++i)
        if (!dfn[i])
            tarjan(i);
    
    for (int i = 1; i < vtot; i += 2)
        if (color[i] == color[i+1])
            return false;
    return true;
}

void work() {
    build();
    if (solve())
        printf("YES\n");
    else
        printf("NO\n");
}

int main() {
    work();
    return 0;
}
/*
4 4
0 1 1 AND
1 2 1 OR
3 2 0 AND
3 0 0 XOR

YES
*/
