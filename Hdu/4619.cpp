/**
 * Description: Consider each domino as a vertex in graph. When two dominos overlaps, connect them with a undirected edge.
 *  Then we can find those domino that overlaps ,i.e. a connected component, is a chain.
 *  For each chain, we only have to choose the odd vertex, and that will be the maximum number of remaining dominos that
 *  not overlapped.
 * Source: Hdu 4619
 * Author: Ply_py
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
using namespace std;

const int MAXL = 105;
const int MAXN = 1005;
const int MAXV = MAXN*2;
const int MAXE = MAXV*2;
struct Edge {
    int vtx;
    Edge *nxt;
    Edge() {}
    Edge(int a, Edge *b): vtx(a), nxt(b) { }
} epool[MAXE], *adj[MAXV], *eptr = epool;
void add(int u, int v) {
    adj[u] = new (eptr++) Edge(v,adj[u]);
    adj[v] = new (eptr++) Edge(u,adj[v]);
}
int hor[MAXL][MAXL];
int ver[MAXL][MAXL];
int n, m;
bool vis[MAXV];
void init() {
    memset(hor,0,sizeof(hor));
    memset(vis,0,sizeof(vis));
    memset(adj,0,sizeof(adj));
    eptr = epool;
}
int cnt;
void dfs(int u) {
    vis[u] = true;
    ++cnt;
    for (Edge *t = adj[u]; t; t = t->nxt) {
        int v = t->vtx;
        if (!vis[v]) {
            // cout << u << " connects " << v << endl;
            dfs(v);
        }
    }
}
void work() {
    n += m;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            cnt = 0;
            dfs(i);
            // cout << endl;
            // cout << "visiting " << i << ' ' << cnt << endl;
            ans += (cnt+1)/2;
        }
    }
    printf("%d\n", ans);
}
bool load() {
    scanf("%d%d", &n, &m);
    if (0 == n && 0 == m)
        return false;
    for (int i = 1; i <= n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        hor[x][y] = hor[x+1][y] = i;
    }

    for (int i = 1; i <= m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        ver[x][y] = ver[x][y+1] = i;
        int t1 = hor[x][y], t2 = hor[x][y+1];
        if (t1)
            add(n+i,t1);
        if (t2)
            add(n+i,t2);
    }
    return true;
}
int main(int argc, char const *argv[]) {
    while (load()) {
        work();
        init();
    }
    return 0;
}