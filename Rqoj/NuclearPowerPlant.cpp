#include <iostream>
using namespace std;
const int MAXN = 60;
long long f[MAXN];
int main()
{
    int n, m;
    cin >> n >> m;
    f[0] = 1;
    for (int i = 1; i < m; i++)
        f[i] = f[i-1]<<1;
    f[m] = f[m-1]*2-1;
    for (int i = m+1; i <= n; i++)
        f[i] = (f[i-1]<<1)-f[i-m-1];
    cout << f[n];
    return 0;
}
