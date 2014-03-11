#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int MAXN = 505;
int n, m;
int ht[MAXN][MAXN];
int flag[MAXN][MAXN];
void load()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", &ht[i][j]);
}
int move[4][2] = {
    {0,1},
    {1,0},
    {-1,0},
    {0,-1}
};
struct segment
{
    int st, ed;
} seg[MAXN];
void dfs(int x, int y, int label)
{
    flag[x][y] = label;
    if (x == n)
    {
        if (!seg[label].st || seg[label].st > y)
            seg[label].st = y;
        if (seg[label].ed < y)
            seg[label].ed = y;
    }
    int dx, dy;
    for (int i = 0; i < 4; ++i)
    {
        dx = x+move[i][0];
        dy = y+move[i][1];
        if (ht[x][y] > ht[dx][dy] && flag[dx][dy] != label)
            dfs(dx,dy,label);
    }
}
int cmp(const void *a, const void *b)
{
    return ((segment *)(a))->st - ((segment *)(b))->st;
}
int f[MAXN];
const int INF = 52111425;
inline int min(int a,int b)
{
    return a<b?a:b;
}
void work()
{
    for (int i = 0; i <= m+1; ++i)
        ht[0][i] = ht[n+1][i] = INF;
    for (int i = 0; i <= n+1; ++i)
        ht[i][0] = ht[i][m+1] = INF;
    for (int i = 1; i <= m; ++i)
        if (!flag[1][i])
            dfs(1,i,i);
    int ct = 0;
    for (int i = 1; i <= m; ++i)
        if (!flag[n][i])
            ++ct;
    if (ct)
    {
        cout << 0 << endl;
        cout << ct << endl;
    }
    else
    {
        for (int i = 1; i <= m; ++i)
            f[i] = INF;
        qsort(seg+1,m,sizeof(segment),cmp);
        for (int j = 1; j <= m; ++j)
            for (int i = seg[j].st; i <= seg[j].ed; ++i)
                f[i] = min(f[i],f[seg[j].st-1]+1);
        //for (int i = 1; i <= m; ++i)
        //    for (int j = 1; j <= m; ++j)
        //        if (seg[j].st <= i && i <= seg[j].ed)
        //            f[i] = min(f[i],f[seg[j].st-1]+1);
        cout << 1 << endl;
        cout << f[m] << endl;
    }
}
int main()
{
    load();
    work();
    //system("pause");
    return 0;
}
