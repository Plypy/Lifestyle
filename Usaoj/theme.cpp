/*
    ID : jake1994
    PROG : theme
    LANG : C++
*/
//使用动态规划
//方程f[i][j] = f[i-1][j-1]+1(a[i]-a[j] = a[i-1]-a[j-1])
//注意到每次只需要考虑两个状态即i-1与i
//所以可以使用滚动数组降低时空复杂度
//另外还要注意一下细节，如ans+1才是真正答案
//还有最短长度必须为5
//另外这道题可以用二分法来做
//不过编程复杂度高，不划算 
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
ifstream fin("theme.in");
ofstream fout("theme.out");
const int MAXN = 5001;
int f[MAXN];
int bf[MAXN]; 
int dat[MAXN];
int n;
int ans;
inline int max(int a, int b)
{
    return a>b?a:b;
}
void load()
{
    fin >> n;
    for (int i = 1; i <= n; i++)
        fin >> dat[i];
}
void work()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
            if (i-bf[j-1]-1>j && dat[i]-dat[j] == dat[i-1]-dat[j-1])
            {
                f[j] = bf[j-1]+1;
                ans = max(f[j],ans);
            }
        memcpy(bf,f,sizeof(f));
        memset(f,0,sizeof(f));
    }
    fout << (ans+1>=5?ans+1:0) << endl;
}
int main()
{
    load();
    work();
    return 0;
}
