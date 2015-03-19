/**
 * Description:
 * ProblemName:
 * Source:
 * Author: Ply_py
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
using namespace std;

const int MAXN = 2005;
const int MOD = 1000000007;

int dp[MAXN][MAXN];
int a[MAXN];
int n, h;

typedef long long ll;
int add(ll a, ll b) {
    return (a+b)%MOD;
}
int mult(ll a, ll b) {
    return (a*b)%MOD;
}

int solve() {
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        int dif = h-a[i];
        int maxdif = min(i,n-i+1);
        if (dif > maxdif) {
            return 0;
        }
        if (dif > 0) {
            dp[i][dif] = add(dp[i][dif], dp[i-1][dif-1]);
            dp[i][dif-1] = add(dp[i][dif-1], dp[i-1][dif-1]);
            dp[i][dif-1] = add(dp[i][dif-1], mult(dp[i-1][dif], dif));
            dp[i][dif-1] = add(dp[i][dif-1], mult(dp[i-1][dif-1], dif-1));
        }
        dp[i][dif] = add(dp[i][dif], dp[i-1][dif]);

    }
    return dp[n][0];
}

int main() {
    scanf("%d%d", &n, &h);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a+i);
    }
    int ans = solve();
    printf("%d\n", ans);
}
