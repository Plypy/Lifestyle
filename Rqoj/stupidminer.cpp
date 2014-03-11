//进行了多余的预处理- -
//其实当那个点人数为1的时候也有可能不挖
//所以就出错了鸟... 
#include <iostream>
using namespace std;
const int MAXN = 1010;
int memo[MAXN][110];
struct node
{
    int son;
    int bro;
    int val;
}v[MAXN];
int n, m, a, b, ans;
int dp(int in, int bud);
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i].val;
    for (int i = 1; i <= n; i++)//建树 
    {
        cin >> a >> b;
        v[b].bro = v[a].son;
        v[a].son = b;
    }
    ans = dp(v[0].son,m);
    cout << ans;
    return 0;
}
int dp(int in, int bud)
{
    if (!in || !bud)
        return 0;
    if (memo[in][bud])
        return memo[in][bud];
    int res = dp(v[in].bro,bud);//不挖的情况 
    for (int i = 0; i < bud; i++)//挖的情况 
        res >?= dp(v[in].son,i)+v[in].val+dp(v[in].bro,bud-i-1);
    return memo[in][bud] = res;
}
