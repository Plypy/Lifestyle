#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;
const int MAXN = 200;
bool flag[MAXN];
int n, m;
vector<int> adj[MAXN];
int col[MAXN], cur_col;
void dfs(int u) {
    col[u] = cur_col;
    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        if (!col[v])
            dfs(v);
    }
}
int main() {
    cin >> n >> m;
    int sb = 0;
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        if (0 == k)
            ++sb;
        int t[MAXN];
        for (int j = 1; j <= k; ++j) {
            cin >> t[j];
            flag[t[j]] = true;
        }
        for (int j = 2; j <= k; ++j) {
            adj[t[j]].push_back(t[j-1]);
            adj[t[j-1]].push_back(t[j]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (flag[i] && !col[i]) {
            ++cur_col;
            dfs(i);
        }
    }
    if (0 == cur_col)
        ++cur_col;
    cout << cur_col-1+sb << endl;
    return 0;
}
