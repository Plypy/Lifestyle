//floyd«ÛΩ‚ 
#include <iostream>
#include <limits.h>
using namespace std;
const int MAXN = 101;
int N;
int data[MAXN];
int list[MAXN][MAXN];
int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            list[i][j] = MAXN*10;
    int l, r;
    for (int i = 1; i <= N; i++)
    {
        cin >> data[i] >> l >> r;
        list[i][i] = 0;
        if (l)
            list[i][l] = list[l][i] = 1;
        if (r)
            list[i][r] = list[r][i] = 1;
    }
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            if (i != k)
                for (int j = 1; j <= N; j++)
                    if (j != i && j!= k)
                        list[i][j] <?= list[i][k] + list[k][j];
    int sum;
    int min = INT_MAX;
    for (int i = 1; i <= N; i++)
    {
        sum = 0;
        for (int j = 1; j <= N; j++)
            sum += data[j]*list[i][j];
        min <?= sum;
    }
    cout << min;
    return 0;
}
