#include <iostream>
#include <cstdlib>
using namespace std;
int n;
int f[5][37];
int sqr(int a)
{
    return a*a;
}
int main()
{
    cin >> n;
    n >>= 1;
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 36; j++)
            for (int k = 0; k <= 9 && k <= j; k++)
                f[i][j] += f[i-1][j-k];
    }
    int ans = 0;
    for (int i = 0; i <= 36; i++)
        ans += sqr(f[n][i]);
    cout << ans << endl;
    //system("pause");
    return 0;
}
