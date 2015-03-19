/**
 * Use binary rise to find the LCA
 **/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;
const int MAXD = 20;
typedef long long ll;

vector<int> adj[MAXN];

int depth[MAXN];
int size[MAXN];
int anc[MAXN][MAXD];

int tin[MAXN];
int tout[MAXN];
int timer;

int n;

void dfs(int u, int fa, int d)
{
    depth[u] = d;
    tin[u] = ++timer;
    size[u] = 1;

    anc[u][0] = fa;
    for (int i = 1; i < MAXD; ++i) {
        anc[u][i] = anc[anc[u][i-1]][i-1];
    }

    int len = adj[u].size();
    for (int i = 0; i < len; ++i) {
        int v = adj[u][i];
        if (v != fa) {
            dfs(v, u, d+1);
            size[u] += size[v];
        }
    }

    tout[u] = ++timer;
}

bool check(int fa, int son)
{
    if (tin[fa] <= tin[son] && tin[son] <= tout[fa]) {
        return true;
    }
    return false;
}

int go_up(int a, int b)
{
    for (int i = MAXD-1; i>=0; --i) {
        if (!check(anc[a][i], b)) {
            a = anc[a][i];
        }
    }
    return a;
}

int lca(int a, int b)
{
    if (check(a,b)) {
        return a;
    }
    if (check(b,a)) {
        return b;
    }
    return anc[go_up(a,b)][0];
}

int query(int a, int b)
{
    if (a == b) {
        return n;
    }
    int c = lca(a,b);
    int dist = depth[a]+depth[b]-2*depth[c];
    if (dist&1) {
        return 0;
    }
    if (depth[a] == depth[b]) {
        a = go_up(a,c);
        b = go_up(b,c);
        return n-size[a]-size[b];
    }
    if (depth[a] < depth[b]) {
        swap(a,b);
    }
    dist >>= 1;
    int cur = a;
    for (int i = MAXD-1; i >= 0; --i) {
        if (depth[a] - depth[anc[cur][i]] < dist) {
            cur = anc[cur][i];
        }
    }
    int mid = anc[cur][0];
    return size[mid]-size[cur];
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 1, 0);
    // for (int i = 1; i <= n; ++i) {
    //     cout << i << ' ' << size[i] << ' ' << depth[i] << endl;
    //     for (int j = 0; j < 3; ++j) {
    //         cout << "ancestors " << anc[i][j] << ' ' ;
    //     }
    //     cout << endl;
    // }
    int m;
    cin >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        cout << query(a,b) << endl;
    }
    return 0;
}
