// 最优比率生成树问题
// 可以使用两种方法求解
// 一为Dinkelbach算法，一为二分搜索算法
// 然而二分法效率较Dinkelbach算法较为低下
// 所以我采用Dinkelbach算法求解此问题 

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
const int MAXN = 1005;
const double INF = 1e10;
const double PRECISION = 1e-6;

struct Village {
    int x, y;
    int h;
} vil[MAXN];

int n;
bool load() {
    scanf("%d", &n);
    if (!n)
        return false;
    for (int i = 1; i <= n; ++i)
        scanf("%d%d%d", &vil[i].x, &vil[i].y, &vil[i].h);
    return true;
}

struct Node {
    int id;
    int pre;
    double dis;
    friend bool operator<(const Node &a, const Node &b) {
        return a.dis > b.dis;
    }
    Node(int id_,double dis_,int pre_):
        id(id_),dis(dis_),pre(pre_) { }
};

double ratio;
bool ouq[MAXN];
double dis[MAXN];
double len[MAXN][MAXN];
double ht[MAXN][MAXN];

double prim() {
    memset(ouq,0,sizeof(ouq));
    for (int i = 2; i <= n; ++i)
        dis[i] = INF;
    dis[1] = 0.0;
    
    priority_queue<Node> que;
    que.push(Node(1,0.0,1));
    int ct = 0;
    
    double scost = 0.0, slen = 0.0;
    while (true) {
        Node t = que.top();
        que.pop();
        int u = t.id;
        int pre = t.pre;
        if (ouq[u])
            continue;
        ouq[u] = true;
        slen += len[pre][u];
        scost += ht[pre][u];
        ++ct;
        if (ct == n)
            break;
        
        for (int v = 1; v <= n; ++v)
            if (!ouq[v]) {
                double tlen = ht[u][v] - ratio*len[u][v];
                if (tlen < dis[v]) {
                    dis[v] = tlen;
                    que.push(Node(v,dis[v],u));
                }
            }
    }
    return scost/slen;
}


void work() {
    for (int i = 1; i < n; ++i)
        for (int j = i+1; j <= n; ++j) {
            len[i][j] = len[j][i] = sqrt(pow(vil[i].x-vil[j].x,2.0)+pow(vil[i].y-vil[j].y,2.0));
            ht[i][j] = ht[j][i] = abs(vil[i].h-vil[j].h);
        }
    
    ratio = 0.0;
    double tmp;
    while (true) {
        tmp = prim();
        if (fabs(tmp-ratio) < PRECISION)
            break;
        ratio = tmp;
    }
    printf("%.3lf\n", ratio);
}

int main() {
    while (load())
        work();
    return 0;
}
