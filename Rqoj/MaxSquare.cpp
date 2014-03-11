#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 1005;
int map[MAXN][MAXN];
inline int min(int a, int b, int c)
{
    if (a > b)
        a = b;
    return a<c?a:c;
}
int main()
{
    int r, c;
    cin >> r >> c;
    int flag = 0;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
        {
            scanf("%d", &map[i][j]);
            flag |= map[i][j];
        }
    if (flag == 0)
    {
        cout << 0;
        return 0;
    }
    int ans = 0;
    for (int i = 2; i <= r; i++)
        for (int j = 2; j <= c; j++)
            if (map[i][j])
                ans >?= map[i][j] = min(map[i][j-1], map[i-1][j], map[i-1][j-1])+1;
    if (ans)
        cout << ans*ans;
    else
        cout << 1;
    return 0;
}
