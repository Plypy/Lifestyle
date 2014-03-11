const int MAXV = MAXN*2;
const int MAXE = MAXV*MAXV;
const int INF = 1<<28;
int vs, vt;
struct Edge {
    int vtx, cap, cost;
    Edge *nxt, *rev;
    Edge() { }
    Edge(int iv, int icap, int icost, Edge *in, Edge *ir):
        vtx(iv), cap(icap), cost(icost), nxt(in), rev(ir) { }
} epool[MAXE], *adj[MAXV], *eptr = epool;
inline void add(int u, int v, int cap, int cost) {
    adj[u] = new (eptr++) Edge(v,cap,cost,adj[u],eptr);
    adj[v] = new (eptr++) Edge(u,0,-cost,adj[v],eptr-2);
}

int pre[MAXV];
Edge *path[MAXV];
int flow;
bool inq[MAXV];
int dis[MAXV];
int spfa() {
    for (int i = vs; i <= vt; ++i)
        dis[i] = INF;
    dis[vs] = 0;
    int sum = 0;
    deque<int> que;
    que.push_front(vs);
    int u, v;
    while (!que.empty()) {
        while (dis[que.front()] > (sum/que.size())) {
            que.push_back(que.front());
            que.pop_front();
        }
        u = que.front();
        que.pop_front();
        inq[u] = false;
        sum -= dis[u];

        for (Edge *t = adj[u]; t; t = t->nxt)
            if (t->cap && dis[u]+t->cost < dis[v=t->vtx]) {
                int tmp = dis[v];
                dis[v] = dis[u]+t->cost;
                pre[v] = u;
                path[v] = t;
                sum += dis[v];
                if (!inq[v]) {
                    if (que.empty() || dis[que.front()] > dis[v])
                        que.push_front(v);
                    else
                        que.push_back(v);
                    inq[v] = true;
                } else {
                    sum -= tmp;
                }
            }
    }
    int delta = INF;
    if (INF != dis[vt]) {
        for (int v = vt; v != vs; v = pre[v])
            if (path[v]->cap < delta)
                delta = path[v]->cap;
        flow += delta;
        for (int v = vt; v != vs; v = pre[v]) {
            path[v]->cap -= delta;
            path[v]->rev->cap += delta;
        }
    }
    if (INF == dis[vt])
        return INF;
    return dis[vt]*delta;
}
int mcmf(int needed) {
    flow = 0;
    int ret = 0;
    while (true) {
        int d = spfa();
        if (d != INF)
            ret += d;
        else
            break;
    }
    if (flow < needed)
        return INF;
    return ret;
}
void init() {
    memset(adj,0,sizeof(adj));
    eptr = epool;
}
