//���ڹ���...
//��������Ҳͦɵ���...
//��Ȼ��ΪһЩС���������3����Сʱ
//��...Ҫ���氡 
#include <iostream>
using namespace std;
const int MAXN = 1025;
struct node
{
    int son;
    int bro;
}v[MAXN];
int c[MAXN], e[MAXN];
int n, m;
int memo[MAXN][110];
int dp(int in, int mny)
{
    if (memo[in][mny])
        return memo[in][mny];
    int res = 0;
    if (mny >= c[in])
        if (v[in].bro)
            res = e[in]+dp(v[in].bro,mny-c[in]);
        else
            res = e[in];
    if (v[in].bro && v[in].son)
        for (int i = 0; i <= mny; i++)
            res >?= dp(v[in].bro,i)+dp(v[in].son,mny-i);
    else if (v[in].bro)
        res >?= dp(v[in].bro,mny);
    else if (v[in].son)
        res >?= dp(v[in].son,mny);
    return memo[in][mny] = res;
}
int main()
{
    cin >> n >> m;
    int tmp;
    for (int i = 2; i <= n; i++)
    {
        cin >> tmp;
        v[i].bro = v[tmp].son;
        v[tmp].son = i;
    }
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i <= n; i++)
        cin >> e[i];
    int ans = dp(1, m);
    cout << ans;
    return 0;
}
