#include <iostream>
using namespace std;
const int MAXN = 1010;
int f[MAXN], ans1, ans2, n;
int g[MAXN], h[MAXN];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> f[i];
        g[i] = h[i] = 1;
        for (int j = 1; j < i; j++)
        {
            if (f[j] >= f[i])
                g[i] >?= g[j]+1;
            else
                h[i] >?= h[j]+1;
        }
        ans1 >?= g[i];
        ans2 >?= h[i];
    }
    cout << ans1 << ' ' << ans2;
    return 0;
}
