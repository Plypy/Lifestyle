/**
 * Copied from Internet
 * Because of this graph is very intense, and there may be a lot of duplicate edges.
 * So we should use adjacent matrix to store this graph
 */
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#define inf 99999999
using namespace std;
int map[200][200];
int sum[200];
struct node
{
    int u,v;
};
node edge[3005];
int pre[200][200];
int first;
int bfs(int u,int n)
{
    int vis[200];
    int dd[200];
    memset(vis,0,sizeof(vis));
    memset(dd,0,sizeof(dd));
    vis[u]=1;
    dd[u]=0;
    int i;
    queue<int> q;
    q.push(u);
    int count=1;
    int s=0;
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        for(i=1;i<=n;i++)
        {
            if(!vis[i]&&map[t][i])
            {
                dd[i]=dd[t]+1;
                if(first)        //只在第一次做,
                    pre[u][i]=t; //关键优化，
                vis[i]=1;
                s+=dd[i];
                q.push(i);
                count++;
            }
        }
    }
    if(count==n)
    {
        return s;
    }
    else
        return inf;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(map,0,sizeof(map));
        memset(sum,0,sizeof(sum));
        int i;
        memset(pre,0,sizeof(pre));
        first=1;
        for(i=0;i<m;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            map[a][b]++;
            map[b][a]++;
            edge[i].u=a;
            edge[i].v=b;
        }
        int flag=0;
        int ss=0;
        for(i=1;i<=n;i++)
        {
            sum[i]=bfs(i,n);
            ss+=sum[i];
            if(sum[i]==inf)
            {
                flag=1;
                break;
            }
        }
        if(flag)
        {
            for(i=0;i<m;i++)
                printf("INF\n");
            continue;
        }
        first=0;
        for(i=0;i<m;i++)
        {
            int s=0;
            if(map[edge[i].u][edge[i].v]>1)
                printf("%d\n",ss);
            else if(map[edge[i].u][edge[i].v]==1)
            {

                int j;
                for(j=1;j<=n;j++)
                {
                    if(pre[j][edge[i].v]!=edge[i].u&&pre[j][edge[i].u]!=edge[i].v)      //关键优化  迅速判断出该边是不是最短树上的路径
                        s+=sum[j];
                    else
                    {
                        map[edge[i].u][edge[i].v]--;
                        map[edge[i].v][edge[i].u]--;
                        s+=bfs(j,n);
                        if(s>=inf)
                            break;
                        map[edge[i].u][edge[i].v]++;
                        map[edge[i].v][edge[i].u]++;
                    }
                }
                if(j>n)
                    printf("%d\n",s);
                else
                    printf("INF\n");
            }
        }
    }
    return 0;
}
