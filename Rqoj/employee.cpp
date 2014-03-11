#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int MAXN = 1010;
const int MAXM = 10010;
const int INF = 52111425;
int n, m;
int s, t;
struct Edge {
    int cap, cost;
    int vtx, nxt;
    int pair;
    Edge(int _vtx = 0, int _nxt = 0, int _cap = 0, int _cost = 0, int _pair = 0):
        vtx(_vtx), nxt(_nxt), cap(_cap), cost(_cost), pair(_pair) { }
} edge[(MAXM+MAXN)*3];
int ct;
int adj[MAXN];
void add(int s, int t, int cap, int cost, int pair) {
    edge[++ct] = Edge(t,adj[s],cap,cost,pair);
    adj[s] = ct;
}
void build(int s, int t, int cap, int cost) {
    add(s,t,cap,cost,ct+2);
    add(t,s,0,-cost,ct);
}
void load() {
    scanf("%d%d", &n, &m);
    ++n;
    s = n+1, t = 0;
    int a, b, c;
    for (int i = 1; i < n; ++i) {
        scanf("%d",&c);
        build(s,i,c,0);
        build(i+1,t,c,0);
    }
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        build(a,b+1,INF,c);
    }
    for (int i = 1; i < n; ++i)
        build(i+1,i,INF,0);
}
bool v[MAXN];
int tcost;
int ans;
inline int min(int a, int b) {
    return a<b?a:b;
}
int aug(int now, int augc) {
    if (now == t) {
        ans += tcost*augc;
        return augc;
    }
    v[now] = true;
    for (int i = adj[now]; i; i = edge[i].nxt) {
        if (!v[edge[i].vtx] && edge[i].cap && !edge[i].cost) {
            int d = aug(edge[i].vtx,min(augc,edge[i].cap));
            if (d) {
                edge[i].cap -= d;
                edge[edge[i].pair].cap += d;
                return d;
            }
        }
    }
    return 0;
}
bool modify() {
    int d = INF;
    for (int u = 0; u <= n+1; ++u)
        if (v[u])
            for (int i = adj[u]; i; i = edge[i].nxt)
                if (!v[edge[i].vtx] && edge[i].cap)
                    d = min(d,edge[i].cost);
    if (INF == d)
        return false;
    for (int u = 0; u <= n+1; ++u)
        if (v[u])
            for (int i = adj[u]; i; i = edge[i].nxt) {
//                if (!v[edge[i].vtx]) {
                    edge[i].cost -= d;
                    edge[edge[i].pair].cost += d;
//                }
            }
    tcost += d;
    return true;
}
//int times;
void work() {
    do {
//        ++times;
        do {
//            cout << "Current cost is " << ans << endl;
//            for (int i = 0; i <= n+1; ++i) {
//                cout << i << endl;
//                for (int j = adj[i]; j; j = edge[j].nxt) {
//                    cout << edge[j].vtx << ' ' << edge[j].cap << ' ' << edge[j].cost << endl;
//                }
//                system("pause");
//                cout << endl;
//            }
            memset(v,0,sizeof(v));
        } while (aug(s,INF));
    } while (modify());
}
void output() {
//    cout << "modified " << times << " times" << endl;
    printf("%d\n", ans);
//    system("pause");
}
int main() {
//    freopen("employee.in", "r", stdin);
//    freopen("employee.out", "w", stdout);
    load();
    work();
    output();
    return 0;
}
/*
3 3
2 3 4
1 2 2
2 3 5
3 3 2
*/
