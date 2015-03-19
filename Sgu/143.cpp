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

const int MAXN = 16005;
int f[MAXN];
int wt[MAXN];
int n;
bool vis[MAXN];

int nxt[MAXN*2];
int vtx[MAXN*2];
int adj[MAXN*2];

void add(int a, int b) {
    // a->b
    vtx[++vtx[0]] = b;
    nxt[vtx[0]] = adj[a];
    adj[a] = vtx[0];
    // b->a
    vtx[++vtx[0]] = a;
    nxt[vtx[0]] = adj[b];
    adj[b] = vtx[0];
}

int dp(int u) {
    vis[u] = true;
    int sum = 0;
    for (int t = adj[u]; t; t = nxt[t]) {
        int v = vtx[t];
        if (!vis[v]) {
            sum += max(0, dp(v));
        }
    }
    return f[u] = sum+wt[u];
}

void load() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", wt+i);
    }
    for (int i = 1; i < n; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a,b);
    }
}

void work() {
    dp(1);
    int ans = wt[1];
    for (int i = 1; i <= n; ++i) {
        ans = min(ans, wt[i]);
    }
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, f[i]);
    }
    printf("%d\n", ans);
}

int main() {
    load();
    work();
}
