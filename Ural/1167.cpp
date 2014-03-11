/**
 * Description: Simple DP
 * Author: Ply_py
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iomanip>
#include <queue>
#include <cmath>
using namespace std;
const int MAXN = 505;
const int INF  = 0x3f3f3f3f;
int sa[MAXN], sb[MAXN];
int f[MAXN][MAXN];
int n, k;
int dp(int i, int j) {
    if (f[i][j] != -1)
        return f[i][j];
    int ret = INF;

    for (int k = i-1; k >= j-1; --k) {
        int tmp = dp(k,j-1);
        tmp += (sa[i]-sa[k])*(sb[i]-sb[k]);
        ret = min(ret,tmp);
    }
    return f[i][j] = ret;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        sa[i] = sa[i-1];
        sb[i] = sb[i-1];
        if (a)
            ++sa[i];
        else
            ++sb[i];
    }
    memset(f,-1,sizeof(f));
    for (int i = 1; i <= n; ++i)
        f[i][1] = sa[i]*sb[i];
    int ans = dp(n,k);
    cout << ans << endl;
    return 0;
}
