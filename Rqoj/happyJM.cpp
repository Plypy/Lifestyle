//开心的金明
//试一次二维背包 
//再次反思
//咱本来就起步的晚
//就必须得加倍的努力
//否则什么都得不到 
#include <iostream>
using namespace std;
int n, m;
int f[26][30000];
int main()
{
    cin >> n >> m;
    int v, p;
    for (int i = 1; i <= m; i++)
    {
        cin >> v >> p;
        p = v*p;
        for (int j = 0; j <= n; j++)//f[i][j]记录在第i件，使用了j的钱的时候能得到的最大重要度 
        {//前面也要赋值啊... 
            f[i][j] = f[i-1][j];//不拿的情况 
            if (j - v >= 0) 
                if (f[i][j] < f[i-1][j-v]+p)//拿的情况
                    f[i][j] = f[i-1][j-v]+p;
        }
    }
    cout << f[m][n];
    return 0;
}
