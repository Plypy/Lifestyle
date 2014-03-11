/**
 * Author: Ply_py
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iomanip>
#include <queue>
#include <cmath>
using namespace std;

const int MAXN = 105;
const int MAXM = 10005;

const int MAXV = MAXN;
const int MAXE = MAXM;
struct Edge {
    int vtx;
    Edge *nxt;
    Edge(int a = 0, Edge *b = 0):
        vtx(a), nxt(b) { }
} epool[MAXE], *adj[MAXV], *eptr = epool;

void add(int u, int v) {
    adj[u] = new (eptr++) Edge(v,adj[u]);
}
void clear() {
    memset(adj,0,sizeof(adj));
    eptr = epool;
}
int n, m, k;
bool load() {
    clear();
//    cin >> n >> m >> k;
    scanf("%d%d%d", &n, &m, &k);
    if (!n)
        return false;
    for (int i = 1; i <= m; ++i) {
        int a, b;
//        cin >> a >> b;
        scanf("%d%d", &a, &b);
        add(a,b);
    }
    return true;
}
bool flag;
int pre[MAXV], que[MAXV], st, ed;
int path[MAXV][MAXV], uses[MAXV];
bool del[MAXV];
int mdel;
void bfs() {
    que[st=ed=0] = 1;
    memset(pre,0,sizeof(pre));
    int u, v;
    while (st <= ed) {
        u = que[st++];
        for (Edge *t = adj[u]; t; t = t->nxt) {
            v = t->vtx;
            if (!del[v] && !pre[v]) {
                pre[v] = u;
                que[++ed] = v;
                if (v == n)
                    return ;
            }
        }
    }
}
void dfs(int dep) {
    bfs();
    if (!pre[n]) {
        flag = true;
        return ;
    }
    int len = 0;
    for (int t = pre[n]; t != 1; t = pre[t]) {
        path[dep][++len] = t;
    }
    if (len+1 > k) {
        flag = true;
        return ;
    }
    if (dep > mdel)
        return ;
    for (int i = 1; i <= len; ++i) {
        int v = path[dep][i];
        del[v] = true;
        if (0 == uses[v])
            dfs(dep+1);
        if (flag)
            return ;
        del[v] = false;
        ++uses[v];
    }
    for (int i = 1; i <= len; ++i)
        --uses[path[dep][i]];
}
int idfs() {
    flag = false;
    for (int i = 0; i <= n; ++i) {
        mdel = i;
        memset(del,0,sizeof(del));
        memset(uses,0,sizeof(uses));
        dfs(1);
        if (flag) {
            return i;
        }
    }
    return -1;
}
void work() {
    printf("%d\n", idfs());
//    cout << idfs() << endl;
}
int main() {
    ios::sync_with_stdio(false);
    while (load()) {
        work();
    }
    return 0;
}
