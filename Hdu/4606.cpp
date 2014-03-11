/**
 * Description:
 * Source:
 * Author: Ply_py
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
using namespace std;

const double EPS = 1e-6;
const double INF = 1e100;
int dblcmp(double x) {
    if (fabs(x) < EPS)
        return 0;
    return x<0?-1:1;
}
typedef struct Point {
    double x, y;
    void read() {
        scanf("%lf%lf", &x, &y);
    }
    Point() { };
    Point(double a, double b): x(a), y(b) { }
} Vector;
Vector operator-(Vector a, Vector b) {
    return Vector(a.x-b.x,a.y-b.y);
}
Vector operator+(Vector a, Vector b) {
    return Vector(a.x+b.x,a.y+b.y);
}
double cross(Vector a, Vector b) {
    return a.x*b.y-a.y*b.x;
}
double area2(Point a, Point b, Point c) {
    return cross(b-a, c-a);
}
double dot(Vector a, Vector b) {
    return a.x*b.x+a.y*b.y;
}
double length(Vector a) {
    return sqrt(dot(a,a));
}
double dis(Point a, Point b) {
    return length(b-a);
}
bool intersect(Point a, Point b, Point c, Point d) {
    double d1 = dblcmp(area2(a,b,c));
    double d2 = dblcmp(area2(a,b,d));
    double d3 = dblcmp(area2(c,d,a));
    double d4 = dblcmp(area2(c,d,b));
    return (d1*d2<0 && d3*d4<0);
}
const int MAXN = 105;
const int MAXM = 105;
const int MAXP = MAXN+2*MAXM;
Point pt[MAXP];
Point seg[MAXM][2];
int plan[MAXN];
int n, m, p;
int pct;
void init() {
}
void load() {
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 1; i <= n; ++i)
        pt[i].read();
    pct = n;
    for (int i = 1; i <= m; ++i) {
        seg[i][0].read(), seg[i][1].read();
        pt[++pct] = seg[i][0];
        pt[++pct] = seg[i][1];
    }
    for (int i = 1; i <= n; ++i)
        scanf("%d", plan+i);
}
bool check(int a, int b) {
    for (int i = 1; i <= m; ++i)
        if (intersect(pt[a],pt[b],seg[i][0],seg[i][1]))
            return false;
    return true;
}
double g[MAXP][MAXP];
void cal_dis() {
    for (int i = 1; i < pct; ++i)
        for (int j = i+1; j <= pct; ++j) {
            if (check(i,j)) {
                g[i][j] = g[j][i] = dis(pt[i],pt[j]);
            } else {
                g[i][j] = g[j][i] = INF;
            }
        }
}
double dist[MAXP][MAXP];
void floyd() {
    memcpy(dist,g,sizeof(dist));
    for (int k = 1; k <= pct; ++k)
        for (int i = 1; i < pct; ++i)
            for (int j = i+1; j <= pct; ++j) {
                if (dist[i][j] > dist[i][k]+dist[k][j])
                    dist[i][j] = dist[j][i] = dist[i][k]+dist[k][j];
            }
}
int pos[MAXN];
const int MAXV = MAXN;
const int MAXE = MAXV*MAXV;
struct Edge {
    int vtx;
    Edge *nxt;
    Edge() { };
    Edge(int a, Edge *c): vtx(a), nxt(c) { }
} epool[MAXE], *adj[MAXV], *eptr = epool;
void add(int u, int v) {
    adj[u] = new (eptr++) Edge(v,adj[u]);
}

void build_graph(double mlen) {
    for (int i = 1; i < n; ++i)
        for (int j = i+1; j <= n; ++j) {
            if (dist[i][j] > mlen)
                continue;
            int a = i, b = j;
            if (pos[i] > pos[j])
                swap(a,b);
            add(a,b);
        }
}
bool vis[MAXV];
int pal[MAXV];
void g_init() {
    memset(adj,0,sizeof(adj));
    memset(pal,0,sizeof(pal));
    eptr = epool;
}
bool dfs(int u) {
    for (Edge *t = adj[u]; t; t = t->nxt) {
        int v = t->vtx;
        if (vis[v])
            continue;
        vis[v] = true;
        if (!pal[v] || dfs(pal[v])) {
            pal[v] = u;
            return true;
        }
    }
    return false;
}
int hungary() {
    int ret = 0;
    for (int i = 1; i <= n; ++i) {
        memset(vis,0,sizeof(vis));
        if (dfs(i))
            ++ret;
    }
    return ret;
}
bool check_graph() {
    int t = n-hungary();
    return t <= p;
}
void cal_cap() {
    for (int i = 1; i <= n; ++i)
        pos[plan[i]] = i;
    double mlen = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = i+1; j <= n; ++j)
            if (INF != dist[i][j] && dist[i][j] > mlen)
                mlen = dist[i][j];
    }
    double l = 0, r = mlen;
    while (r-l > 0.0001) {
        double m = (r+l)/2;
        g_init();
        build_graph(m);
        if (check_graph())
            r = m;
        else
            l = m;
    }
    printf("%.2lf\n", r);
}
void work() {
    cal_dis();
    floyd();
    cal_cap();
}
int main(int argc, char const *argv[]) {
    int T;
    scanf("%d", &T);
    while (T--) {
        init();
        load();
        work();
    }
    return 0;
}