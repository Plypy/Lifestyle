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
const int MAXN = 100005;
bool has[MAXN];
int mu[MAXN];
int minp[MAXN];
void prep() {
    for (int i = 2; i < MAXN; ++i) {
        if (!has[i]) {
            for (int j = i; j < MAXN; j += i) {
                minp[j] = i;
                has[j] = true;
            }
        }
    }
    mu[1] = 1;
    for (int i = 2; i < MAXN; ++i) {
        int d = minp[i];
        if ((i/d)%d == 0) {
            mu[i] = 0;
        } else {
            mu[i] = -mu[i/d];
        }
    }
}
typedef long long ll;
ll solve(int a, int b) {
    ll ret = 0;
    for (ll i = 1; i <= a; ++i) {
        ret += mu[i]*(a/i)*(b/i);
    }
    return ret;
}
int main(int argc, char const *argv[]) {
    int T;
    scanf("%d", &T);
    prep();
    for (int i = 1; i <= T; ++i) {
        int a, b, c, d, k;
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
        ll ans = 0;
        if (k != 0) {
            b /= k;
            d /= k;
            if (b > d)
                swap(b,d);
            ans = solve(b,d)-solve(b,b)/2;
        }
        printf("Case %d: %I64d\n", i, ans);
    }
    return 0;
}