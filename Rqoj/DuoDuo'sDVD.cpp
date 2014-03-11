#include <iostream>
#include <string.h>
using namespace std;
const int MAXN = 101;
const int MAXT = 1001;
int f[MAXT][MAXN];
int n, m, l;
int main()
{
    memset(f,0xff,sizeof(f));
    f[0][0] = 0;
    cin >> n >> m >> l;
    int v, t;
    for (int i = 1; i <= n; i++)
    {
        cin >> t >> v;
        for (int j = l; j >= t; j--)
            for (int k = m; k > 0; k--)
                if (f[j-t][k-1] != -1 && f[j-t][k-1]+v > f[j][k])
                    f[j][k] = f[j-t][k-1]+v;
    }
    int ans = 0;
    for (int i = 1; i <= l; i++)
        ans >?= f[i][m];
    cout << ans;
    return 0;
}
