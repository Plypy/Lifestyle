/**
 * Description: Finding all vertices that don't lie an any simple path between S to D
 * Source: ZOJ 3583
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

const int MAXN = 105;

bool g[MAXN][MAXN];
int N, M, S, T;


bool load() {
    if (EOF == scanf("%d%d%d%d", &N, &M, &S, &T))
        return false;
    ++S, ++T;
    for (int i = 1; i <= M; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        ++a, ++b;
        g[a][b] = g[b][a] = true;
    }
    return true;
}
bool ct[MAXN];
int pre[MAXN];
bool in[MAXN];
int ans = 0;
void dfs(int u) {
    if (ct[u] || u == T) {
        u = pre[u];
        while (!ct[u]) {
            ct[u] = true;
            ++ans;
            u = pre[u];
        }
        return ;
    }
    in[u] = true;
    for (int v = 1; v <= N; ++v) {
        if (g[u][v] && !in[v]) {
            pre[v] = u;
            dfs(v);
        }
    }
    in[u] = false;
}
void work() {
    ct[0] = true;
    dfs(S);
    ans = N-ans-1;
    printf("%d\n", ans);
}
void init() {
    ans = 0;
    memset(g,0,sizeof(g));
    memset(pre,0,sizeof(pre));
    memset(ct,0,sizeof(ct));
}
int main() {
    ios::sync_with_stdio(false);
    while (load()) {
        work();
        // for (int i = 1; i <= N; ++i)
        //     cout << i << ' ' << ct[i] << endl;
        init();
    }
}