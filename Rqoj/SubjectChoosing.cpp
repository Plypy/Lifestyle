// f[i][j] 表示前i个课题完成j篇论文所需最短的时间
// 可以看出若第i个课题完成t个论文那么我们就需要求f[i-1][j-t]显然这是个子问题
// 而且可以应用剪切法证明具有最优子问题的性质
// 考虑到任何时刻只需要f[i]与f[i-1]这两个数组，我们可以使用滚动数组优化空间需求
// 将f全部初始化为INFINITY ,f[0][0]设为0即可 
#include <iostream>
#include <cmath>
#include <cstring>
#include <climits>
#include <cstdlib>
using namespace std;
const int MAXN = 210;
const int MAXM = 30;
typedef unsigned long long ull;
int a[MAXM], b[MAXM];
ull f[2][MAXN];
int n, m;
void load()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
        cin >> a[i] >> b[i];
}
ull ans = LLONG_MAX;
ull min(ull a, ull b)
{
    return a<b?a:b;
}
ull power(int bas, int p)
{
    ull ret = 1;
    for (int i = 1; i <= p; ++i)
        ret *= bas;
    return ret;
}
void work()
{
    for (int i = 1; i <= n; ++i)
        f[0][i] = LLONG_MAX;
    int u, v;
    for (int i = 1; i <=m; ++i)
    {
        u = (i-1)&1;
        v = i&1;
        for (int j = 1; j <= n; ++j)
            f[v][j] = f[u][j];
        for (int j = 1; j <= n; ++j)
            for (int k = 1; k <= j; ++k)
                f[v][j] = min(f[v][j],f[u][j-k]+a[i]*power(k,b[i]));
        ans = min(ans,f[v][n]);
    }
}
void output()
{
    cout << ans << endl;
}
int main()
{
    load();
    work();
    output();
    //system("pause");
    return 0;
}
