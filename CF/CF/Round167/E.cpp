#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL MAXN = 1005;
const LL MOD = 1000000007;
LL dp[MAXN][4];
LL cnt[4];
LL n, p;
void load() {
    cin >> n >> p;
}
LL mex(LL a, LL b) {
    for (LL i = 0; i < 3; ++i)
        if (a != i && b != i)
            return i;
}
LL x[MAXN], sg[MAXN];
LL sum(LL a, LL b) {
    LL l = p-b, r = p-a;
    return ((l+r)*(r-l+1)/2)%MOD;
}
void calc() {
    LL num = 1;
    x[num] = 2, sg[num] = 0;
    LL l = 1, r = 1;
    while (x[num] < p) {
        LL nl = (x[l]+1)*3-1;
        LL nr = x[r]/2*3;
        if (x[r]&1)
            ++nr;
        sg[++num] = mex(sg[l],sg[r]);
        if (sg[num] == sg[num-1])
            --num;
        x[num] = min(nl,nr);
        if (nl == x[num])
            ++l;
        if (nr == x[num])
            ++r;
    }
    if (x[num] >= p)
        x[num] = p-1;
    for (LL i = 1; i <= num; ++i)
        cnt[sg[i]] = (cnt[sg[i]] + sum(x[i-1]+1,x[i]))%MOD;
}
void work() {
    calc();
    dp[0][0] = 1;
    for (LL i = 0; i < n; ++i) {
        for (LL j = 0; j < 4; ++j) {
            for (LL k = 0; k < 4; ++k) {
                LL t = j^k;
                dp[i+1][t] = (dp[i][j]*cnt[k]+dp[i+1][t])%MOD;
            }
        }
    }
    LL ans = 0;
    for (LL i = 1; i < 4; ++i)
        ans = (dp[n][i]+ans)%MOD;
    cout << ans << endl;
}

int main() {
    load();
    work();
    return 0;
}
