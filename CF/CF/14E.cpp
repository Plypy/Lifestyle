//注意边界条件……
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 25;
int dp[MAXN][MAXN][MAXN];
int n, t;
int main() {
    scanf("%d%d", &n, &t);
    t = 2*t;
    dp[1][0][1] = dp[1][0][2] = dp[1][0][3] = 1;
    for (int i = 1; i < n; ++i)
        for (int j = 0; j <= t; ++j)
            for (int k = 1; k <= 4; ++k)
                for (int l = 1; l <= 4; ++l) {
                    if ((i == 1 && l > k) || (i != 1 && l != k)) {
                        int nj = j;
                        if (j%2 && l < k)
                            ++nj;
                        else if (j%2 == 0 && l > k)
                            ++nj;
                        dp[i+1][nj][l] += dp[i][j][k];
                    }
                }
    int ans = 0;
    for (int i = 1; i <= 4; ++i)
        ans += dp[n][t][i];
    printf("%d\n", ans);
    return 0;
}
