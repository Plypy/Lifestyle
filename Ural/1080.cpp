#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN = 105;
int n;

struct Edge {
    int vtx;
    Edge *nxt;
    Edge(int ivtx = 0, Edge *inxt = 0):
        vtx(ivtx), nxt(inxt) { }
} edge[MAXN*MAXN], *adj[MAXN];
int ect;
void addedge(int u, int v) {
    adj[u] = &(edge[++ect] = Edge(v,adj[u]));
    adj[v] = &(edge[++ect] = Edge(u,adj[v]));
}

void load() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        while (true) {
            int t;
            scanf("%d", &t);
            if (!t)
                break;
            addedge(i,t);
        }
    }
}

int c[MAXN];
void work() {
    memset(c,-1,sizeof(c));
    queue<int> que;
    bool suc = true;
    for (int i = 1; i <= n; ++i) {
        if (-1 == c[i]) {
            que.push(i);
            c[i] = 0;
            while (que.size()) {
                int u = que.front();
                que.pop();
                for (Edge *t = adj[u]; t; t = t->nxt) {
                    int v = t->vtx;
                    if (-1 == c[v]) {
                        c[v] = 1-c[u];
                        que.push(v);
                    }
                    if (suc) {
                        for (Edge *t = adj[v]; t; t = t->nxt)
                            if (c[v] == c[t->vtx])
                                suc = false;
                    }
                }
            }
        }
    }
    if (suc) {
        for (int i = 1; i <= n; ++i)
            cout << c[i];
        cout << endl;
    } else {
        cout << -1 << endl;
    }
}
        
int main() {
    load();
    work();
    return 0;
}
