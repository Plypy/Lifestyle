/**
 * author: Ply_py
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
#include <climits>
using namespace std;
const int MAXN = 1005;
const int INF = INT_MAX; // a very big number
int n, t;
int g[MAXN][MAXN]; // 2 dimension array used to store the graph
int dis[MAXN];
void load() {
    cin >> t >> n;
    // do the initialization
    for (int i = 2; i <= n; ++i) dis[i] = INF;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            g[i][j] = INF;
    // load the data
    for (int i = 1; i <= t; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        if (g[a][b] > c) // there might be duplicate edges, wo choose the shortest one
            g[a][b] = g[b][a] = c;
    }
}
bool used[MAXN];
void work() {
    while (true) {
        // select the nearest vertex that hasn't been used yet
        int minu = -1;
        int u;
        for (u = 1; u <= n; ++u) {
            if (!used[u]) {
                if (-1 == minu || dis[u] < dis[minu]) {
                    minu = u;
                }
            }
        }
        u = minu;
        if (u == n) // we have got the destination
            break;
        used[u] = true;
        // do the relax operation
        for (int v = 1; v <= n; ++v)
            if (g[u][v] != INF) {
                if (dis[v] > dis[u]+g[u][v]) {
                    dis[v] = dis[u]+g[u][v];
                }
            }
    }
    cout << dis[n] << endl;
}
int main() {
    load();
    work();
    return 0;
}
