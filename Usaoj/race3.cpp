/*
    ID : jake1994
    PROG : race3
    LANG : C++
*/
#include <iostream>
#include <fstream>
#include <climits>
#include <cstring>
using namespace std;
ifstream fin("race3.in");
ofstream fout("race3.out");
const int MAXN = 51;
bool graph[MAXN][MAXN];
int dis[MAXN];
int que[MAXN];
bool flag[MAXN];
bool used[MAXN];
int ans2[MAXN];
bool able[MAXN][MAXN];
int bg, ed;
int n = -1;
int t;
void bfs(int id)
{
    bg = ed = 0;
    que[bg] = id;
    int now;
    int tmp;
    while (bg <= ed)
    {
        now = que[bg++];
        for (int i = 1; i <= n; i++)
            if (dis[i]>dis[now]+1 && graph[now][i])
            {
                dis[i] = dis[now]+1;
                que[++ed] = i;
            }
    }
}
bool floyd()
{
    for (int k = 0; k <= n; k++)
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                able[i][j] |= able[i][k]&&able[k][j];
}
bool check(int id)
{
    for (int i = 0; i < n; i++)
        if (able[id][i] && dis[i] < dis[id])
            return false;
    return true;
}
bool dfs(int now, int id)
{
    if (now == n)
        return true;
    for (int i = 0; i <= n; i++)
        if (i != id && !used[i] && graph[now][i])
        {
            used[i] = true;
            if (dfs(i,id))
                return true;
            used[i] = false;
        }
    return false;
}
int main()
{
    while (t != -1)
    {
        for (++n; ;)
        {
            fin >> t;
            if (t<0)
                break;
            able[n][t] = graph[n][t] = true;
        }
    }
    --n;
    for (int i = 1; i <= n; i++)
        dis[i] = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        memset(used,0,sizeof(used));
        if (!dfs(0,i))
            flag[i] = true;
    }
    bfs(0);
    int ct = 0;
    floyd();
    for (int i = 1; i < n; i++)
        if (flag[i])
        {
            ++ct;
            if (check(i))
                ans2[++ans2[0]] = i;
        }
//output part
    fout << ct;
    for (int i = 1; i < n; i++)
        if (flag[i])
            fout << ' ' << i;
    fout << endl;
    fout << ans2[0];
    for (int i = 1; i <= ans2[0]; i++)
        fout << ' ' << ans2[i];
    fout << endl;
    return 0;
}
