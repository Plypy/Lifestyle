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
    Edge(int a = 0, int b = 0): vtx(a), len(b) { }

} ;
vector<Edge> adj[MAXV];
void add(int u, int v, int l) {
    adj[u].push_back(Edge(v,l));
    adj[v].push_back(Edge(u,l));
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
        que.pop();
        if (outq[u]) {
            continue;
        }
        outq[u] = true;
        for (int i = 0; i < adj[u].size(); ++i) {
            Edge *t = &adj[u][i];
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

