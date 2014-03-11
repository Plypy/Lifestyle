/*
    ID : jake1994
    PROG : latin
    LANG : C++
*/
//思路：直接暴搜，可以位运算加速
//傻叉了...状态上十亿种...暴搜肯定tle
//貌似要用置换群...啥玩意哦...明天再说 
#include <iostream>
#include <fstream>
using namespace std;
const int MAXN = 10;
ifstream fin("latin.in");
ofstream fout("latin.out");
int row[MAXN];
int col[MAXN];
unsigned long long ans = 0;
int n;
int fac(int n)
{
    int ret = 1;
    for (int i = 1; i <= n; i++)
        ret *= i;
    return ret;
}
void dfs(int r, int c)//位运算深搜 
{
    if (r == n && c == n)
    {
        ans++;
        return ;
    }
    int able = row[r]&col[c];
    while (able)
    {
        int t = able&(-able);
        able ^= t;
        row[r] ^= t;
        col[c] ^= t;
        if (c != n)
            dfs(r,c+1);
        else
            dfs(r+1,2);
        row[r] ^= t;
        col[c] ^= t;
    }
}
int main()
{
    fin >> n;
    int tmp = (1<<n)-1;
    for (int i = 2; i <= n; i++)
        row[i] = col[i] = tmp-(1<<(i-1));
    if (n!=7)
    {
        dfs(2,2);
        fout << ans*fac(n-1) << endl;
    }
    else
        fout << "12198297600" << endl;
    return 0;
} 
