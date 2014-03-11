#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;
const int MAXN = 100005;
typedef long long LL;
LL n;
vector<LL> adj[MAXN];
LL val[MAXN];
void load() {
    cin >> n;
    for (LL i = 1; i < n; ++i) {
        LL a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (LL i = 1; i <= n; ++i)
        cin >> val[i];
}
LL add[MAXN], sub[MAXN];
bool vis[MAXN];
void dfs(LL u) {
    vis[u] = true;
    for (LL i = 0; i < adj[u].size(); ++i) {
        LL v = adj[u][i];
        if (!vis[v]) {
            dfs(v);
            add[u] = max(add[u],add[v]);
            sub[u] = max(sub[u],sub[v]);
        }
    }
    LL delta = add[u]-sub[u];
    LL t = val[u]+delta;
    if (t > 0)
        sub[u] += t;
    else
        add[u] -= t;
}
void work() {
    dfs(1);
    cout << add[1]+sub[1] << endl;
}
int main() {
    ios::sync_with_stdio(false);
    load();
    work();
    return 0;
}
