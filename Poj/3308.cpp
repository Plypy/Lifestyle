#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iomanip>
using namespace std;
const int MAXN = 100;
const int MAXM = 1005;

const int MAXV = MAXN*2;
const int MAXE = 2*(MAXM+MAXN*2);
const double INF = 1e8;
const double EPS = 1e-8;
inline double dblfix(double t) {
    if (t < EPS)
        return 0;
    return t;
}
struct Edge {
    int vtx;
    double cap;
    Edge *nxt, *rev;
    Edge() { }
    Edge(int iv, double ic, Edge *in, Edge *ir):
        vtx(iv), cap(ic), nxt(in), rev(ir) { }
} epool[MAXE], *adj[MAXV], *eptr = epool, *p[MAXV], *stae[MAXV];
int lv[MAXV], stap[MAXV];
int vs, vt;
void add(int u, int v, double cap) {
    adj[u] = new (eptr++) Edge(v,cap,adj[u],eptr);
    adj[v] = new (eptr++) Edge(u,0,adj[v],eptr-2);
}
bool label() {
    int head, tail;
    stap[head=tail=0] = vs;
    memset(lv,-1,sizeof(lv));
    lv[vs] = 0;
    while (head<=tail) {
        int u = stap[head++];
        for (Edge *t = adj[u]; t; t = t->nxt) {
            int v = t->vtx;
            if (dblfix(t->cap) > 0 && -1 == lv[v]) {
                lv[v] = lv[u]+1;
                if (v == vt)
                    return true;
                stap[++tail] = v;
            }
        }
    }
    return false;
}

double aug() {
    double ret = 0;
    for (int i = vs; i <= vt; ++i)
        p[i] = adj[i];
    int stop = 1;
    stap[stop] = vs;
    int u, v;
    while (stop) {
        u = stap[stop];
        if (u != vt) {
            for (; p[u]; p[u] = p[u]->nxt)
                if (dblfix(p[u]->cap) > 0 && lv[u]+1 == lv[v=p[u]->vtx])
                    break;
            if (p[u]) {
                stap[++stop] = v;
                stae[stop] = p[u];
            } else
                --stop, lv[u] = -1;
        } else {
            double delta = INF;
            for (int i = stop; i >= 2; --i)
                if (stae[i]->cap < delta)
                    delta = stae[i]->cap;
            ret += delta;
            for (int i = stop; i >= 2; --i) {
                stae[i]->cap -= delta;
                stae[i]->rev->cap += delta;
                if (0 == dblfix(stae[i]->cap))
                    stop = i-1;
            }

        }
    }
    return ret;
}
double dinic() {
    double ret = 0;
    while (label())
        ret += aug();
    return ret;
}
int n, m, l;
void load() {
    //scanf("%d%d%d", &n, &m, &l);
    cin >> n >> m >> l;
    vs = 0;
    vt = n+m+1;
    for (int i = 1; i <= n; ++i) {
        double t;
        //scanf("%f", &t);
        cin >> t;
        t = log(t);
        add(vs,i,t);
    }
    for (int i = 1; i <= m; ++i) {
        double t;
        //scanf("%f", &t);
        cin >> t;
        t = log(t);
        add(n+i,vt,t);
    }
    for (int i = 1; i <= l; ++i) {
        int a, b;
        //scanf("%d%d", &a, &b);
        cin >> a >> b;
        add(a,n+b,INF);
    }
}
void work() {
    double ans = dinic();
    cout << fixed << setprecision(4);
//    cout << ans << endl;
    ans = exp(ans);
    cout << ans << endl;
    //printf("%.4f\n", ans);
}
void init() {
    n = m = l = 0;
    eptr = epool;
    memset(adj,0,sizeof(adj));
    vs = vt = 0;
}
int main() {
    int t;
    ios::sync_with_stdio(false);
    //scanf("%d", &t);
    cin >> t;
    for (int i = 0; i < t; ++i) {
        init();
        load();
        work();
    }
    return 0;
}
