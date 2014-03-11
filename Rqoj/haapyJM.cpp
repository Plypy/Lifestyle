//傻叉了...++ -- 傻傻分不清楚...
//可不敢这样...
//一个小错误就得调试好久 
#include <iostream>
using namespace std;
int n, m;
int w[60][5];
int v[60][5];
int tmpw[60];
int tmpv[60];
int tmp[60];
int f[32010];
int main()
{
    cin >> n >> m;
    n = n/10;
    for (int i = 1; i <= m; i++)
    {
        cin >> tmpw[i] >> tmpv[i] >> tmp[i];
        tmpw[i] = tmpw[i]/10;
        tmpv[i] = tmpv[i]*tmpw[i];
        if (tmp[i]==0)
        {
            w[i][1] = tmpw[i];
            v[i][1] = tmpv[i];
        }
    }
    int index;
    for (int i = 1; i <= m; i++)
    {
        if (tmp[i])
        {
            index = tmp[i];
            if (w[index][2])
            {
                w[index][3] = w[index][1]+tmpw[i];
                w[index][4] = w[index][2]+tmpw[i];
                v[index][3] = v[index][1]+tmpv[i];
                v[index][4] = v[index][2]+tmpv[i];
            }
            else
            {
                w[index][2] = w[index][1]+tmpw[i];
                v[index][2] = v[index][1]+tmpv[i];
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        if (w[i][1])
        {
            for (int j = n; j >= 0; j--)
            {
                if (j >= w[i][1] && f[j-w[i][1]]+v[i][1] > f[j])
                    f[j] = f[j-w[i][1]]+v[i][1];
                if (j >= w[i][2] && f[j-w[i][2]]+v[i][2] > f[j])
                    f[j] = f[j-w[i][2]]+v[i][2];
                if (j >= w[i][3] && f[j-w[i][3]]+v[i][3] > f[j])
                    f[j] = f[j-w[i][3]]+v[i][3];
                if (j >= w[i][4] && f[j-w[i][4]]+v[i][4] > f[j])
                    f[j] = f[j-w[i][4]]+v[i][4];
            }
        }
    }
    cout << f[n]*10;
    return 0;
}
/*
1000 5
800 2 0
400 5 1
300 5 1
400 3 0
500 2 0
*/
