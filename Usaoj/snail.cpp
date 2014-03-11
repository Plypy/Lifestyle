/*
    ID : jake1994
    PROG : snail
    LANG : C++
*/
//总结...要有清醒的头脑
//要时刻明白你正在干什么
//才可以不至于犯迷糊..
//搜索还是我的弱项啊
//这样一道简单的搜索题，竟然都用了近3个小时
//其实也跟自己精神不集中有关...
//这道题的解法：深搜即可，没有难度 
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("snail.in");
ofstream fout("snail.out");
const int MAXN = 125;
const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,1,-1};
short map[MAXN][MAXN];
int n, m;
void load()
{
    fin >> n >> m;
    for (int i = 1; i <= n; i++)
        map[0][i] = map[i][0] = map[n+1][i] = map[i][n+1] = -1;
    for (int i = 1; i <= m; i++)
    {
        char ch;
        int t;
        fin >> ch >> t;
        map[t][ch-'A'+1] = -1;
    }
}
int ans;
void dfs(int x, int y, int len, int dir)
{
    int tx = x, ty = y;
    while (map[tx+dx[dir]][ty+dy[dir]] == 0)
    {
        map[tx][ty] = 1;
        len++;
        tx+=dx[dir];
        ty+=dy[dir];
    }
    if (len > ans)
        ans = len;
    if (map[tx+dx[dir]][ty+dy[dir]] == -1)
        for (int d = 0; d < 4; d++)
            if (map[tx+dx[d]][ty+dy[d]] == 0)
                dfs(tx,ty,len,d);
    while (tx!=x || ty!=y)
    {
        map[tx][ty] = 0;
        tx-=dx[dir];
        ty-=dy[dir];
    }
}
void solve()
{
    map[1][1] = 1;
    dfs(1,1,1,0);
    dfs(1,1,1,2);
    fout << ans << endl;
}
int main()
{
    load();
    solve();
    return 0;
}
