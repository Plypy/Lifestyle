#include <iostream>
using namespace std;
const int MAXN = 1001;
struct tree
{
    int son;
    int bro;
    int val;
}v[MAXN];
bool vis[MAXN];
int memo[MAXN][2];
int k, m;
int dp(int index, int buy);
int main()
{
    scanf("%d%d",&k,&m);
    for (int i = 1; i <= k; i++)
        scanf("%d", &v[i].val);
    int a, b;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &a, &b);
        vis[b] = true;
        v[b].bro = v[a].son;
        v[a].son = b;
    }
    int ans = 0;
    for (int i = 1; i <= k; i++)
        if (!vis[i])
            ans += max(dp(i,0),dp(i,1));
    cout << ans;
    return 0;
}
int dp(int index, int buy)
{
    if (memo[index][buy])
        return memo[index][buy];
    int res = 0;
    if (buy)
    {
        res += v[index].val;
        for (int i = v[index].son; i; i = v[i].bro)
            res += dp(i,0);
    }
    else
        for (int i = v[index].son; i; i = v[i].bro)
            res += max(dp(i,0),dp(i,1));
    return memo[index][buy] = res;
}
