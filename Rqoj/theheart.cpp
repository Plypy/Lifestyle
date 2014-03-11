// Floyd求最小环 
#include <iostream>
#include <string.h>
#include <limits.h>
using namespace std;
const int MAXN = 251;
const int INF = 19940306;
int map[MAXN][MAXN];
int dis[MAXN][MAXN];
int n, m;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dis[i][j] = map[i][j] = INF;
    int a, b;
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        cin >> map[a][b];
        map[b][a] = dis[a][b] = dis[b][a] = map[a][b];
    }
    int ans = INF;
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i < k; i++)
            for (int j = i+1; j < k; j++)
                ans <?= map[k][i]+map[k][j]+dis[i][j];
        for (int i = 1; i <= n; i++)
            if (i != k)
                for (int j = 1; j <= n; j++)
                    if (i != j && j != k)
                        dis[i][j] <?= dis[i][k]+dis[k][j];
    }
    if (ans < INF)
        cout << ans;
    else
        cout << "He will never come back.";
    return 0;
}
