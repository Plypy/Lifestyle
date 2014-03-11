#include <iostream>
using namespace std;
const int MAXN = 131;
int dp[MAXN][MAXN];
int n, sum;
int main()
{
    cin >> n;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            for (int k = 0; k < j; k++)
                dp[i][j] += dp[i-j][k];
    for (int i = 1; i < n; i++)
        sum += dp[n][i];
    for (int i = 1; i <= n; i++)
        cout << dp[n][i] << ' ';
    cout << endl;
    cout << sum;
    cin.get();
    cin.get();
    return 0;
}
