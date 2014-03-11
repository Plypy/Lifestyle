#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 19;
typedef long long ll;
ll dp[1<<MAXN][MAXN];
ll ans;
bool g[MAXN][MAXN];
int n, m;
void load() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        g[x][y] = g[y][x] = true;
    }
}
void work() {
    for (int i = 0; i < n; ++i)
        dp[1<<i][i] = 1;
    int bd = 1<<n;
    for (int i = 1; i < bd; ++i) {
        int s = __builtin_ctz(i);
        for (int j = s; j < n; ++j) {
            if (dp[i][j]) {
                if (g[j][s]) {
                    ans += dp[i][j];
                }
                for (int k = s+1; k < n; ++k)
                    if ( ((1<<k)&(~i)) && g[j][k])
                        dp[i|(1<<k)][k] += dp[i][j];
            }
        }
    }
    ans = (ans-m)>>1;
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    load();
    work();
    return 0;
}

