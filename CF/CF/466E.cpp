/**
 * Description:
 * ProblemName:
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
#include <vector>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];

void add(int u, int v) {
    adj[u].push_back(v);
}

int fa[MAXN];

int find(int a) {
    if (fa[a] == 0) {
        return a;
    }
    return fa[a] = find(fa[a]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    fa[a] = b;
}

int bg[MAXN];
int ed[MAXN];
int deg[MAXN];
int dfst;
void dfs(int u) {
    bg[u] = ++dfst;
    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        if (!bg[v]) {
            dfs(v);
        }
    }
    ed[u] = ++dfst;
}

bool check(int u, int v) {
    if (bg[v] >= bg[u] && ed[v] <= ed[u]) {
        return true;
    }
    return false;
}

int query[MAXN][3];
int gived[MAXN];
vector<int> nquery[MAXN];
vector<int> iquery[MAXN];
bool ans[MAXN];

int n, m;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d", query[i]);
        if (2 == query[i][0]) {
            scanf("%d", query[i]+1);
            gived[++gived[0]] = query[i][1];
        } else {
            scanf("%d%d", query[i]+1, query[i]+2);
            if (1 == query[i][0]) {
                ++deg[query[i][1]];
                add(query[i][2], query[i][1]);
            } else {
                nquery[query[i][2]].push_back(query[i][1]);
                iquery[query[i][2]].push_back(i);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (0 == deg[i] && 0 == bg[i]) {
            dfs(i);
        }
    }
    int ict = 0;
    for (int i = 1; i <= m; ++i) {
        int t = query[i][0];
        if (1 == t) {
            merge(query[i][1], query[i][2]);
        } else if (2 == t) {
            int idx = ++ict;
            int v = query[i][1];
            for (int j = 0; j < nquery[idx].size(); ++j) {
                int u = nquery[idx][j];
                int ansi = iquery[idx][j];
                ans[ansi] = (check(u,v) && find(u) == find(v));
            }
        }
    }
    for (int i = 1; i <= m; ++i) {
        if (3 == query[i][0]) {
            if (ans[i]) {
                puts("YES");
            } else {
                puts("NO");
            }
        }
    }
}
