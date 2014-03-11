// noip 2007 Ê÷ÍøµÄºËÒ»Ìâ 
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 310;
const int INF = 52111425;
struct Edge {
    int vtx, len;
    Edge *nxt;
    Edge(int tvtx = 0, int tlen = 0, Edge *tnxt = 0):
        vtx(tvtx), len(tlen), nxt(tnxt) { }
} e[MAXN], *adj[MAXN];
int dis[MAXN][MAXN];
int ct;
void add(int s, int t, int len) {
    adj[s] = &(e[++ct] = Edge(t,len,adj[s]));
    dis[s][t] = len;
}
int n, s;
void load() {
    scanf("%d%d", &n, &s);
    int s, t, l;
    for (int i = 1; i < n; ++i) {
        scanf("%d%d%d", &s, &t, &l);
        add(s,t,l);
        add(t,s,l);
    }
}

inline int min(int a, int b) {
    return a<b?a:b;
}
inline int max(int a, int b) {
    return a>b?a:b;
}
bool used[MAXN];
int nxtv[MAXN];
int dfs(int u) {
    used[u] = true;
    int ret = 0;
    int tmp;
    for (Edge *t = adj[u]; t; t = t->nxt) {
        if (!used[t->vtx]) {
            tmp = t->len+dfs(t->vtx);
            if (tmp > ret) {
                ret = tmp;
                nxtv[u] = t->vtx;
            }
        } 
    }
    return ret;
}
int path[MAXN];
int ans = INF;
int ecc(int s, int t) {
    int ret = 0;
    for (int i = s; i <= t; ++i) {
        memset(used,0,sizeof(used));
        for (int j = s; j <= t; ++j)
            used[path[j]] = true;
        ret = max(ret,dfs(path[i]));
    }
    return ret;
}
void work() {
    dfs(1);
    int vt = 1;
    while (nxtv[vt])
        vt = nxtv[vt];
    memset(used,0,sizeof(used));
    memset(nxtv,0,sizeof(nxtv));
    dfs(vt);
    path[++path[0]] = vt;
    while (nxtv[vt]) {
        vt = nxtv[vt];
        path[++path[0]] = vt;
    }
    for (int i = 1; i <= path[0]; ++i) {
        int plenth = 0;
        int st = i, ed = i;
        for (int j = i+1; j <= path[0]; ++j) {
            if (plenth+dis[path[j-1]][path[j]] <= s) {
                ed = j;
                plenth += dis[path[j-1]][path[j]];
            }
            else
                break;
        }
        ans = min(ans,ecc(st,ed));
        if (ed == path[0])
            break;
    }
}
void output() {
    printf("%d\n", ans);
//    system("pause");
}
int main() {
    load();
    work();
    output();
    return 0;
}

