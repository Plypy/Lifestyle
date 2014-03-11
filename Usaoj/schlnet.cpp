/*
    ID : jake1994
    PROG : schlnet
    LANG : C++
*/
//算法：Kosaraju算法，《算法导论》上的那个
//求出每个强联通块，并将其视为一个点。
//然后建立新图，入度为0的点就是第一个答案
//第二个答案为，入度为0的点的个数与出度为0的点的个数中的最大值（强联通分块不止一个）
//如果强联通分块只有一个的话，即原图即为强联通的，则输出0 
#include <iostream> 
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("schlnet.in");
ofstream fout("schlnet.out");
inline int max(int a, int b)
{
    return a>b?a:b;
}
const int MAXN = 101;
bool g[MAXN][MAXN];
int n;
void load()
{
    fin >> n;
    for (int i = 1; i <= n; i++)
    {
        int t;
        while (1)
        {
            fin >> t;
            if (t)
                g[i][t] = true;
            else
                break;
        }
    }
}
bool used[MAXN];
int rep[MAXN];
int in[MAXN];
int ou[MAXN];
int cnt;
int vlist[MAXN];
void dfs(int id)
{
    used[id] = true;
    for (int i = 1; i <= n; i++)
        if (!used[i] && g[id][i])
            dfs(i);
    vlist[++vlist[0]] = id;
}
void dfs1(int id)
{
    used[id] = true;
    rep[id] = cnt;
    for (int i = 1; i <= n; i++)
        if (!used[i] && g[i][id])
            dfs1(i);
}
void work()
{
    for (int i = 1; i <= n; i++)
        if (!used[i])
            dfs(i);
    memset(used,0,sizeof(used));
    for (int i = n; i; i--)
        if (!used[vlist[i]])
        {
            cnt++;
            dfs1(vlist[i]);
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (g[i][j] && rep[i] != rep[j])
            {
                in[rep[j]]++;
                ou[rep[i]]++;
            }
}
void output()
{
    int ans1 = 0, ans2 = 0;
    for (int i = 1; i <= cnt; i++)
    {
        if (!in[i])
            ans1++;
        if (!ou[i])
            ans2++;
    }
    if (cnt>1)
        fout << ans1 << endl << max(ans1,ans2) << endl;
    else
        fout << 1 << endl << 0 << endl;
}
int main()
{
    load();
    work();
    output();
    return 0;
}
