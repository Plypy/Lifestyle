/**
 * Description:
 * ProblemName:
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
#include <vector>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
using namespace std;

const int MAXN = 1015;
const int MAXV = MAXN;
const int MAXE = MAXV*MAXV;
const int INF = 0x3f3f3f3f;

struct Edge {
    int vtx;
    int len;
    Edge *nxt;
    Edge(int iv = 0, int il = 0, Edge* ie = 0): vtx(iv), len(il), nxt(ie) {}
} epool[MAXE], *adj[MAXV], *eptr = epool;

void add(int u, int v, int len) {
    adj[u] = new (eptr++) Edge(v, len, adj[u]);
    adj[v] = new (eptr++) Edge(u, len, adj[v]);
}

struct Block {
    int x1, y1;
    int x2, y2;
    Block(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0): x1(x1), y1(y1), x2(x2), y2(y2) { };
} block[MAXN];

int calc(int a, int b) {
    if (a > b) {
        return a-b-1;
    }
    return 0;
}

int dis(int i, int j) {
    int ret = 0;
    ret = max(ret, calc(block[i].x1, block[j].x2));
    ret = max(ret, calc(block[j].x1, block[i].x2));
    ret = max(ret, calc(block[i].y1, block[j].y2));
    ret = max(ret, calc(block[j].y1, block[i].y2));
    return ret;
}

int N, H, W;
struct Node {
    int vtx;
    int dis;
    Node(int iv = 0, int id = 0): vtx(iv), dis(id) { }
    bool operator<(const Node& t) const {
        return dis>t.dis;
    }
};

int dist[MAXN];
int outq[MAXN];
int dijk() {
    priority_queue<Node> que;
    que.push(Node(0,0));
    memset(dist, INF, sizeof(dist));
    memset(outq, 0, sizeof(outq));
    dist[0] = 0;

    while (!que.empty()) {
        int u = que.top().vtx;
        que.pop();
        if (outq[u]) {
            continue;
        }
        outq[u] = true;
        if (outq[N]) {
            break;
        }

        for (Edge* t = adj[u]; t; t = t->nxt) {
            int v = t->vtx;
            int len = t->len;
            if (dist[u]+len < dist[v]) {
                dist[v] = dist[u]+len;
                que.push(Node(v,dist[v]));
            }
        }
    }
    return dist[N];
}

void clear() {
    eptr = epool;
    memset(adj, 0, sizeof(adj));
}

int work() {
    for (int i = 0; i <= N; ++i) {
        for (int j = i+1; j <= N; ++j) {
            int d = dis(i,j);
            add(i,j,d);
        }
    }
    // cout << N << endl;
    // int a, b;
    // while (cin >> a >> b) {
    //     cout << dis(a,b) << endl;
    // }
    return dijk();
}
void load() {
    scanf("%d%d%d", &W, &H, &N);
    for (int i = 1; i <= N; ++i) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        ++a, ++b, ++c, ++d;
        block[i] = Block(a,b, c,d);
    }
    block[0] = Block(0,1, 0,H);
    block[++N] = Block(W+1,1, W+1,H);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        clear();
        load();
        printf("Case #%d: %d\n", i, work());
    }
}
