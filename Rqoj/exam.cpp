#include <iostream>
using namespace std;
const int MAXN = 101;
int f[MAXN];
int v[MAXN];
int main()
{
    int t, n, p;
    cin >> t >> n >> p;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= t; j++)
            cin >> v[j];
        for (int j = t; j >= 0; j--)
            for (int k = 1; k <= t; k++)
                if (j >= k+p)
                    f[j] >?= f[j-k-p]+v[k];
    }
    cout << f[t];
    return 0;
}
