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

const int MAXN = 105;
const int MAXV = MAXN;
const int MAXE = MAXV*MAXV;
struct Edge {
    int vtx;
    Edge *nxt;
    Edge(int a = 0, Edge *c = 0):
        vtx(a), nxt(c) { }
} epool[MAXE], *adj[MAXV], *eptr = epool;

void add(int u, int v) {
    adj[u] = new (eptr++) Edge(v,adj[u]);
}
vector<int> ans;
int deg[MAXN];
int n, m;
void topsort() {
    queue<int> que;
    for (int i = 1; i <= n; ++i)
        if (0 == deg[i])
            que.push(i);
    while (que.size()) {
        int u = que.front();
        que.pop();
        ans.push_back(u);
        for (Edge *t = adj[u]; t; t = t->nxt) {
            int v = t->vtx;
            --deg[v];
            if (0 == deg[v])
                que.push(v);
        }
    }
}
void load() {
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        add(a,b);
        ++deg[b];
    }
}
int main(int argc, char const *argv[]) {
    /* code */
    return 0;
}