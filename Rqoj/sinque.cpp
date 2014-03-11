//求两遍上升序列即可
//但还是出错了....- -
//傻叉哇
//把g弄成f了... 
//可不敢这样... 
#include <iostream>
using namespace std;
int que[110];
int n;
int f[110];
int g[110];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> que[i];
    for (int i = 1; i <= n; i++)
    {
        f[i] = 1;
        for (int j = 1; j < i; j++)
            if (que[j] < que[i])
                f[i] = max(f[i], f[j]+1);
    }
    for (int i = n; i > 0; i--)
    {
        g[i] = 1;
        for (int j = n; j > i; j--)
            if (que[j] < que[i])
                g[i] = max(g[i], g[j]+1);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, g[i]+f[i]-1);
    cout << n - ans;
    return 0;
}
