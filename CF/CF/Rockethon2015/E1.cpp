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
#include <bitset>
#include <stack>
using namespace std;

const int MAXN = 405;
const int MAXK = 55;
const int INF = 0x3f3f3f3f;
int f[MAXK][MAXN][MAXN];
int g[MAXN];
int h[MAXN];
int s[MAXN];
int n, m;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        s[i] = s[i-1]+a;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            for (int k = 2; k <= m; ++k) {
                f[k][i][j] = -INF;
            }
        }
    }
    int ans = -INF;
    for (int k = 2; k <= m; ++k) {
        for (int i = 0; i <= n; ++i) {
            g[i] = h[i] = -INF;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                int tmp = s[i]-s[j-1];
                g[i] = max(g[i], f[k-1][j][i]+tmp);
                h[i] = max(h[i], f[k-1][j][i]-tmp);
            }
            for (int j = i; j <= n; ++j) {
                int tmp = s[j]-s[i-1];
                f[k][i][j] = max(g[i-1]-tmp, h[i-1]+tmp);
                if (k == m) {
                    ans = max(ans, f[k][i][j]);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
