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

const int MAXN = 5005;
typedef long long ll;
ll n, m, k;
ll p[MAXN];
ll sum[MAXN];
ll tsum[MAXN];
void init() {
    for (ll i = 1; i <= n; ++i) {
        sum[i] = sum[i-1]+p[i];
    }
    for (ll i = m; i <= n; ++i) {
        tsum[i] = sum[i]-sum[i-m];
    }
}
ll f[MAXN][MAXN];
int main() {
    cin >> n >> m >> k;
    for (ll i = 1; i <= n; ++i) {
        cin >> p[i];
    }
    init();
    for (ll i = m; i <= n; ++i) {
        ll bd = min(i/m, k);
        for (ll j = 0; j<=bd; ++j) {
            f[i][j] = max(f[i-1][j], f[i][j]);
            if (j > 0) {
                ll t = f[i-m][j-1]+tsum[i];
                f[i][j] = max(f[i][j], t);
            }
        }
    }
    cout << f[n][k] << endl;
}
