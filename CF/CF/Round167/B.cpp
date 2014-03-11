
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
const LL MAXN = 100010;

LL a[MAXN];
LL b[MAXN];
LL n, m;
const LL HASH_NUM = 1000007;
LL ct[HASH_NUM];
const LL SHIFT = 7;
LL hash[HASH_NUM];
LL fact[MAXN];
LL same[HASH_NUM];
LL p2[MAXN];
LL get(LL t) {
    LL pos = t%HASH_NUM;
    while (hash[pos] && hash[pos] != t) {
        pos = (pos+SHIFT) % HASH_NUM;
    }
    hash[pos] = t;
    return pos;
}
void load() {
    scanf("%I64d", &n);
    for (LL i = 1; i <= n; ++i)
        scanf("%I64d", a+i);
    for (LL i = 1; i <= n; ++i)
        scanf("%I64d", b+i);
    scanf("%I64d", &m);
}
LL eval(LL a, LL b) {
    LL ret = 1%m;
    for (int i = 2; i <= a; ++i) {
        LL t = i;
        while (0 == t%2 && b) {
            t >>= 1;
            --b;
        }
        ret = ret*t%m;
    }
    return ret;
}
void work() {
    for (LL i = 1; i <= n; ++i) {
        LL tmp = get(a[i]);
        ++ct[tmp];
        tmp = get(b[i]);
        ++ct[tmp];
        if (b[i] == a[i])
            ++same[tmp];
    }
    LL ans = 1;
    for (LL i = 0; i < HASH_NUM; ++i) {
        ans = ans*eval(ct[i],same[i])%m;
    }
    printf("%I64d\n", ans);
}
int main() {
    load();
    work();
    return 0;
}
