#include <bits/stdc++.h>
using namespace std;

#define MP(a,b) make_pair((a), (b))
#define X first
#define Y second

typedef long long ll;
const int MAXN = 1e5+5;
const int MAXE = 2*MAXN;

int n;

typedef pair<int, int> pi;

vector<pi> adj[MAXN];

void add(int u, int v, int len)
{
    adj[u].push_back(MP(v,len));
    adj[v].push_back(MP(u,len));
}

int farthest;
int root;
ll dp[MAXN][2];
ll dis[MAXN];

void dfs1(int u, int p)
{
    int sz = adj[u].size();
    for (int i = 0; i < sz; ++i) {
        int v = adj[u][i].X;
        int l = adj[u][i].Y;
        if (v == p) {
            continue;
        }
        dfs1(v, u);
        ll tmp = l+dp[v][0];
        if (tmp > dp[u][0]) {
            dp[u][1] = dp[u][0];
            dp[u][0] = tmp;
        } else if (tmp > dp[u][1]) {
            dp[u][1] = tmp;
        }
    }
}

void dfs2(int u, int p, ll dd)
{
    dis[u] = max(dp[u][0], dd);
    int sz = adj[u].size();
    for (int i = 0; i < sz; ++i) {
        int v = adj[u][i].X;
        int l = adj[u][i].Y;
        if (v == p) {
            continue;
        }
        if (dp[v][0] + l == dp[u][0]) {
            dfs2(v, u, max(dd, dp[u][1])+l);
        } else {
            dfs2(v, u, max(dd, dp[u][0])+l);
        }
    }
}


int rt[MAXN];
void build(int u, int p)
{
    int sz = adj[u].size();
    for (int i = 0; i < sz; ++i) {
        int v = adj[u][i].X;
        if (v == p) {
            continue;
        }
        rt[v] = u;
        build(v,u);
    }
}

int fa[MAXN];
int num[MAXN];
void init()
{
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
        num[i] = 1;
    }
}

int find(int u)
{
    if (u == fa[u]) {
        return u;
    }
    return fa[u] = find(fa[u]);
}

int merge(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v) {
        return 0;
    }
    fa[u] = v;
    num[v] += num[u];
    return 1;
}

void work()
{
    dfs1(1, 1);
    dfs2(1, 1, 0);
    root = 1;
    for (int i = 2; i <= n; ++i) {
        if (dis[i] < dis[root]) {
            root = i;
        }
    }

    build(root, root);

    vector< pair<ll, int> > vec;
    for (int i = 1; i <= n; ++i) {
        vec.push_back(MP(dis[i], i));
    }
    sort(vec.begin(), vec.end());
    // for (int i = 1; i <= n; ++i) {
    //     cout << dis[i] << ' ' << rt[i] << endl;
    // }

    int q;
    scanf("%d", &q);
    while (q--) {
        ll L;
        scanf("%I64d", &L);
        init();
        int ans = 0;
        int top = vec.size()-1;
        for (int i = top; i >= 0; --i) {
            int u = vec[i].Y;
            int len = adj[u].size();
            for (int j = 0; j < len; ++j) {
                int v = adj[u][j].X;
                if (v == rt[u]) {
                    continue;
                }
                merge(v, u);
            }
            while (vec[top].X - vec[i].X > L) {
                --num[find(vec[top].Y)];
                --top;
            }
            ans = max(ans, num[find(u)]);
        }
        printf("%d\n", ans);
    }
}

void load()
{
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a,b,c);
    }
}

int main()
{
    load();
    work();
}
