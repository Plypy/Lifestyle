/* 毫无难度的最大权闭合子图问题
 * 唯一和平常不同的就是要输出方案
 * 用一遍dfs就可以了，利用了依赖节点和被依赖节点一定在同一个顶点集中的性质 
 */ 
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <fstream>
using namespace std;
ifstream fin("shut.in");
ofstream fout("shut.out");
const int MAXN = 50;
const int MAXV = MAXN*2;
const int MAXE = MAXV*MAXV+MAXV*2;
const int INF = 52111425;

inline int min(int a, int b) {
    return a<b?a:b;
}

struct Edge {
    int cap, vtx;
    Edge *nxt, *opp;
    Edge(int _vtx = 0, int _cap = 0, Edge *_nxt = 0, Edge *_opp = 0):
        vtx(_vtx), cap(_cap), nxt(_nxt), opp(_opp) { }
} edge[MAXE], *adj[MAXV];
int ect;
inline void add(int u, int v, int cap) {
    adj[u] = &(edge[++ect] = Edge(v,cap,adj[u],edge+ect+1));
    adj[v] = &(edge[++ect] = Edge(u,0,adj[v],edge+ect-1));
}

int n, m;
int vs, vt, vtot;
int ans;
void load() {
    fin >> m >> n;
    vs = 0;
    vt = m+n+1;
    vtot = vt+1;
    fin.get();
    for (int i = 1; i <= m; ++i) {
        int tmp;
        fin >> tmp;
        ans += tmp;
        add(vs,i,tmp);
        while ('\n' != fin.get()) {
            fin >> tmp;
            add(i,tmp+m,INF);
        }
    }
    for (int i = 1; i <= n; ++i) {
        int tmp;
        fin >> tmp;
        add(i+m,vt,tmp);
    }
}

int hct[MAXV];
int ht[MAXV];
int aug(int u, int augc) {
    if (u == vt)
        return augc;
    int tmp = augc;
    int minht = vtot-1;
    for (Edge *t = adj[u]; t; t = t->nxt)
        if (t->cap) {
            int v = t->vtx;
            if (ht[v]+1 == ht[u]) {
                int d = aug(v,min(t->cap,tmp));
                tmp -= d;
                t->cap -= d;
                t->opp->cap += d;
                if (!tmp)
                    return augc;
                if (ht[vs] >= vtot)
                    return augc-tmp;
            }
            minht = min(minht,ht[v]);
        }
    if (tmp == augc) {
        --hct[ht[u]];
        if (!hct[ht[u]])
            ht[vs] = vtot;
        ht[u] = minht+1;
        ++hct[ht[u]];
    }
    return augc-tmp;
}
int sap() {
    int ret = 0;
    hct[0] = vtot;
    while (ht[vs] < vtot)
        ret += aug(vs,INF);
    return ret;
}
bool used[MAXV];
void dfs(int u) {
    used[u] = true;
    for (Edge *t = adj[u]; t; t = t->nxt) {
        int v = t->vtx;
        if (!used[v] && t->cap)
            dfs(v);
    }
}
void work() {
    int mcut = sap();
    ans -= mcut;
    dfs(vs);
    bool flag = true;
    for (int i = 1; i <= m; ++i)
        if (used[i]) {
            if (flag)
                flag = false;
            else
                fout << ' ';
            fout << i;
        }
    fout << endl;
    flag = true;
    for (int i = m+1; i <= n+m; ++i)
        if (used[i]) {
            if (flag)
                flag = false;
            else
                fout << ' ';
            fout << i-m;
        }
    fout << endl;
    fout << ans << endl;
}

int main() {
    load();
    work();
    return 0;
}
