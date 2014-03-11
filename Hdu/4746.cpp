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

const int MAXN = 500005;
const int MAXD = 19;
bool has[MAXN];
int minp[MAXN];
int mu[MAXN];
int luck[MAXN];
int coef[MAXD][MAXN];
void prep() {
    for (int i = 2; i < MAXN; ++i) {
        if (!has[i]) {
            for (int j = i; j < MAXN; j += i) {
                has[j] = true;
                minp[j] = i;
            }
        }
    }
    mu[1] = 1;
    luck[1] = 0;
    for (int i = 2; i < MAXN; ++i) {
        int d = minp[i];
        if ((i/d)%d == 0)
            mu[i] = 0;
        else
            mu[i] = -mu[i/d];
        luck[i] = luck[i/d]+1;
    }
    for (int i = 1; i < MAXN; ++i)
        for (int j = i; j < MAXN; j += i)
            coef[luck[i]][j] += mu[j/i];
    for (int i = 1; i < MAXD; ++i)
        for (int j = 1; j < MAXN; ++j)
            coef[i][j] += coef[i-1][j];
    for (int j = 1; j < MAXN; ++j)
        for (int i = 0; i < MAXD; ++i)
            coef[i][j] += coef[i][j-1];
}
typedef long long ll;
int main(int argc, char const *argv[]) {
    prep();
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        ll ans = 0;
        if (k > 18) {
            ans = (ll)n*m;
        } else {
            int i = 1;
            while (i <= n && i <= m) {
                int a = n/i, b = m/i;
                int j = min(n/a,m/b);
                ans += (ll)a*b*(coef[k][j]-coef[k][i-1]);
                i = j+1;
            }
        }
        printf("%I64d\n", ans);
    }
    return 0;
}