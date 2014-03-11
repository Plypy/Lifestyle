// 练习写最小费用最大流
// I am practicing writing the minimum cost maxflow algorithm
#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;
const int MAXN = 55;
const int MAXV = MAXN*MAXN*2;
const int MAXE = MAXN*MAXN*2*4;
const int INF = 52111425;
struct Edge {
    int st, ed;
    int cap, cost;
    int pair, nxt;
    int id;
    Edge(int _st = 0, int _ed = 0, int _nxt = 0, int _cap = 0, int _cost = 0, int _pair = 0):
        st(_st), ed(_ed), nxt(_nxt), cap(_cap), cost(_cost), pair(_pair) { }
} edge[MAXE];
int tot;
int ct;
int adj[MAXV];
int n, m;
int in[MAXN][MAXN], ou[MAXN][MAXN];
inline void add(int u, int v, int cap, int cost, int pair) {
    edge[++ct] = Edge(u,v,adj[u],cap,cost,pair);
    adj[u] = ct;
}
inline void build(int s, int t, int cap, int cost) {
    add(s,t,cap,cost,ct+2);
    add(t,s,0,-cost,ct);
}
void load() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            in[i][j] = ++tot;
            ou[i][j] = ++tot;
        }
    int hap;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            cin >> hap;
            if (i == 1 && j == 1) {
                build(in[1][1],ou[1][1],2,0);
                build(ou[1][1],in[1][2],1,0);
                build(ou[1][1],in[2][1],1,0);
            } else if (i == n && j == m) {
                build(in[n][m],ou[n][m],2,0);
            } else {
                build(in[i][j],ou[i][j],1,-hap);
                if (i != n)
                    build(ou[i][j],in[i+1][j],1,0);
                if (j != m)
                    build(ou[i][j],in[i][j+1],1,0);
            }
        }
}

bool inq[MAXV];
int dis[MAXV];
int pre_edge[MAXV];
queue<int> que;
inline int min(int a, int b) {
    return a<b?a:b;
}
int spfa() {
    for (int i = 2; i <= tot; ++i)
        dis[i] = INF;
    que.push(1);
    inq[1] = true;
    int u, v;
    while (!que.empty()) {
        u = que.front();
        inq[u] = false;
        que.pop();
        for (int t = adj[u]; t; t = edge[t].nxt) {
            v = edge[t].ed;
            if (edge[t].cap && dis[v] > dis[u]+edge[t].cost) {
                dis[v] = dis[u]+edge[t].cost;
                pre_edge[v] = t;
                if (!inq[v]) {
                    que.push(v);
                    inq[v] = true;
                }
            }
        }
    }
    return dis[tot];
}
int ans;
void work() {
    int tcost;
    while ((tcost = spfa()) != INF) {
        int aug = INF;
        for (int t = pre_edge[tot]; edge[t].st != 1; t = pre_edge[edge[t].st])
            aug = min(aug,edge[t].cap);
        for (int t = pre_edge[tot]; edge[t].st != 1; t = pre_edge[edge[t].st]) {
            edge[t].cap -= aug;
            edge[edge[t].pair].cap += aug;
        }
        ans += tcost*aug;
    }
    cout << -ans << endl;
}
int main() {
    load();
    work();
    return 0;
}
/*
3 3
0 3 9
2 8 5
5 7 0

34
*/
