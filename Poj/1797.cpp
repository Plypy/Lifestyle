#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
const int MAXN = 1005;
const int INF = 52111425;

int g[MAXN][MAXN];
int n, m;
void load() {
    memset(g,0,sizeof(g));
    scanf("%d%d", &n, &m);
    while (m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = g[b][a] = max(g[a][b],c);
    }
}

struct Node {
    int id;
    int dis;
    Node(int id_,int dis_):
        id(id_), dis(dis_) { }
    friend bool operator<(const Node &a, const Node &b) {
        return a.dis<b.dis;
    }
};

int dis[MAXN];
bool ouq[MAXN];
int work() {
    memset(dis,0,sizeof(dis));
    memset(ouq,0,sizeof(ouq));
    priority_queue<Node> que;
    que.push(Node(1,INF));
    
    while (true) {
        Node tmp = que.top();
        que.pop();
        int u = tmp.id;
        int tdis = tmp.dis;
        if (ouq[u])
            continue;
        ouq[u] = true;
        if (u == n)
            break;
        
        for (int v = 1; v <= n; ++v)
            if (!ouq[v] && g[u][v]) {
                int tcap = min(g[u][v],tdis);
                if (tcap > dis[v]) {
                    dis[v] = tcap;
                    que.push(Node(v,dis[v]));
                }
            }
    }
    
    return dis[n];
}

int k;
int main() {
    scanf("%d", &k);
    for (int i = 1; i <= k; ++i) {
        load();
        int tmp = work();
        printf("Scenario #%d:\n", i);
        printf("%d\n", tmp);
        puts("");
    }
    return 0;
}
