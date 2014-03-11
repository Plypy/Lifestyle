#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int MAXN = 10005;
const int MAXV = MAXN;
const int MAXE = MAXN*MAXN;
int n, m;
int vtot;
struct Edge
{
    int vtx;
    int len;
    Edge *nxt;
    Edge *rev;
    Edge() {}
    Edge(int ivtx, Edge *inxt, Edge *irev):
        vtx(ivtx), nxt(inxt), rev(irev) {}
} epool[MAXE], *adj[MAXV];
Edge *eptr = epool;

inline void add(int u, int v)
{
    adj[u] = new (eptr++) Edge(v,adj[u],eptr);
    adj[v] = new (eptr++) Edge(u,adj[v],eptr-2);
}

void load()
{
    cin >> n >> m;
    vtot = n;
    for (int i = 1; i <= m; ++i)
    {
        int a, b;
        cin >> a >> b;
        add(a,b);
    }
}
bool vis[MAXV];
void dfs(int u)
{
    vis[u] = true;
    cout << u << endl;
    for (Edge *t = adj[u]; t; t = t->nxt)
    {
        int v = t->vtx;
        if (!vis[v])
            dfs(v);
    }
}
void check(int u)
{
    cout << u << adj[u]->vtx << endl;
    cout << adj[u]->vtx << adj[u]->rev->vtx << endl;
    cout << u << adj[u]->rev->rev->vtx << endl;
    cout << endl;
}
void work()
{
    while (true)
    {
        int u;
        cin >> u;
        check(u);
    }
}

int main()
{
    load();
    work();
    return 0;
}
