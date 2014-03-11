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
typedef long long ll;
const ll MOD = 1000000007;
ll mabs(ll a) {
    return (a+MOD)%MOD;
}
ll add(ll a, ll b) {
    return mabs((a+b)%MOD);
}
ll mult(ll a, ll b) {
    return mabs((a*b)%MOD);
}
ll powmod(ll a, ll b) {
    if (b == 0)
        return 1;
    ll ret = 1;
    ll tmp = powmod(a,b/2);
    ret = mult(tmp,tmp);
    if (b&1)
        ret = mult(ret,a);
    return ret;
}
ll inv(ll a) {
    if (1 == a)
        return 1;
    return mult(-(MOD/a),inv(MOD%a));
}

const ll MAXN = 300005;
int n, m, k;
ll fac[MAXN], rfac[MAXN];
ll comb(ll a, ll b) {
    return mult(fac[a],mult(rfac[a-b],rfac[b]));
}

void prep() {
    fac[0] = rfac[0] = 1;
    ll mn = 300000;
    for (ll i = 1; i <= mn; ++i) {
        fac[i] = mult(fac[i-1],i);
    }
    rfac[mn] = inv(fac[mn]);
    for (ll i = mn-1; i; --i) {
        rfac[i] = mult(i+1,rfac[i+1]);
    }
}
int cnt[MAXN], a[MAXN];
int ans[MAXN];
void work() {
    memset(cnt,0,sizeof(cnt));
    for (ll i = 1; i <= n; ++i) {
        ++cnt[a[i]];
    }
    for (ll d = 1; d <= m; ++d) {
        ll x = 0;
        for (ll i = d; i <= m; i += d)
            x += cnt[i];
        x = n-x;
        if (x > k)
            ans[d] = 0;
        else {
            ans[d] = mult(powmod(m/d, x),powmod(m/d-1, k-x));
            ans[d] = mult(ans[d],comb(n-x,k-x));
        }
    }
    for (ll i = m; i; --i) {
        for (ll j = i+i; j <= m; j += i)
            ans[i] = add(ans[i],-ans[j]);
    }
    for (ll i = 1; i <= m; ++i) {
        printf("%d", ans[i]);
        if (i == m)
            puts("");
        else
            putchar(' ');
    }
}
bool load() {
    if (EOF == scanf("%d%d%d", &n, &m, &k))
        return false;
    for (ll i = 1; i <= n; ++i)
        scanf("%d", a+i);
    return true;
}
int main() {
    prep();
    while (load()) {
        work();
    }
    return 0;
}