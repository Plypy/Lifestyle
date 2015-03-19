#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2005;

double f[MAXN][MAXN];
double p;
int n, t;
int main()
{
    cout << fixed << setprecision(10);
    cin >> n >> p >> t;
    f[0][0] = 1;
    for (int i = 1; i <= t; ++i) {
        f[i][0] = (1-p)*f[i-1][0];
        for (int j = 1; j < n; ++j) {
            f[i][j] = p*f[i-1][j-1] + (1-p)*f[i-1][j];
        }
        f[i][n] = p*f[i-1][n-1] + f[i-1][n];
    }
    double ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += i*f[t][i];
    }
    cout << ans << endl;
}
