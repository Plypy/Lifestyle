/**
 * Description: bitmask DP
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
const int SIZE = 1<<MAXN;
int a[MAXN];
int f[SIZE];
int n;
const int INF = 0x3f3f3f3f;
inline int left(int a) {
    if (a == 1)
        return n;
    return a-1;
}
inline int right(int a) {
    if (a == n)
        return 1;
    return a+1;
}
int dp(int mask) {
    if (f[mask])
        return f[mask];
    int dmg = 0;
    int ret = INF;
    for (int i = 1; i <= n; ++i) {
        int t = 1<<(i-1);
        if (!(mask&t)) {
            dmg += a[i];
        }
        int l = 1<<(left(i)-1);
        int r = 1<<(right(i)-1);
        int nMask = mask|l|t|r;
        if (nMask != mask)
            ret = min(ret,dp(nMask));

    }
    return f[mask] = ret+dmg;
}
int main() {
    cin >> n;
    int state = 0;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
        state = (state<<1)+1;
    }
    f[state] = 1;
    int ans = dp(0)-sum-1;
    cout << ans << endl;
    return 0;
}
