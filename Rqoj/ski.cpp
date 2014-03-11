#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 101;
int map[MAXN][MAXN];
bool used[MAXN][MAXN];
int mem[MAXN][MAXN];
int r, c;
int ans;
int dfs(int x, int y)
{
    if (mem[x][y])
        return mem[x][y];
    int ret = 1;
    int len = 0;
    int tmp;
    if (x > 1 && map[x-1][y] < map[x][y])
    {
        len = dfs(x-1,y);
    }
    if (x < r && map[x+1][y] < map[x][y])
    {
        tmp = dfs(x+1,y);
        if (tmp > len)
            len = tmp;
    }
    if (y > 1 && map[x][y-1] < map[x][y])
    {
        tmp = dfs(x,y-1);
        if (tmp > len)
            len = tmp;
    }
    if (y < c && map[x][y+1] < map[x][y])
    {
        tmp = dfs(x,y+1);
        if (tmp > len)
            len = tmp;
    }
    return mem[x][y] = ret+len;
}
int main()
{
//    freopen("test.in","r", stdin);
//    freopen("test.out", "w", stdout);
    cin >> r >> c;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            cin >> map[i][j];
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
        {
            if (!mem[i][j])
                dfs(i,j);
            if (ans < mem[i][j])
                ans = mem[i][j];
        }
    cout << ans << endl;
    return 0;
}
