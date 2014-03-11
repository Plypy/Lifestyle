#include <iostream>
using namespace std;
const int MAXN = 32767;
int n, m;
int f[MAXN];
int main()
{
    cin >> n >> m;
    f[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            f[j] = f[j-1]+f[j];
    cout << f[m];
    return 0;
}
