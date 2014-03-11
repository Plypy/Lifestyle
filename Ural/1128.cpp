//黑书P295

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;
const int MAXN = 7200;
const int MAXE = MAXN*3;
const int MAXV = MAXN;
int n;
struct Edge {
    int vtx;
    Edge *nxt;
    Edge(int ivtx = 0, Edge *inxt = 0):
        vtx(ivtx), nxt(inxt) { }
} edge[MAXE], *adj[MAXV];
int ect;
inline void addedge(int u, int v) {
    adj[u] = &(edge[++ect] = Edge(v,adj[u]));
}

void load() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int t;
        scanf("%d", &t);
        for (int j = 1; j <= t; ++j) {
            int k;
            scanf("%d", &k);
            addedge(i,k);
        }
    }
}

int c[MAXV];
const int UNVISITED = -1;
const int WHITE = 0;
const int BLACK = 1;
void bfs() {
    memset(c,-1,sizeof(c));
    queue<int> que;
    for (int i = 1; i <= n; ++i)
        if (UNVISITED == c[i]) {
            que.push(i);
            c[i] = BLACK;
            while (que.size()) {
                int u = que.front();
                que.pop();
                for (Edge *t = adj[u]; t; t = t->nxt) {
                    int v = t->vtx;
                    if (UNVISITED == c[v]) {
                        que.push(v);
                        c[v] = 1-c[u];
                    }
                }
            }
        }
}

int get_adv(int u) {
    int ret = 0;
    for (Edge *t = adj[u]; t; t = t->nxt)
        if (c[u] == c[t->vtx])
            ++ret;
    return ret;
}

void work() {
    bfs();

    stack<int> stk;
    for (int u = 1; u <= n; ++u)
        if (get_adv(u) > 1)
            stk.push(u);
    while (stk.size()) {
        int u = stk.top();
        stk.pop();
        if (get_adv(u) > 1) {
            c[u] = 1-c[u];
            for (Edge *t = adj[u]; t; t = t->nxt) {
                int v = t->vtx;
                if (get_adv(v) > 1)
                    stk.push(v);
            }
        }
    }

    int ct[2] = {0};
    for (int i = 1; i <= n; ++i)
        ++ct[c[i]];

    bool side;
    if (ct[0] == ct[1])
        side = c[1];
    else
        side = ct[1]<ct[0];
    printf("%d\n", ct[side]);
    for (int i = 1; i <= n; ++i)
        if (c[i] == side)
            printf("%d ", i);
}
int main() {
    load();
    work();
//    system("pause");
    return 0;
}
