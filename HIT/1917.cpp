// ´ËÌâÊÇÒ»¸ö±ê×¼µÄ2-SAT ÎÊÌâ
// ½â·¨Ïê¼û wc2003 ÎéêÅÂÛÎÄ
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 8001;
const int MAXM = 20001;
const int MAXV = MAXN*2;
const int MAXE = MAXM*6;
inline int cal(int a) {
    if (a&1)
        return a+1;
    return a-1;
}
int e[MAXE], nxt[MAXE];
int adj[MAXV], tadj[MAXV];
int cnt;
inline void add(int u, int v) {
    e[++cnt] = v;
    nxt[cnt] = adj[u];
    adj[u] = cnt;

    e[++cnt] = u;
    nxt[cnt] = tadj[v];
    tadj[v] = cnt;
}
bool used[MAXV];
int color[MAXV];
int opp[MAXV];
bool del[MAXV];
int table[MAXV];

int n, m;
void load() {
    n *= 2;

    cnt = table[0] = color[0] = 0;
    memset(adj,0,sizeof(adj));
    memset(tadj,0,sizeof(tadj));
    memset(del,0,sizeof(del));

    int a, b;
    while (m--) {
        scanf("%d%d", &a, &b);
        add(a,cal(b));
        add(b,cal(a));
    }
}
void dfs(int u) {
    used[u] = true;
    for (int t = adj[u]; t; t = nxt[t]) {
        int v = e[t];
        if (!used[v])
            dfs(v);
    }
    table[++table[0]] = u;
}
void kosaraju(int u) {
    used[u] = false;
    color[u] = color[0];
    for (int t = tadj[u]; t; t = nxt[t]) {
        int v = e[t];
        if (used[v])
            kosaraju(v);
    }
}
void solve() {
    // use the kosaraju algorithm to compute the strongly connected components and
    // topsort the graph
    for (int i = 1; i <= n; ++i)
        if (!used[i])
            dfs(i);
    for (int i = n; i; --i)
        if (used[table[i]]) {
            ++color[0];
            kosaraju(table[i]);
        }
    // judge the feasibility
    for (int i = 1; i < n; i += 2)
        if (color[i] == color[i+1]) {
            printf("NIE\n");
            return;
        }
    // compute each subgraph's symmetry subgraph
    for (int i = 1; i <= n; ++i)
        opp[color[i]] = color[cal(i)];
    // by the reverse order computed by topsort to construct a feasible solution
    for (int i = color[0]; i; --i)
        if (!del[i])
            del[opp[i]] = true;
    // simply output
    for (int i = 1; i <= n; ++i)
        if (!del[color[i]])
            printf("%d\n", i);
}
int main() {
    while (EOF != scanf("%d%d", &n, &m)) {
        load();
        solve();
    }
    return 0;
}

