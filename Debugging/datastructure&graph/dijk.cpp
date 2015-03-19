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
const int INF  = 0x3f3f3f3f;
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

void dijk(int vs) {
    priority_queue<Data> que;
    memset(dis,INF,sizeof(dis));
    memset(outq,0,sizeof(outq));
    dis[vs] = 0;
    que.push(Data(vs,0));
    while (que.size()) {
        int u = que.top().vtx;
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
int S;
void work() {
    dijk(S);
}
void init() {
    eptr = epool;
    memset(adj,0,sizeof(adj));
}
bool load() {

}
int main() {
    ios::sync_with_stdio(false);
    while (load()) {
        work();
    }
    return 0;
}
