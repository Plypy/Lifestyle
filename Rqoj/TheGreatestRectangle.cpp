#include <iostream>
#include <climits>
#include <cstdio>
using namespace std;
const int MAXN = 101;
int sum[MAXN][MAXN];
int n;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &sum[i][j]);
            sum[i][j] += sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    int ans = INT_MIN;
    for (int p = 1; p <= n; p++)
        for (int q = p; q <= n; q++)
        {
            int f[MAXN] = {0};
            for (int i = 1; i <= n; i++)
            {
                f[i] = sum[i][q]-sum[i][p-1]-sum[i-1][q]+sum[i-1][p-1];
                if (f[i-1] > 0)
                    f[i] += f[i-1];
                ans >?= f[i];
            }
        }
    printf("%d", ans);
    return 0;
}
/*
4
0 每2 每7 0
 9 2 每6 2
-4 1 每4  1 
每1 8  0 每2
*/
/*
#include <iostream>
#include <climits>
using namespace std;
const int MAXN = 101;
int sum[MAXN][MAXN];
int n;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &sum[i][j]);
            sum[i][j] += sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    }
    int ans = INT_MIN;
    for (int p = 1; p <= n; p++)
        for (int q = 1; q <= n; q++)
            for (int i = p; i <= n; i++)
                for (int j = q; j <= n; j++)
                    ans >?= sum[i][j]+sum[p-1][q-1]-sum[i][q-1]-sum[p-1][j];
    printf("%d", ans);
    return 0;
}
*/
