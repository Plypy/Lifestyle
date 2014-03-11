/*
  Name: DjikstraWithPriority_queue
  Author: Ply_py
  Date: 04-04-11
*/

#include <iostream>
#include <cstdio>
#include <queue>
#include <cstdlib>
using namespace std;
const int MAXN = 30001;
const int MAXM = 300001;
const int INF = 0x7ffffff;
struct edge
{
    int vtx;
    int len;
} edg[MAXM];
struct node
{
    int dis;
    int vtx;
    node(int _vtx = 0, int _dis = INF):
        vtx(_vtx),dis(_dis){ }
    bool operator<(const node &t)const
    {
        return t.dis<dis;
    }
};
int adj[MAXN], nxt[MAXM];
int ct;
int n, m;
void add(int u, int v, int l)
{
    edg[++ct].vtx = v;
    edg[ct].len = l;
    nxt[ct] = adj[u];
    adj[u] = ct;
}
void load()
{
    scanf("%d%d", &n, &m);
    int u, v, l;
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d%d", &u, &v, &l);
        add(u,v,l);
        add(v,u,l);
    }
}
bool used[MAXN];
int dis[MAXN];
void work()
{
    priority_queue<node> que;
    node cur;
    for (int i = 2; i <= n; i++)
        dis[i] = INF;
    que.push(node(1,0));
    int u, v, tdis;
    while (!que.empty())
    {
        cur = que.top();
        que.pop();
        u = cur.vtx;
        tdis = cur.dis;
        if (u == n)
            break;
        if (used[u])
            continue;
        used[u] = true;
        for (int t = adj[u]; t; t = nxt[t])
        {
            if (used[v = edg[t].vtx])
                continue;
            if (dis[v] > tdis+edg[t].len)
            {
                dis[v] = tdis+edg[t].len;
                que.push(node(v,dis[v]));
            }
        }
    }
    printf("%d\n",dis[n]);
    //system("pause");
}
int main()
{
    load();
    work();
    return 0;
}

