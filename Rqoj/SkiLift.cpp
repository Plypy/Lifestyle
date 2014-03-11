#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;
const int MAXN = 5001;
int f[MAXN];
int list[MAXN];
int n, k;
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        scanf("%d", list+i);
    f[1] = 1;
    int tmp;
    double x, m;
    for (int i = 2; i <= n; ++i)
    {
        m = f[i] = INT_MAX;
        tmp = max(i-k,1);
        for (int j = i-1; j >= tmp; --j)
        {
            x = double(list[i]-list[j])/double(i-j);
            m <?= x;
            if (x <= m && f[j]+1 < f[i])
                f[i] = f[j]+1;
        }
    }
    cout << f[n];
    return 0;
}
