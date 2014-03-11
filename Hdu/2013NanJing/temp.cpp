#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<string>
#include<queue>
#include<map>
#include<set>
#define REP(i, n) for(int i=0; i<n; i++)
#define CLR(a, b) memset(a, b, sizeof(a))
#define PB push_back
#define LL long long
using namespace std;
const int MOD = 1e9 + 7;
int n, m;
int C, D;
int dp[2][1 << 10][22];
char ch[110][20];
int now, next;
int ALL;

void update(int nexts, int s, int nextk, int k)
{
    if (nexts & (1 << m))///转移时的条件，必须保证转移后，之前的格子，都被覆盖
    {
        dp[next][nexts ^ (1 << m)][nextk] += dp[now][s][k];
        if (dp[next][nexts ^ (1 << m)][nextk] >= MOD) dp[next][nexts ^ (1 << m)][nextk] %= MOD;
    }
}
int main()
{
    while (scanf("%d%d%d%d", &n, &m, &C, &D) != EOF)
    {
        REP(i, n) scanf("%s", ch[i]);
        CLR(dp, 0);
        now = 0;
        ALL = (1 << m) - 1;
        dp[0][ALL][0] = 1;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                next = now ^ 1;
                if (ch[i][j] == '0')/// 不可放时的转移
                {
                    for (int k = 0; k <= D; k++) for (int s = 0; s <= ALL; s++)
                        if (dp[now][s][k]) update((s << 1) ^ 1, s, k, k);
                }
                else///可以放时的转移
                {
                    for (int k = 0; k <= D; k++) for (int s = 0; s <= ALL; s++)
                        if (dp[now][s][k])
                        {
                            update((s << 1), s, k, k);///此处不放，直接转移
                            update((s << 1) ^ 1, s, k + 1, k);///放1*1块的转移
                            if (j && !(s & 1)) update((s << 1) ^ 3, s, k, k);///横着放1*2块时的转移
                            if (i && !(s & (1 << (m - 1)))) update((s << 1) ^ (1 << m) ^ 1, s, k, k);///竖着放1*2块是的转移
                        }
                }
                CLR(dp[now], 0);
                now ^= 1;
            }
        }
        int ans = 0;
        for (int i = C; i <= D; i++)
        {
            ans += dp[now][ALL][i];
            if (ans >= MOD) ans %= MOD;
        }
        printf("%d\n", ans);
    }
}