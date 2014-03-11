#include <iostream>
#include <math.h>
using namespace std;
int n, m, x, y;
long long map[21][21];
bool safe(int a, int b)
{
    return !((abs(a-x)*abs(b-y)==2) || (a==x && b == y));
}
int main()
{
    cin >> n >> m >> x >> y;
    map[0][0] = 1;
    for (int i = 1; safe(i,0) && i<=n; i++)
        map[i][0] = map[i-1][0];
    for (int i = 1; safe(0,i) && i<=m; i++)
        map[0][i] = map[0][i-1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (safe(i,j))
                map[i][j] = map[i-1][j]+map[i][j-1];
    cout << map[n][m];
    return 0;
}
