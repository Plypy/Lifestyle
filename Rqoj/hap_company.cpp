//hohohoho
#include <iostream>
using namespace std;
const int MAXN = 1025;
int f[MAXN][120],p[MAXN], c[MAXN], e[MAXN],n, m;
int main()
{
    cin >> n >> m;
    for (int i = 2; i <= n; i++)
        cin >> p[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i <= n; i++)
        cin >> e[i];
    int i, j, k;
    for (i = n; i >= 1; i--)
    {
        for (j = m; j >= c[i]; j--)
            f[i][j] >?= e[i];
        for (j = m; j >= 0; j--)
            for (k = 0; k <= j; k++)
                f[p[i]][j] >?= f[p[i]][j-k]+f[i][k];
    }
    cout << f[1][m];
    cin.get();
    cin.get();
    return 0;
}
