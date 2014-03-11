/**
 * Description:
 * Source:
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
struct Edge {
    int vtx;
    int flag;
    Edge *nxt;
    Edge() {}
    Edge(int a, Edge *b, int c): vtx(a), flag(c), nxt(b) {}
} epool[MAXN*2], *adj[MAXN], *eptr = epool;

void add(int u, int v, int c) {
    adj[u] = new (eptr++) Edge(v,adj[u],c);
    adj[v] = new (eptr++) Edge(u,adj[v],c);
}
bool vis[MAXN];
vector<int> ans;
bool dfs(int u, int f) {
    vis[u] = true;
    bool chose = false;
    for (Edge *t = adj[u]; t; t = t->nxt) {
        int v = t->vtx;
        if (!vis[v]) {
            chose |= dfs(v,t->flag);
        }
    }
    if (f && !chose) {
        ans.push_back(u);
        chose = true;
    }
    return chose;
}
int n;
int main(int argc, char const *argv[]) {
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if (c == 1)
            c = 0;
        add(a,b,c);
    }
    dfs(1,0);
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d ", ans[i]);
    }
    return 0;
}