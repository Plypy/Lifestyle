#define MAXN 105
#define MAXV MAXN*2
#define MAXE MAXV*MAXV
#define INF 52111425


struct Edge {
    int vtx;
    Edge *nxt;
    Edge(int ivtx = 0, Edge *inxt = 0):
        vtx(ivtx), nxt(inxt) { }
} edge[MAXE], *adj[MAXV];
int ect;
inline void add(int u, int v) {
    adj[u] = &(edge[++ect] = Edge(v,adj[u]));
}
int color[MAXV];
int dfn[MAXV];
int low[MAXV];
bool ins[MAXV];
int stack[MAXV];

void tarjan(int u) {
    low[u] = dfn[u] = ++dfn[0];
    stack[++stack[0]] = u;
    ins[u] = true;
    for (Edge *t = adj[u]; t; t = t->nxt) {
        int v = t->vtx;
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u],low[v]);
        } else if (ins[v])
            low[u] = min(low[u],dfn[v]);
    }
    if (dfn[u] == low[u]) {
        ++color[0];
        int v;
        do {
            v = stack[stack[0]--];
            ins[v] = false;
            color[v] = color[0];
        } while (v != u);
    }
}

