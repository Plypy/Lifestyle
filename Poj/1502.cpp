/**
 * Author: Ply_py
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
using namespace std;
const int MAXN = 105;
const int INF  = 0x7f7f7f7f;
const int MAXV = MAXN;
const int MAXE = MAXN*MAXN;
struct Edge {
    int vtx, len;
    Edge *nxt;
    Edge(int a = 0, int b = 0, Edge *c = 0):
        vtx(a), len(b), nxt(c) { }
} epool[MAXE], *adj[MAXV], *eptr = epool;
void add(int u, int v, int l) {
    adj[u] = new (eptr++) Edge(v,l,adj[u]);
    adj[v] = new (eptr++) Edge(u,l,adj[v]);
}
int n;
void load() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j < i; ++j) {
            string tmp;
            cin >> tmp;
            if ('x' != tmp[0]) {
                int a = atoi(tmp.c_str());
                add(i,j,a);
            }
        }
}
struct Data {
    int vtx;
    int dis;
    Data(int a, int b):vtx(a), dis(b) { }
    bool operator<(const Data &t) const {
        return dis>t.dis;
    }
} ;
int dis[MAXV];
bool outq[MAXV];
void dijk() {
    priority_queue<Data> que;
    memset(dis,INF,sizeof(dis));
    dis[1] = 0;
    que.push(Data(1,0));
    while (que.size()) {
        int u = que.top().vtx;
        int d = que.top().dis;
        que.pop();
        if (outq[u]) {
            continue;
        }
        outq[u] = true;
        for (Edge *t = adj[u]; t; t = t->nxt) {
            int v = t->vtx;
            if (dis[v] > dis[u]+t->len) {
                dis[v] = dis[u]+t->len;
                que.push(Data(v,dis[v]));
            }
        }
    }
}
void work() {
    dijk();
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans,dis[i]);
    }
    cout << ans << endl;
}
int main() {
    load();
    work();
    return 0;
}
