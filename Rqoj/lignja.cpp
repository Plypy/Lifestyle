#include <iostream>
using namespace std;
const int MAXN = 10005;
int dp[MAXN];
int p[MAXN];
int t[MAXN];
int n, k;
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k; i++)
        scanf("%d%d", p+i, t+i);
    int ct=k;
    for (int i = n; i >= 1; i--)
    {
        if (i != p[ct])
            dp[i] = dp[i+1]+1;
        else
            while (p[ct]==i)
                dp[i] >?= dp[i+t[ct--]];
    }
    printf("%d", dp[1]);
    return 0;
}

