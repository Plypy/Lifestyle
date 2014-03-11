#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
using namespace std;

const int MAXN = 100;

const int MAXV = MAXN*2;
const int MAXE = MAXV*MAXV;
const int INF = 1<<28;
int vs, vt;
struct Edge {
    int vtx, cap, cost;
    Edge *nxt, *rev;
    Edge() { }
    Edge(int iv, int icap, int icost, Edge *in, Edge *ir):
        vtx(iv), cap(icap), cost(icost), nxt(in), rev(ir) { }
} epool[MAXE], *adj[MAXV], *eptr = epool;
inline void add(int u, int v, int cap, int cost) {
    adj[u] = new (eptr++) Edge(v,cap,cost,adj[u],eptr);
    adj[v] = new (eptr++) Edge(u,0,-cost,adj[v],eptr-2);
}

int pre[MAXV];
Edge *path[MAXV];
int flow;
bool inq[MAXV];
int dis[MAXV];
int spfa() {
    for (int i = vs; i <= vt; ++i)
        dis[i] = INF;
    dis[vs] = 0;
    int sum = 0;
    deque<int> que;
    que.push_front(vs);
    int u, v;
    while (!que.empty()) {
        while (dis[que.front()] > (sum/que.size())) {
            que.push_back(que.front());
            que.pop_front();
        }
        u = que.front();
        que.pop_front();
        inq[u] = false;
        sum -= dis[u];

        for (Edge *t = adj[u]; t; t = t->nxt)
            if (t->cap && dis[u]+t->cost < dis[v=t->vtx]) {
                int tmp = dis[v];
                dis[v] = dis[u]+t->cost;
                pre[v] = u;
                path[v] = t;
                sum += dis[v];
                if (!inq[v]) {
                    if (que.empty() || dis[que.front()] > dis[v])
                        que.push_front(v);
                    else
                        que.push_back(v);
                    inq[v] = true;
                } else {
                    sum -= tmp;
                }
            }
    }
    int delta = INF;
    if (INF != dis[vt]) {
        for (int v = vt; v != vs; v = pre[v])
            if (path[v]->cap < delta)
                delta = path[v]->cap;
        flow += delta;
        for (int v = vt; v != vs; v = pre[v]) {
            path[v]->cap -= delta;
            path[v]->rev->cap += delta;
        }
    }
    if (INF == dis[vt])
        return INF;
    return dis[vt]*delta;
}
int mcmf(int needed) {
    flow = 0;
    int ret = 0;
    while (true) {
        int d = spfa();
        if (d != INF)
            ret += d;
        else
            break;
    }
    if (flow < needed)
        return INF;
    return ret;
}
int n, m, k;
int want[MAXN][MAXN];
int have[MAXN][MAXN];
void init() {
    memset(adj,0,sizeof(adj));
    eptr = epool;
}
bool load() {
    scanf("%d%d%d", &n, &m, &k);
    vs = 0, vt = n+m+1;
    if (0 == n && 0 == m && 0 == k)
        return false;
    memset(want,0,sizeof(want));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= k; ++j) {
            scanf("%d", &want[i][j]);
            want[0][j] += want[i][j];
        }
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= k; ++j)
            scanf("%d", &have[i][j]);
    return true;
}
void work() {
    int ans = 0;
    bool fail = false;
    for (int t = 1; t <= k; ++t) {
        init();
        for (int i = 1; i <= m; ++i)
            if (have[i][t])
                add(vs,i,have[i][t],0);
        for (int i = 1; i <= n; ++i)
            if (want[i][t])
                add(m+i,vt,want[i][t],0);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) {
                int tmp;
                scanf("%d", &tmp);
                add(j,i+m,INF,tmp);
            }
        int d = mcmf(want[0][t]);
        if (INF != d)
            ans += d;
        else {
            fail = true;
        }
    }
    if (fail)
        printf("-1\n");
    else
        printf("%d\n", ans);
}
int main() {
    while (load()) {// only read the shopkeepers's order & the storage
        work();
    }
    return 0;
}
