/**
 * Description: DP bitmask
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
const int MAXN = 25;
const int SIZE = 1<<(MAXN-1);
const int INF = 1000;
int a[MAXN];
int dp[SIZE];
int n;
int bitCount(int t) {
    int ret = 0;
    while (t) {
        if (t&1)
            ++ret;
        t >>= 1;
    }
    return ret;
}
int f(int mask, int t) {
    if (dp[mask])
        return dp[mask];
    int ct = bitCount(mask);
    int ret = INF;
    int nMask = (mask&~(1<<t)|(1<<t-1)); // 令第t位为0的方法
    for (int i = 0; i < t; ++i) {
        for (int j = 0; j <= i; ++j)
            if (a[i]+a[j] == a[t]) {
                int x = 1<<i;
                int y = 1<<j;
                int tmp = f(nMask|x|y,t-1);
                ret = min(ret,max(tmp,ct));
            }
    }
    return dp[mask] = ret;
}
int main() {
    test(10);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    dp[1] = 1;
    int ans = f(1<<(n-1),n-1);
    if (INF == ans)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}
