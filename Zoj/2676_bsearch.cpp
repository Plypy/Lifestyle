// 速度快如闪电 哇哈哈
// 不过这一次还是有教训的。。。
// Note： 模块化编程非常强大，可以保证自己很少出错。以后要坚持
// 模块化编程的时候应该尽可能的让各部分不相关
// 还有就是未初始化的变量就是灾难啊...和宏差不多会导致各种奇妙的错误...就跟变魔术一样 
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

//#define DEBUG

const int Maxn = 105;
const int Maxm = 405;
const int Maxv = Maxn;
const int Maxe = Maxm<<1;

int e[Maxe][3];
int n, m;
bool load() {
    if (EOF == scanf("%d%d", &n, &m))
        return false;
    for (int i = 1; i <= m; ++i)
        scanf("%d%d%d", &e[i][0], &e[i][1], &e[i][2]);
    return true;
}

struct Edge {
    int vtx;
    double cap;
    int id;
    Edge *nxt, *opt;
    Edge(int ivtx = 0, double icap = 0, int iid = 0, Edge *inxt = 0, Edge *iopt = 0):
        vtx(ivtx), cap(icap), id(iid), nxt(inxt), opt(iopt) { }
} edge[Maxe], *adj[Maxv];
int ect;
void add(int u, int v, double cap, int id) {
    adj[u] = &(edge[++ect] = Edge(v,cap,id,adj[u],edge+ect+1));
    adj[v] = &(edge[++ect] = Edge(u,cap,id,adj[v],edge+ect-1));
}


const double Inf = 1e10;
int ans[Maxe];
int ht[Maxv], hct[Maxv];
bool vis[Maxv];
void init() {
    memset(adj,0,sizeof(adj));
    ect = 0;
    memset(ht,0,sizeof(ht));
    memset(hct,0,sizeof(hct));
    memset(vis,0,sizeof(vis));
    ans[0] = 0;
}

void dfs(int u) {
    vis[u] = true;
    for (Edge *t = adj[u]; t; t = t->nxt)
        if (!vis[t->vtx] && t->cap > 0)
            dfs(t->vtx);
}

int s, t;
double aug(int u, double augc) {
    if (u == t)
        return augc;
    double l = augc;
    int minht = n;
    for (Edge *t = adj[u]; t; t = t->nxt) {
        int v = t->vtx;
        if (t->cap > 0) {
            if (ht[v]+1 == ht[u]) {
                double d = aug(v,min(l,t->cap));
                l -= d;
                t->cap -= d;
                t->opt->cap += d;
                if (0 == l)
                    return augc;
                if (ht[s] >= n)
                    return augc-l;
            }
            minht = min(minht,ht[v]);
        }
    }
    if (augc == l) {
        --hct[ht[u]];
        if (!hct[ht[u]])
            ht[s] = n;
        ht[u] = minht+1;
        ++hct[ht[u]];
    }
    return augc-l;
}
double sap() {
    double ret = 0;
    hct[0] = n;
    while (ht[s] < n) {
        ret += aug(s,Inf);
    }
    return ret;
}
        
double  mincut() {
    s = 1, t = n;
    double ret = sap();
    dfs(1);
    for (int u = 1; u <= n; ++u)
        if (vis[u])
            for (Edge *t = adj[u]; t; t = t->nxt)
                if (!vis[t->vtx])
                    ans[++ans[0]] = t->id;
    return ret;
}

double solve(double t) {
    init();
    double ret = 0;
    for (int i = 1; i <= m; ++i) {
        if (e[i][2] > t)
            add(e[i][0],e[i][1],e[i][2]-t,i);
        else {
            ans[++ans[0]] = i;
            ret += e[i][2]-t;
        }
    }
    return ret + mincut();
}

const double Prec = 1e-2;
void work() {
    double tot = 0;
    for (int i = 1; i <= m; ++i)
        tot += e[i][2];
    
    double l = 0, r = tot;
    double mid, t;
    while (r-l > Prec) {
        mid = (l+r)/2.0;
        t = solve(mid);
        
//        cout << mid << ' ' << t << endl;
//        if (fabs(t)<Prec)
//            break;
        if (t > 0.0)
            l = mid;
        else
            r = mid;
    }
}

void output() {
    printf("%d\n", ans[0]);
    for (int i = 1; i <= ans[0]; ++i)
        printf("%d ", ans[i]);
    printf("\n");
}
int main() {
    while (load()) {
        work();
        output();
    }
    return 0;
}
/*

6 8
1 2 3
1 3 3
2 4 2
2 5 2
3 4 2
3 5 2
5 6 3
4 6 3

4
3 4 5 6 
*/
