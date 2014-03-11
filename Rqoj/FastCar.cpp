#include <iostream>
#include <cstdlib>
using namespace std;
const int MAXN = 110;
const int MAXK = 15;
const int INF = 52111425;
inline int min(int a, int b)
{
    return a<b?a:b;
}
bool car[MAXN][MAXK];
int bump[MAXN][MAXK];
int n, k;
void load()
{
    cin >> n >> k;
    char ch;
    for (int i = n; i; --i)
        for (int j = 1; j <= k; ++j)
        {
            cin >> ch;
            if (ch == '1')
                car[i][j] = true;
            bump[i][j] = INF;
        }
    if (n&1)
    {
        ++n;
        for (int i = 1; i <= k; ++i)
            bump[n][i] = INF;
    }
    for (int i = 0; i <= n; ++i)
        bump[i][0] = bump[i][k+1] = INF;
}
void work()
{
    for (int i = 2; i <= n; i+=2)
    {
        for (int j = 1; j <= k; ++j)
            bump[i][j] = car[i][j]+min(bump[i-2][j]+car[i-1][j],
                                        min(bump[i-2][j-1],bump[i-2][j+1]));
    }
    int ans = INF;
    for (int i = 1; i <= k; ++i)
        if (bump[n][i] < ans)
            ans = bump[n][i];
    cout << ans << endl;
}
int main()
{
    load();
    work();
    return 0;
}

