#include <iostream>
#include <cstdlib>
using namespace std;
const int MAXN = 101;
int f[MAXN][5*MAXN];
int cost[MAXN][5*MAXN];
short pre[MAXN][5*MAXN];
int m, n;
void load()
{
    cin >> m >> n;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
        {
            cin >> cost[i][j];
        }
}
int ans[MAXN<<3];
void work()
{
    bool flag;
    for (int i = 1; i <= m; ++i)
    {
        flag = true;
        for (int j = 1; j <= n; ++j)
            f[i][j] = f[i-1][j]+cost[i][j];
        while (flag)//更简单的方法是先从左向右推一遍，再从右向左推一遍 
        {
            flag = false;
            for (int j = 1; j <= n; ++j)
            {
                if (j > 1 && f[i][j-1]+cost[i][j] < f[i][j])
                {
                    f[i][j] = f[i][j-1]+cost[i][j];
                    pre[i][j] = -1;
                    flag = true;
                }
                if (j < n && f[i][j+1]+cost[i][j] < f[i][j])
                {
                    f[i][j] = f[i][j+1]+cost[i][j];
                    pre[i][j] = 1;
                    flag = true;
                }
            }
        }
    }
    int minid = 1;
    for (int i = 2; i <= n; ++i)
        if (f[m][i] < f[m][minid])
            minid = i;
    int cur = minid;
    for (int i = m; i; --i)
    {
        while (1)
        {
            ans[++ans[0]] = cur;
            if (pre[i][cur] == 0)
                break;
            cur += pre[i][cur];
        }
    }
    cout << ans[ans[0]];
    for (int i = ans[0]-1; i; --i)
        cout << ' ' << ans[i];
    cout << endl;
    //system("pause");
}
int main()
{
    load();
    work();
    return 0;
}
/*
3 4
10 10 1 10
2 2 2 10
1 10 10 10
*/
