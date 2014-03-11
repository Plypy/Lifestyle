//dfs¼´¿É
//×¢ÒâÏ¸½Ú°¡ 
#include <iostream>
#include <cstdlib>
using namespace std;
const int MAXN = 50;
bool map[MAXN][MAXN];
int n;
void load()
{
    cin >> n;
    char ch;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            cin >> ch;
            if ('.' == ch)
                map[i][j] = true;
        }
}
int ans;
bool used[MAXN][MAXN];
int step[4][2] = {
    {0,1},
    {0,-1},
    {1,0},
    {-1,0}
};
void dfs(int x, int y)
{
    used[x][y] = true;
    int dx, dy;
    for (int i = 0; i < 4; ++i)
    {
        dx = x+step[i][0];
        dy = y+step[i][1];
        if (map[dx][dy])
        {
            if (!used[dx][dy])
                dfs(dx,dy);
        }
        else
            ++ans;
    }
}
void work()
{
    dfs(1,1);
    if (!used[n][n])
        dfs(n,n);
    cout << (ans-4)*9 << endl;
}
int main()
{
    load();
    work();
    //system("pause");
    return 0;
}
