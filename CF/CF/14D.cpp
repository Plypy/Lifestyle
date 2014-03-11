//≥ı ºªØ°≠°≠
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;
const int MAXN = 205;
typedef pair<int,int> Edge;
vector<Edge> adj[MAXN];
bool del[MAXN];
int st[MAXN], ed[MAXN];
int n;
void load() {
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].push_back(make_pair(b,i));
        adj[b].push_back(make_pair(a,i));
        st[i] = a;
        ed[i] = b;
    }
}
int used[MAXN];
int dis[MAXN];
int farthest;
void dfs(int u) {
    used[u] = true;
    for (vector<Edge>::iterator itr = adj[u].begin(); itr != adj[u].end(); ++itr) {
        int v = itr->first;
        int id = itr->second;
        if (0 == del[id] && 0 == used[v]) {
            dis[v] = dis[u]+1;
            if (dis[v] > dis[farthest])
                farthest = v;
            dfs(v);
        }
    }
}
void work() {
    int ans = 0;
    for (int t= 1; t < n; ++t) {
        memset(used,0,sizeof(used));
        memset(dis,0,sizeof(dis));
        del[t] = true;
        farthest = st[t];
        dfs(st[t]);
        memset(used,0,sizeof(used));
        memset(dis,0,sizeof(dis));
        dfs(farthest);
        int tans = dis[farthest];

        memset(dis,0,sizeof(dis));
        memset(used,0,sizeof(used));
        farthest = ed[t];
        dfs(ed[t]);
        memset(dis,0,sizeof(dis));
        memset(used,0,sizeof(used));
        dfs(farthest);
        tans *= dis[farthest];
        if (tans > ans)
            ans = tans;
        del[t] = false;
    }
    printf("%d\n", ans);
}
int main() {
    load();
    work();
    return 0;
}
