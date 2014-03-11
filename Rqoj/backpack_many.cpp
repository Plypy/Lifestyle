//À²À²++ --ÃÔÃÔºýºý¡·¡£¡£
//careless leads small problem
//small problem leads big problem
//big problem leads failure 
#include <iostream>
#include <string.h>
#include <limits.h>
using namespace std;
int K, V, N, a, b, i, j, k, ct1, ct2, ans;
int f[5001][51], tmp[51];
int main()
{
    scanf("%d%d%d", &K, &V, &N);
    for (i = 0; i <= V; i++)
        for (j = 1; j <= K; j++)
            f[i][j] = INT_MIN;
    f[0][1] = 0;
    for (i = 1; i <= N; i++)
    {
        scanf("%d%d", &a, &b);
        for (j = V; j >= a; j--)
        {
            for (k = ct1 = ct2 = 1; k <= K; k++)
            {
                if (f[j][ct1]<f[j-a][ct2]+b)
                    tmp[k] = f[j-a][ct2++]+b;
                else
                    tmp[k] = f[j][ct1++];
            }
            for (k = 1; k <= K; k++)
                f[j][k] = tmp[k];
        }
    }
    for (i = 1; i <= K; i++)
        ans += f[V][i];
    cout << ans;
    return 0;
}
/*
2 10 5
3 12
7 20
2 4
5 6
1 1
*/
