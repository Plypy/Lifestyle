#include <stdio.h>
#include <stdlib.h>
#define MAXN 2011
int n, m;
bool map[MAXN][MAXN];
struct point
{
    int x, y;
    int step;
    point(int _x = 0, int _y = 0, int _step = 0):
        x(_x), y(_y), step(_step){ }
} que[MAXN*MAXN];
int sx, sy, tx, ty;
void load()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            scanf("%d", &map[i][j]);
        }
    }
    for (int i = 0; i <= n+1; ++i)
        map[i][0] = map[i][m+1] = true;
    for (int i = 0; i <= m+1; ++i)
        map[0][i] = map[n+1][i] = true;
    scanf("%d%d", &sx, &sy);
    scanf("%d%d", &tx, &ty);
}
int st, ed;
bool used[MAXN][MAXN];
int move[4][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1,0}
};
void work()
{
    que[st] = point(sx, sy, 0);
    used[sx][sy] = true;
    int nx, ny, nstep;
    int dx, dy;
    int ans = -1;
    if (used[tx][ty])
    {
        st = 2;
        ans = 0;
    }
    while (st <= ed)
    {
        nx = que[st].x;
        ny = que[st].y;
        nstep = que[st++].step;
        for (int i = 0; i < 4; ++i)
        {
            dx = nx+move[i][0];
            dy = ny+move[i][1];
            if (!used[dx][dy] && !map[dx][dy])
            {
                que[++ed] = point(dx,dy,nstep+1);
                used[dx][dy] = true;
            }
        }
        if (used[tx][ty])
        {
            ans = nstep+1;
            break;
        }
    }
    if (-1 == ans)
        printf("No Answer!\n");
    else
        printf("%d\n", ans);
}
int main()
{
    load();
    work();
    return 0;
}
/*
5 5
1 1 1 1 1
1 1 1 0 0
1 0 0 0 1
0 0 1 0 0
1 1 1 0 1
4 1
5 4

6
*/
