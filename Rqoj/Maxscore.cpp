#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int MAXT = 10001;
int f[MAXT];
int t, n;
inline int max(int a, int b)
{
    return a>b?a:b;
}
int main()
{
    scanf("%d%d", &t, &n);
    int v, w;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &v, &w);
        for (int j = w; j <= t; j++)
            f[j] = max(f[j],f[j-w]+v);
    }
    printf("%d", f[t]);
    //system("pause");
    return 0;
}
