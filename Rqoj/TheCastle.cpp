/*
ID:jake1994
PROG:castle
LANG:C++
*/
//先研究～ 
#include <stdio.h>
#define MAX 15
#define MAXN 100
#define MAXC 10000
int N, M, tc, max, ansx, ansy;//推墙房间的坐标 
int map[MAXN][MAXN], tick[MAXN][MAXN], color[MAXC];
int d_x[9] = {0, 0, -1, 0, 0, 0, 0, 0, 1}; // 1 2 4 8 refer to four directions of
int d_y[9] = {0, -1, 0, 0, 1, 0, 0, 0, 0}; // W N R S
char p[9] = {' ', 'W', 'N', ' ', 'E', ' ', ' ', ' ', 'S'};
char ansc;//方向 
 
void dfs (int x, int y) // flood-fill
{
    int st = map[x][y], i;
    tick[x][y] = tc;
    ++color[tc];//颜色 
    while (st != MAX)//用dfs找链接的房间吗～ 
    {
        i = (~st) & (st + 1); // find the first zero from left - the direction without wall
        if (!tick[d_x[i] + x][d_y[i]+ y])
           dfs (d_x[i] + x, d_y[i]+ y);
        st = (st | i) & MAX;
    }
}
 
void breakwall (int x, int y, int dir)
{
    int xx = x + d_x[dir], yy = y + d_y[dir];
    int tot = 0;
    if (xx > 0 && yy > 0 && xx <= N && yy <= M)
       if (tick[xx][yy]!=tick[x][y])
          tot = color[tick[xx][yy]] + color[tick[x][y]];
       else tot = color[tick[x][y]];
    else;
    if (tot > max) max = tot, ansx = x, ansy = y, ansc = p[dir];
}
int main()
{
    freopen ("castle.in", "r", stdin);
    freopen ("castle.out", "w", stdout);
    scanf ("%d %d", &M, &N);
    int i, j;
    for (i = 1; i <= N; ++i)
        for (j = 1; j <= M; ++j)
            scanf ("%d", &map[i][j]);
    for (i = 1; i <= N; ++i)
        for (j = 1; j <= M; ++j)
            if (!tick[i][j])/*如果没有被访问过*/ ++tc/*这个变量用来标记相同的房间*/, dfs(i, j);
    for (i = 1; i <= tc; ++i)
        max = (max>color[i])?max:color[i];//寻找最大的房间的面积 
    printf ("%d\n%d\n", tc, max);//输出房间数目，和最大房间的面积 
    for (j = 1; j <= M; ++j)
        for (i = N; i >= 1; --i)//推墙啦... 
        {
            breakwall (i, j, 1 << 1); // north
            breakwall (i, j, 1 << 2); // east
        }
    printf ("%d\n%d %d %c\n", max, ansx, ansy, ansc);
    return 0;
}
