//注意细节问题
//现在做题手感很生啊
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN = 105;
const int MAXM = 105;

const int INF = 1<<28;
const int MAXV = MAXN;
const int MAXE = MAXM*MAXN*MAXN;
struct Edge {
    int vtx;
    Edge *nxt;
    Edge() {}
    Edge(int iv, Edge *in):
        vtx(iv), nxt(in) { }
} epool[MAXE], *adj[MAXV], *eptr = epool;
void add(int u, int v) {
    adj[u] = new (eptr++) Edge(v,adj[u]);
    adj[v] = new (eptr++) Edge(u,adj[v]);
}
void init() {
    memset(adj,0,sizeof(adj));
    eptr = epool;
}
int n, m, k;

const int UNIT = 4;
bool got_mt[MAXN];
int maxdis[MAXN];
int st[MAXN];
void load() {
    scanf("%d%d", &n, &m);
    for (int p = 0; p < m; ++p) {
        int t;
        int buf[MAXN];
        scanf("%d", &t);
        for (int i = 0; i < t; ++i)
            scanf("%d", buf+i);
        for (int i = 0; i < t; ++i)
            for (int j = i+1; j < t; ++j)
                add(buf[i],buf[j]);
    }
    scanf("%d", &k);
    for (int i = 1; i <= k; ++i) {
        scanf("%d%d%d", maxdis+i, st+i, got_mt+i);
        maxdis[i] /= UNIT;
    }
}
int dis[MAXN][MAXN];
bool used[MAXN];
void bfs(int a) {
    memset(used,0,sizeof(used));
    queue<int> que;
    que.push(a);
    used[a] = true;
    dis[a][a] = 0;
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (Edge *t = adj[u]; t; t = t->nxt) {
            int v = t->vtx;
            if (!used[v]) {
                dis[a][v] = dis[a][u]+1;
                que.push(v);
                used[v] = true;
            }
        }
    }
}
bool checked[MAXN];
int eval(int dest) {
    int ret = 0;
    for (int i = 1; i <= k; ++i) {
        if (-1 == dis[st[i]][dest])
            return INF;
        if (!got_mt[i]) {
            if (dis[st[i]][dest] > maxdis[i])
                return INF;
            ret += dis[st[i]][dest];
        }
    }
    return ret;
}
void work() {
    memset(dis,-1,sizeof(dis));
    for (int i = 1; i <= k; ++i) {
        if (!checked[st[i]]) {
            checked[st[i]] = true;
            bfs(st[i]);
        }
    }
    int ans = INF, pos = 0;
    for (int i = 1; i <= n; ++i) {
        int tmp = eval(i);
        if (tmp < ans) {
            ans = tmp;
            pos = i;
        }
    }
    if (ans != INF)
        printf("%d %d\n", pos, ans*UNIT);
    else
        printf("0\n");
}
int main() {
    load();
    work();
    return 0;
}
