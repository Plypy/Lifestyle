/**
 * Description:
 * Author: Ply_py
 */

#include <iostream>
#include <fstream>
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
#include <stack>
using namespace std;
typedef long long LL;
const int MAXN = 200005;
const int MAXM = MAXN;
const int MAXQ = MAXM;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
const int MAXV = MAXN;
const int MAXE = MAXM*2*2;
struct Edge {
    int vtx;
    LL len;
    Edge *nxt;
    Edge(int a = 0, LL b = 0, Edge *c = 0): vtx(a), len(b), nxt(c) { }
} epool[MAXE], *eptr = epool, *adj[MAXV], *nadj[MAXV];
void add1(int u, int v, LL len) {
    adj[u] = new (eptr++) Edge(v,len,adj[u]);
    adj[v] = new (eptr++) Edge(u,len,adj[v]);
}
void add2(int u, int v, LL len) {
    nadj[u] = new (eptr++) Edge(v,len,nadj[u]);
    nadj[v] = new (eptr++) Edge(u,len,nadj[v]);
}
struct Node {
    int vtx;
    LL len;
    Node(int a = 0, LL b = 0): vtx(a), len(b) { }
    bool operator<(const Node &a) const {
        return len>a.len;
    }
};
LL dist[MAXV];
bool outq[MAXV];
void dijkstra(int vs) {
    memset(outq,0,sizeof(outq));
    memset(dist,INF,sizeof(dist));
    dist[vs] = 0;
    priority_queue<Node> que;
    que.push(Node(vs,0));
    int u, v;
    while (que.size()) {
        u = que.top().vtx;
        que.pop();
        if (outq[u])
            continue ;
        outq[u] = true;
        for (Edge *t = adj[u]; t; t = t->nxt) {
            v = t->vtx;
            if (dist[v] > dist[u]+t->len) {
                dist[v] = dist[u]+t->len;
                que.push(Node(v,dist[v]));
            }
        }
    }
}
int S, T;
int n, m;
LL disS[MAXV], disT[MAXV];
void SPG() {
    dijkstra(S);
    memcpy(disS,dist,sizeof(dist));
    dijkstra(T);
    memcpy(disT,dist,sizeof(dist));
    for (int u = 1; u <= n; ++u) {
        for (Edge *t = adj[u]; t; t = t->nxt) {
            int v = t->vtx;
            if (disS[u]+t->len == disS[v]) {
                add2(u,v,t->len);
            }
        }
    }
}
int dfn[MAXV], low[MAXV], dtime;
int match[MAXV];
int col[MAXV];
void color(int u, int cur) {
    col[u] = cur;
    for (Edge *t = nadj[u]; t; t = t->nxt) {
        int v = t->vtx;
        if (disS[v] == disS[u]+t->len && !col[v]) {
            if (match[u] == v)
                color(v,cur+1);
            else
                color(v,cur);
        }
    }
}
bool Bridge(int u, int fa) {
    bool ret = (u == T);
    low[u] = dfn[u] = ++dtime;
    for (Edge *p = nadj[u]; p; p = p->nxt) {
        if (disS[p->vtx] == disS[u]+p->len) {
            if (!dfn[p->vtx]) {
                bool r = Bridge(p->vtx, u);
                ret |= r;
                if (r) low[u] = min(low[u], low[p->vtx]);
            }
        }
        else if (p->vtx != fa && dfn[p->vtx]) {
            low[u] = min(low[u], dfn[p->vtx]);
        }
    }
    if (low[u] == dfn[u] && ret) {
        match[fa] = u;
    }
    return ret;
}
typedef pair<int,int> PI;
stack<PI> stk;
bool get[MAXV];
Edge *p[MAXV];
int lst[MAXV];
void NewBridge() {
    for (int i = 1; i <= n; ++i)
        p[i] = nadj[i];
    stk.push(make_pair(S,0));
    int u, v;
    int fa;
    get[T] = true;
    while (stk.size()) {
        u = stk.top().first;
        fa = stk.top().second;
        if (lst[u]) {
            v = lst[u];
            get[u] |= get[v];
            if (get[v]) {
                low[u] = min(low[u],low[v]);
            }
        }
        if (!dfn[u]) {
            low[u] = dfn[u] = ++dtime;
        }
        for (; p[u]; p[u] = p[u]->nxt) {
            v = p[u]->vtx;
            if (disS[u]+p[u]->len == disS[v]) {
                if (!dfn[v]) {
                    lst[u] = v;
                    stk.push(make_pair(v,u));
                    goto outside;
                }
            } else if (v != fa && dfn[v]) {
                low[u] = min(low[u],dfn[v]);
            }
        }
        if (p[u]) {
        } else {
            stk.pop();
            if (low[u] == dfn[u] && get[u])
                match[fa] = u;
        }
    outside:
    ;
    }
}
void split() {
//    Bridge(S,0);
    NewBridge();
    color(S,1);
}
struct Loop {
    int u, v;
    LL len;
    Loop(int a = 0, int b = 0, LL c = 0): u(a), v(b), len(c) { }
    bool operator<(const Loop &a) const {
        return len<a.len;
    }
} ;
vector<Loop> loop;
void getLoop() {
    for (int u = 1; u <= n; ++u)
        for (Edge *t = adj[u]; t; t = t->nxt) {
            int v = t->vtx;
            if (col[u] < col[v] && match[u] != v) {
                loop.push_back(Loop(u,v,disS[u]+disT[v]+t->len));
            }
        }
    sort(loop.begin(), loop.end());
}
LL ans[MAXV];
int x[MAXQ], y[MAXQ];
void print(LL a) {
    if (a == INF)
        puts("Infinity");
    else
        cout << a << endl;
}
void work() {
    SPG();
    split();
    getLoop();
    memset(ans,INF,sizeof(ans));
    int lLen = loop.size();
    for (int i = 0; i < lLen; ++i) {
        int u = loop[i].u, v = loop[i].v;
        LL len = loop[i].len;
        u = col[u], v = col[v];
        while (u != v) {
            --v;
            ans[v] = min(ans[v],len);
        }
    }
    for (int i = 1; i <= m; ++i) {
        if (col[x[i]] > col[y[i]])
            swap(x[i],y[i]);
        if (match[x[i]] == y[i]) {
            print(ans[col[x[i]]]);
        } else {
            print(disS[T]);
        }
    }
}
void load() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int a, b;
        LL c;
        cin >> a >> b >> c;
//        ++a, ++b;
        add1(a,b,c);
    }
    cin >> S >> T;
//    ++S, ++T;
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> x[i] >> y[i];
//        ++x[i], ++y[i];
    }
}
int main() {
    freopen("dream.in", "r", stdin);
    freopen("ans1.txt", "w", stdout);
    load();
    work();
    return 0;
}
