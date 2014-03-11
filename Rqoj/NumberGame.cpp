// 设状态f[i][j]为前i个数划分为j部分能取到的最大值
// 则f[i][j] = max(f[k][j-1]*((sum[i]-sum[k])mod10))
// 粗心害死人...
// 还是老错误，是用类似滚动数组的数据结构是要注意刷掉之前的数据 
#include <iostream>
#include <cstdlib>
using namespace std;
const int MAXN = 55;
const int MAXM = 20;
int num[MAXN<<1];
int n, m;
inline int mod10(int a)
{
     return (a%10+10)%10;
}
void load()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> num[i];
        num[i+n] = num[i];
    }
}
const int INF = 52111425;
int minans = INF;
int maxans;
int minf[MAXN][MAXM];
int maxf[MAXN][MAXM];
int sum[MAXN<<1];
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
    for (int i = 1; i <= 2*n; ++i)
        sum[i] = sum[i-1]+num[i];
    for (int bg = 0; bg < n; ++bg)
    {
        for (int i = 1; i <= n; ++i)
        {
            maxf[i][1] = minf[i][1] = mod10(sum[bg+i]-sum[bg]);
            for (int j = 2; j <= min(i,m); ++j)
            {
                minf[i][j] = INF;
                maxf[i][j] = 0;
                for (int k = j-1; k < i; ++k)
                {
                    maxf[i][j] = max(maxf[i][j], maxf[k][j-1]*mod10(sum[bg+i]-sum[bg+k]));
                    minf[i][j] = min(minf[i][j], minf[k][j-1]*mod10(sum[bg+i]-sum[bg+k]));
                }
            }
        }
        minans = min(minans, minf[n][m]);
        maxans = max(maxans, maxf[n][m]);
    }
    cout << minans << endl << maxans << endl;
    //system("pause");
}
int main()
{
    load();
    work();
    return 0;
}
/*
4 2
4
3
-1


7
81
*/
