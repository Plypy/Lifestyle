#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;
const int MAXN = 50;
int sum[MAXN][MAXN][MAXN]; // h m n
int h, m, n;
int main()
{
    scanf("%d%d%d", &h, &m, &n);
    for (int p = 1; p <= h; p++)
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
            {
                scanf("%d", &sum[p][i][j]);
                sum[p][i][j] += sum[p][i-1][j]+sum[p-1][i][j]+sum[p][i][j-1]+sum[p-1][i-1][j-1]-sum[p][i-1][j-1]-sum[p-1][i][j-1]-sum[p-1][i-1][j];
                //这行真tm长... 
            }
    int ans = INT_MIN;
    int f[MAXN] = {0};
    for (int a = 1; a <= m; a++)
        for (int b = 1; b <= n; b++)
            for (int c = a; c <= m; c++)
                for (int d = b; d <= n; d++)
                    for (int i = 1; i <= h; i++)
                    {
                        f[i] = sum[i][c][d]+sum[i][a-1][b-1]-sum[i][c][b-1]-sum[i][a-1][d]-(sum[i-1][c][d]+sum[i-1][a-1][b-1]-sum[i-1][c][b-1]-sum[i-1][a-1][d]);
                        //没想到啊...这行更tm长 
                        if (f[i-1] > 0)
                            f[i] += f[i-1];
                        ans >?= f[i];
                    }
    printf("%d", ans);
    return 0;
}
