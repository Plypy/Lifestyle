//用到了些求和的技巧，具体看167的报告
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int MOD = 1000000007;
const int MAXN = 155;
int n, m;
int f[MAXN][MAXN][2][2];
void add(int &a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int l = 1; l <= m; ++l)
        for (int r = l; r <= m; ++r)
            f[l][r][1][1] = 1;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        long long tmp = 0;
        for (int l = 1; l <= m; ++l)
            for (int r = l; r <= m; ++r)
                for (int sl = 0; sl < 2; ++sl)
                    for (int sr = 0; sr < 2; ++sr)
                        tmp += f[l][r][sl][sr];
        ans = (ans+tmp*(n-i+1)) % MOD;

        for (int l = 1; l <= m; ++l)
            for (int r = l+1; r <= m; ++r)
                for (int sr = 0; sr < 2; ++sr) {
                    add(f[l+1][r][0][sr],f[l][r][0][sr]);
                    add(f[l+1][r][0][sr],f[l][r][1][sr]);
                }

        for (int l = 1; l <= m; ++l)
            for (int r = m; r >= l+1; --r)
                for (int sl = 0; sl < 2; ++sl) {
                    add(f[l][r-1][sl][0],f[l][r][sl][0]);
                    add(f[l][r-1][sl][0],f[l][r][sl][1]);
                }

        for (int l = m; l >= 2; --l)
            for (int r = l; r <= m; ++r)
                for (int sr = 0; sr < 2; ++sr)
                    add(f[l-1][r][1][sr],f[l][r][1][sr]);

        for (int l = m; l >= 1; --l)
            for (int r = l; r < m; ++r)
                for (int sl = 0; sl < 2; ++sl)
                    add(f[l][r+1][sl][1],f[l][r][sl][1]);
    }
    cout << ans << endl;
    return 0;
}
