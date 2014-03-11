/**
 * Description: Find the minimum step that could visit
 * Source: Hdu 4607
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

const int MAXN = 100005;
const int MAXV = MAXN;
const int MAXE = MAXV*2;
struct Edge {
    int vtx;
    Edge *nxt;
    Edge() { }
    Edge(int a, Edge *b): vtx(a), nxt(b) { }
} epool[MAXE], *adj[MAXV], *eptr;
void init() {
    memset(adj,0,sizeof(adj));
    eptr = epool;
}
void add(int u, int v) {
    adj[u] = new (eptr++) Edge(v,adj[u]);
    adj[v] = new (eptr++) Edge(u,adj[v]);
}
int dis[MAXV];
int que[MAXV], st, ed;
bool vis[MAXV];
int bfs(int vs) {
    int ret = vs;
    memset(dis,0,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[vs] = 0;
    vis[vs] = true;
    que[st=ed=0]=vs;
    while (st<=ed) {
        int u = que[st++];
        for (Edge *t = adj[u]; t; t = t->nxt) {
            int v = t->vtx;
            if (!vis[v]) {
                vis[v] = true;
                dis[v] = dis[u]+1;
                if (dis[v] > dis[ret]) {
                    ret = v;
                }
                que[++ed] = v;
            }
        }
    }
    return ret;
}
int n, m;
int main(int argc, char const *argv[]) {
    int T;
    scanf("%d", &T);
    while (T--) {
        init();
        scanf("%d%d", &n, &m);
        for (int i = 1; i < n; ++i) {
            int a, b;
            scanf("%d%d", &a, &b);
            add(a,b);
        }
        int t = bfs(1);
        t = bfs(t);
        int mnum = dis[t]+1;
        for (int i = 1; i <= m; ++i) {
            scanf("%d", &t);
            int ans = 0;
            if (t <= mnum) {
                ans = t-1;
            } else {
                ans = mnum-1+2*(t-mnum);
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}