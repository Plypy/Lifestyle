#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
const int MAXN = 705;
int x[MAXN];
int y[MAXN];
int n;
int ans;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", x+i, y+i);
    int tot = 0;
    for (int i = 1; i <= n; i++)
    {
        map<double,int> ct;
        int t;
        for (int j = 1; j <= n; j++)
            if (j != i)
            {
                double tmp = double(y[j]-y[i])/double(x[j]-x[i]);
                if ((t = (++ct[tmp]))>ans)
                    ans = t;
            }
    }
    printf("%d", ans+1);
    getchar();
    getchar();
    return 0;
}
