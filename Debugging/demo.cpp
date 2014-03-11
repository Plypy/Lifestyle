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

const int MAXN = 105;

vector<int> adj[MAXN];

void add(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}
bool vis[MAXN];
void dfs(int u) {
    vis[u] = true;
    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        if (!vis[v])
            dfs[v]);
    }
}