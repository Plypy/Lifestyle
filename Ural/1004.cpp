// Using the Floyd Algorithm to find the minimum lenth simple cycle in a
// undirected graph.
// 思路：使用Floyd寻找最小环，在松弛的时候记录中间节点，然后根据中间节点进行深搜
// 记录下路径即可 
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int MAXN = 101;
int map[MAXN][MAXN];
int dis[MAXN][MAXN];
int mid[MAXN][MAXN];
int ans[MAXN];
int ct;
const int INF = 52111425;
inline int min(int a, int b)
{
    return a<b?a:b;
}
void search(int a, int b)
{
    int t = mid[a][b];
    if (mid[a][t])
        search(a,t);
    ans[++ct] = t;
    if (mid[t][b])
        search(t,b);
}
int main()
{
    //freopen("test.in","r", stdin);
    //freopen("test.out","w",stdout);
    int n, m;
    while (1)
    {
        cin >> n;
        if (n == -1)
            break;
        cin >> m;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                map[i][j] = INF;
        }
        int u, v, l;
        for (int i = 1; i <= m; i++)
        {
            cin >> u >> v >> l;
            map[u][v] = map[v][u] = min(map[u][v], l);
        }
        memset(mid,0,sizeof(mid));
        memcpy(dis,map,sizeof(dis));
        int minlen = INF;
        int tmp;
        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i < k; i++)
                if (map[k][i] != INF)
                    for (int j = i+1; j <= k; j++)
                    {
                        if (map[k][j] != INF)
                        {
                            tmp = map[k][i]+map[k][j]+dis[i][j];
                            if (tmp < minlen)
                            {
                                minlen = tmp;
                                ct = 1;
                                ans[ct] = k;
                                ans[++ct] = i;
                                if (mid[i][j])
                                    search(i,j);
                                ans[++ct] = j;
                            }
                        }
                    }
            for (int i = 1; i < n; i++)
                if (i != k)
                    for (int j = i+1; j <= n; j++)
                        if (j != k)
                        {
                            tmp = dis[i][k]+dis[k][j];
                            if (dis[i][j] > tmp)
                            {
                                dis[i][j] = dis[j][i] = tmp;
                                mid[i][j] = mid[j][i] = k;
                            }
                        }
        }
        if (minlen == INF)
            cout << "No solution." << endl;
        else
        {
            cout << ans[1];
            for (int i = 2; i <= ct; i++)
                cout << ' ' << ans[i];
            cout << endl;
        }
    }
    return 0;
}
