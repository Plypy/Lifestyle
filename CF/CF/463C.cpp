/**
 * Description: Simple Greedy
 * ProblemName:
 * Source: Codeforces
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

typedef long long ll;

const int MAXN = 2005;
int n;
int f[MAXN][MAXN];
ll sum[MAXN][MAXN];

ll rct(int r, int c, ll ct) {
    ct += f[r][c];
    ll ret = 0;
    if (r == n || c == n) {
        ret = ct;
    } else {
        ret = rct(r+1,c+1,ct);
    }
    sum[r][c] += ret;
    return ret;
}
ll lct(int r, int c, ll ct) {
    ct += f[r][c];
    ll ret = 0;
    if (r == 1 || c == n) {
        ret = ct;
    } else {
        ret = lct(r-1, c+1, ct);
    }
    sum[r][c] += ret;
    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &f[i][j]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        rct(i,1,0);
        if (i != 1) {
            rct(1,i,0);
        }
    }
    for (int i = n, j = 1; i; --i, ++j) {
        lct(i,1,0);
        if (i != n) {
            lct(n,j,0);
        }
    }

    ll ans[2] = {-1, -1};
    int x[2], y[2];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            sum[i][j] -= f[i][j];
            int t = (i+j)&1;
            ll tmp = sum[i][j];
            if (tmp > ans[t]) {
                ans[t] = tmp;
                x[t] = i, y[t] = j;
            }
        }
    }
    cout << ans[0]+ans[1] << endl;
    cout << x[0] << ' ' << y[0] << ' ' << x[1] << ' ' << y[1] << endl;
}
