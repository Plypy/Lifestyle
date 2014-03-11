/**
 * Description: Judge whether there is a positive loop in the graph
 * Solution: Bellman-Ford, spfa and other algorithms which could find a positive loop whatsoever
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
#include <cmath>
using namespace std;

const int MAXN = 105;
const int MAXM = 105;

const int MAXV = MAXN;
const int MAXE = MAXM*2;
const double eps = 1e-8;
int dblcmp(double a) {
    if (fabs(a) < eps)
        return 0;
    if (a > 0)
        return 1;
    return -1;
}
struct Edge {
    int u, v;
    double cost, rate;
    Edge() {}
    Edge(int a, int b, double c, double d):
        u(a), v(b), cost(c), rate(d) { }
} edge[MAXE], *eptr = edge;

void add(int u, int v, double cost, double rate) {
    new (eptr++) Edge(u,v,cost,rate);
}

int N, M, S;
double V;
void load() {
    cin >> N >> M >> S >> V;
    for (int i = 1; i <= M; ++i) {
        int a, b;
        double rab, cab;
        double rba, cba;
        cin >> a >> b >> rab >> cab >> rba >> cba;
        add(a,b,cab,rab);
        add(b,a,cba,rba);
    }
}

double got[MAXV];
bool relax(Edge &t) {
    double tmp = t.rate*(got[t.u]-t.cost);
    if (1 == dblcmp(tmp-got[t.v])) {
        got[t.v] = tmp;
        return true;
    }
    return false;
}
bool bellman() {
    for (int i = 1; i < N; ++i) {
        for (Edge *t = edge; t != eptr; ++t)
            relax(*t);
    }
    for (Edge *t = edge; t != eptr; ++t)
        if (relax(*t))
            return true;
    return false;
}
void work() {
    got[S] = V;
    if (bellman()) {
        cout << "YES" << endl;
    } else {
        cout << "NO"  << endl;
    }
}
int main() {
    load();
    work();
    return 0;
}

