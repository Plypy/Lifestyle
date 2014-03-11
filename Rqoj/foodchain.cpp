#include <iostream>
using namespace std;
const int MAXN = 50001;
int f[MAXN];
int d[MAXN];
int r[MAXN];
int n, k;
inline int find(int a)
{
    if (a == f[a])
        return a;
    int res = find(f[a]);
    d[a] = (d[f[a]]+d[a])%3;
    return f[a] = res;
}
inline int same(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if (fx == fy)
    {
        if (d[x] == d[y])
            return 0;
        else
            return 1;
    }
    f[fx] = fy;
    d[fx] = (d[y]-d[x]+3)%3;
    return 0;
}
inline int eat(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if (fx == fy)
    {
        if ((d[x]+1)%3 == d[y])
            return 0;
        else
            return 1;
    }
    f[fx] = fy;
    d[fx] = (d[y]-d[x]+2)%3;
    return 0;
}
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        f[i] = i;
    int ans = 0;
    int p, x, y;
    for (int i = 1; i <= k; i++)
    {
        scanf("%d%d%d", &p, &x, &y);
        if (x > n || y > n)
            goto wrong;
        if (p == 1)
            ans += same(x,y);
        else
            ans += eat(x,y);
        continue;
        wrong:
            ans++;
    }
    printf("%d", ans);
    getchar();
    getchar();
    return 0;
}
