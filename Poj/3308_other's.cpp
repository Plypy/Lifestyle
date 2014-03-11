#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
#define inf 1000000
#define size 200
#define eps 1e-8
struct edge
{
    int from;
    int to;
    int next;
    double val;
}e[140000];
int v[size];//顶点集合
int que[size];//在bfs中当队列用，在Dinic中当作栈来用
int dis[size];//距离，层次图
int cnt;//计数
int cur[size];//当前从某顶点要出发的流所对应的边，-1代表没有了
void insert(int from, int to, double va)
{
    e[cnt].from = from;
    e[cnt].to = to;
    e[cnt].val = va;
    e[cnt].next = v[from];
    v[from] = cnt++;
    e[cnt].from = to;
    e[cnt].to = from;
    e[cnt].val = 0;
    e[cnt].next = v[to];
    v[to] = cnt++;
}
bool bfs(int n, int s, int t)//广搜
{
    int head, tail, i;
    head = tail = 0;
    que[tail++] = s;//源点入列
    memset(dis, -1, sizeof(int) * n);
    dis[s] = 0;
    while(head < tail) // bfs,得到顶点i的距s的最短距离dis[i]
        for(i = v[que[head++]]; i != -1; i = e[i].next)
            if (e[i].val > eps && dis[e[i].to] == -1)
            { //dis[e[i].to] == -1说明了顶点e[i].to没被访问到
                dis[e[i].to] = dis[e[i].from] + 1;
                que[tail++] = e[i].to;
                if (e[i].to == t)
                    return true;//如果能遍历到汇点，说明还有增广路径
            }
    return false;
}

double Dinic(int N, int s, int t)//N=t+1
{
    double maxflow = 0, tmp;
    int i;
    while(bfs(N, s, t))//每循环一次e[].val的值会发生变化,bfs的结果也会发生变化
    {
        int u = s, tail = 0;
        for(i = 0; i <=N; i++)//N=t+1
            cur[i] = v[i];
        while(cur[s] != -1)//s是源点
            if (u != t && cur[u] != -1 && e[cur[u]].val > eps && dis[u] != -1 && dis[u] + 1 == dis[e[cur[u]].to])
            {//如果没有到达汇点t&&从u出发还有流&&这条流不为0&&u是在此次BFS中能访问到的点&&u不是某条流的终点
                que[tail++] = cur[u];//边纳入队列栈中
                u = e[cur[u]].to;// 流往前推进
            }
            else
                if (u == t)//找到一条增广路
                {
                    for(tmp = inf, i = tail - 1; i >= 0; i--)//找出最小的，残留网络
                        tmp = min(tmp, e[que[i]].val);
                    for(maxflow += tmp, i = tail - 1; i >= 0; i--)//消灭这条增广路径
                    {
                        e[que[i]].val -= tmp;
                        e[que[i]^ 1].val += tmp;
                        if (fabs(e[que[i]].val) <= eps)
                            tail = i;
                    }
                    u = e[que[tail]].from;
                }
                else
                {
                    while(tail > 0 && u != s && cur[u] == -1)
                        u = e[que[--tail]].from;
                    cur[u] = e[cur[u]].next;
                }
    }
    return maxflow;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    int T, n, m, l, a, b;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d", &n, &m, &l);
        int s = 0, t = n + m + 1;//s源点，t汇点
        double tmp;
        memset(v, -1, sizeof(int) * (t + 1));
        cnt = 0;
        for(int i = 1; i <= n; i++)//建立源点s->X的边
        {
            scanf("%lf", &tmp);
            insert(s, i, log(tmp));
        }
        for(int j = 1; j <= m; j++)//建立源点Y->t的边
        {
            scanf("%lf", &tmp);
            insert(j + n, t, log(tmp));
        }
        while(l--)//如果（i,j）处有伞兵，那么集合X内的点i向集合Y内的点j连一条容量为无穷大的边。
        {
            scanf("%d%d", &a, &b);
            insert(a, b + n, inf);
        }
        tmp = Dinic(t + 1, s, t);
        printf("%.4f\n", exp(tmp));
    }
    return 0;
}
