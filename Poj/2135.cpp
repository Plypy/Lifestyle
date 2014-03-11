#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <deque>
using namespace std;

const int MAXN = 1005;
const int MAXM = 10005;

const int MAXV = MAXN;
const int MAXE = MAXM*4;
const int INF = 1<<28;
int vs, vt;
struct Edge {
    int vtx, cap, cost;
    Edge *nxt, *rev;
    Edge() { }
    Edge(int iv, int icap, int icost, Edge *in, Edge *ir):
        vtx(iv), cap(icap), cost(icost), nxt(in), rev(ir) { }
} epool[MAXE], *adj[MAXV], *eptr = epool, *path[MAXV];
inline void add(int u, int v, int cap, int cost) {
    adj[u] = new (eptr++) Edge(v,cap,cost,adj[u],eptr);
    adj[v] = new (eptr++) Edge(u,0,-cost,adj[v],eptr-2);
}
bool inq[MAXV];
int dis[MAXV];
int pre[MAXV];

int spfa() {
    for (int i = vs; i <= vt; ++i)
        dis[i] = INF;
    dis[vs] = 0;
    memset(inq,0,sizeof(inq));
    memset(pre,0,sizeof(pre));

    deque<int> que;
    que.push_front(vs);
    int sum = 0;
    int u, v;
    while (!que.empty()) {
        while (dis[que.front()] > (sum/que.size())) {
            que.push_back(que.front());
            que.pop_front();
        }
        u = que.front();
        que.pop_front();
        sum -= dis[u];
        inq[u] = false;

        for (Edge *t = adj[u]; t; t = t->nxt)
            if (t->cap && dis[u]+t->cost < dis[v=t->vtx]) {
                int tmp = dis[v];
                dis[v] = dis[u]+t->cost;
                pre[v] = u;
                path[v] = t;
                sum += dis[v];
                if (!inq[v]) {
                    if (que.empty() || dis[que.front()] > dis[v]) {
                        que.push_front(v);
                    } else {
                        que.push_back(v);
                    }
                    inq[v] = true;
                } else
                    sum -= tmp;
            }
    }
    if (INF != dis[vt]) {
        int delta = INF;
        for (int t = vt; t != vs; t = pre[t])
            if (path[t]->cap < delta)
                delta = path[t]->cap;
        for (int t = vt; t != vs; t = pre[t]) {
            path[t]->cap -= delta;
            path[t]->rev->cap += delta;
        }
    }
    return dis[vt];
}
int mcmf() {
    int ret = 0;
    while (true) {
        int d = spfa();
        if (d != INF)
            ret += d;
        else
            break;
    }
    return ret;
}
int n, m;
void load() {
    scanf("%d%d", &n, &m);
    vs = 0, vt = n+1;
    add(vs,1,2,0);
    add(n,vt,2,0);
    for (int i = 1; i <= m; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a,b,1,c);
        add(b,a,1,c);
    }
}
void work() {
    printf("%d\n", mcmf());
//    system("pause");
}
int main() {
    load();// load&build
    work();
    return 0;
}
