/**
 * Description: Note, corner case and initialization are especially important
 *     in DP
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

const int MAXN = 30005;
const int MAXK = 205;
const int INF = 0x3f3f3f3f;

int f[MAXN][MAXK][2][2];
int g[MAXN][MAXK][2][2];
int a[MAXN];
int n, m;

int sign[2] = {1, -1};

inline void check(int &a, int b)
{
    if (a < b) {
        a = b;
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int k = 0; k <= m; ++k) {
        for (int i = 0; i <= n; ++i) {
            for (int p = 0; p <= 1; ++p) {
                for (int q = 0; q <= 1; ++q) {
                    f[i][k][p][q] = -INF;
                    g[i][k][p][q] = -INF;
                }
            }
        }
    }

    f[0][1][0][0] = f[0][1][1][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int p = 0; p <= 1; ++p) {
            f[i][1][p][0] = max(f[i-1][1][p][0]+a[i], a[i]);
            f[i][1][p][1] = max(f[i-1][1][p][1]-a[i], -a[i]);
        }
    }

    int ans = -INF;
    for (int k = 2; k <= m; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int p = 0; p <= 1; ++p) {
                for (int q = 0; q <= 1; ++q) {

                    int x = -a[i], y = a[i];
                    if (m == k) {
                        y = 0;
                    }

                    int addon = sign[p]*x+sign[q]*y;
                    int &tmp = f[i][k][p][q];
                    tmp = max(f[i-1][k][p][q], g[i-1][k][p][q]+addon);
                    // cout << i << ' ' << k << ' ' << p << ' ' << q << ' ' << tmp << " f" << endl;

                    if (m == k) {
                        check(ans, tmp);
                    }

                    int &tm = g[i][k][p][q];
                    tm = max(f[i][k-1][0][p], f[i][k-1][1][p]);
                    // cout << i << ' ' << k << ' ' << p << ' ' << q << ' ' << tm << " g" << endl;
                    tm = max(tm, g[i-1][k][p][q] + addon);
                    // cout << i << ' ' << k << ' ' << p << ' ' << q << ' ' << tm << " g" << endl;

                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
