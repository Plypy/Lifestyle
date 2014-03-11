/*
    ID : jake1994
    PROG : bigbrn
    LANG : C++
*/
// 思路：用动态规划即可,用f[i][j]表示以(i,j)为右下角的最大的正方形边长 
//方程 f[i][j] = min(f[i][j-1],f[i-1][j],f[i-1][j-1])+1(f[i][j]可行) 
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("bigbrn.in");
ofstream fout("bigbrn.out");
const int MAXN = 1001;
bool map[MAXN][MAXN];
int f[MAXN][MAXN];
inline int min(int a, int b)
{
    return a<b?a:b;
}
int main()
{
    int n, t;
    fin >> n >> t;
    for (int i = 1; i <= t; i++)
    {
        int x, y;
        fin >> x >> y;
        map[x][y] = true;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (!map[i][j])
                f[i][j] = min(f[i-1][j-1],min(f[i-1][j],f[i][j-1]))+1;
            if (f[i][j] > ans)
                ans = f[i][j];
        }
    fout << ans << endl;
    fin.close();
    fout.close();
    return 0;
}
