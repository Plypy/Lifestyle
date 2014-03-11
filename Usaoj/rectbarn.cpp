/*
    ID : jake1994
    PROG : rectbarn
    LANG : C++
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("rectbarn.in");
ofstream fout("rectbarn.out");
const int MAXL = 3010;
bool dam[MAXL][MAXL];
int lt[2][MAXL];
int rt[2][MAXL];
int height[2][MAXL];
int r, c, p;
void load()
{
    fin >> r >> c >> p;
    int a, b;
    for (int i = 1; i <= p; ++i)
    {
        fin >> a >> b;
        dam[a][b] = true;
    }
    for (int i = 1; i <= c; ++i)
        dam[0][i] = dam[r+1][i] = true;
    for (int i = 1; i <= r; ++i)
    {
        dam[i][0] = dam[i][c+1] = true;
        lt[0][i] = 0;
        rt[0][i] = c+1;
    }
}
int ans;
inline int min(int a, int b)
{
    return a<b?a:b;
}
inline int max(int a, int b)
{
    return a>b?a:b;
}
void work()
{
    for (int i = 1; i <= r; ++i)
    {
        int l[MAXL] = {0};
        int tmp = 0;
        for (int j = 1; j <= c; ++j)
        {
            if (dam[i][j])
                tmp = j;
            else
                l[j] = tmp+1;
        }
        int r[MAXL] = {0};
        tmp = c+1;
        for (int j = c; j; --j)
        {
            if (dam[i][j])
                tmp = j;
            else
                r[j] = tmp-1;
        }
        int u = (i-1)&1;
        int v = i&1;
        for (int j = 1; j <= c; ++j)
        {
            if (dam[i][j])
            {
                height[v][j] = 0;
                lt[v][j] = 0;
                rt[v][j] = c+1;
            }
            else
            {
                height[v][j] = height[u][j]+1;
                lt[v][j] = max(lt[u][j],l[j]);
                rt[v][j] = min(rt[u][j],r[j]);
                ans = max(ans,height[v][j]*(rt[v][j]-lt[v][j]+1));
            }
        }
    }
    fout << ans << endl;
}

int main()
{
    load();
    work();
    return 0;
}
