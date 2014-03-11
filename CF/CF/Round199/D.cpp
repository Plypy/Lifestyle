/**
 * Description:
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
#include <map>
#include <vector>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
using namespace std;

const int MAXN = 100005;
const int MAXM = 3;
const int MAXS = 8;
const int MOD = 1000000007;
typedef long long ll;

int add(ll a, ll b) {
    return (a+b)%MOD;
}

int dp[MAXN][MAXS];
int table[MAXM][MAXN];
char buf[MAXM][MAXN];
int state[MAXN];
int n;
int m = 3;

int solve(int flag) {
    memset(dp,0,sizeof(dp));
    dp[0][7] = 1;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < MAXS; ++j) if (dp[i][j]) {
            int mask = 0, fail = 0;
            for (int k = 0; k < MAXM; ++k) {
                if ((1<<k)&j)
                    continue;
                if ('.' != buf[k][i-1])
                    continue;
                if (flag && buf[k][i+1] == 'O')
                    fail = 1;
                if (flag && i > 1 && buf[k][i-2] == 'O')
                    fail = 1;
                mask += 1<<k;
            }
            if (fail)
                continue;
            if (state[i] != (mask | state[i]))
                continue;
            dp[i+1][mask] = add(dp[i+1][mask],dp[i][j]);
            if (mask+3 == (mask|3)) {
                if (flag && buf[2][i] == 'O') {}
                else {
                    mask += 3;
                    if ((mask | state[i]) == state[i])
                        dp[i+1][mask] = add(dp[i+1][mask],dp[i][j]);
                    mask -= 3;
                }
            }
            if (mask+6 == (mask|6)) {
                if (flag && buf[0][i] == 'O') {}
                else {
                    mask += 6;
                    if ((mask | state[i]) == state[i])
                        dp[i+1][mask] = add(dp[i+1][mask],dp[i][j]);
                    mask -= 6;
                }
            }
        }
    return dp[n][state[n-1]];
}
void work() {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if ('.' == buf[j][i])
                state[i] += (1<<j);
        }
    int ans = solve(0)-solve(1);
    ans %= MOD;
    ans = add(ans,MOD);
    printf("%d\n", ans);
}
void load() {
    scanf("%d", &n);
    for (int i = 0; i < m; ++i)
        scanf("%s", buf[i]);
}
int main(int argc, char const *argv[]) {
    load();
    work();
    return 0;
}
