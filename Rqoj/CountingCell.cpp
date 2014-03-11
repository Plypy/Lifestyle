#include <iostream>
#include <cstdlib>
using namespace std;
const int MAXN = 85;
bool table[MAXN][MAXN];
bool used[MAXN][MAXN];
int m, n;
int ans;
const int move[4][2] = {
    {-1,0},
    {1,0},
    {0,-1},
    {0,1}
};
void dfs(int x, int y)
{
    used[x][y] = true;
    int dx, dy;
    for (int i = 0; i < 4; ++i)
    {
        dx = x+move[i][0];
        dy = y+move[i][1];
        if (!used[dx][dy] && table[dx][dy])
            dfs(dx,dy);
    }
}
int main()
{
    cin >> m >> n;
    char ch;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
        {
            cin >> ch;
            table[i][j] = ch!='0';
        }
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            if (!used[i][j] && table[i][j])
            {
                ++ans;
                dfs(i,j);
            }
    cout << ans << endl;
//    system("pause");
    return 0;
}
