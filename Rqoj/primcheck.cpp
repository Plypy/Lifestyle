#include <stdio.h>
#include <math.h>
const int MAXN = 21;
int n, k, ans;
int list[MAXN];
inline bool check(int num)
{
    for (int i = 2; i <= int(sqrt(num)); i++)
        if (num % i == 0)
            return false;
    return true;
}
void dfs(int depth, int ct, int num)
{
    if (ct == k && check(num))
    {
        ans++;
        return;
    }
    if (depth < n)
    {
        dfs(depth+1,ct+1,num+list[depth+1]);
        dfs(depth+1,ct,num);
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    for (int i = 1; i <= n; i++)
        scanf("%d",list+i);
    dfs(0,0,0);
    printf("%d",ans);
    return 0;
}
