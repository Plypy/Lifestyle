#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
LL gcd(LL a, LL b) {
    if (b)
        return gcd(b,a%b);
    return a;
}
const LL MAXN = 100005;
LL n, m;
LL a[MAXN];
void load() {
    scanf("%I64d%I64d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%I64d", a+i);
        --a[i];
    }
}
LL ans;
void get(LL t) {
    while (t <= m) {
        ans += m-t;
        t <<= 1;
    }
}
void work() {
    LL commonD = a[1];
    for (int i = 2; i <= n; ++i)
        commonD = gcd(commonD,a[i]);
    while (0 == commonD%2)
        commonD >>= 1;
    for (int i = 1; i*i <= commonD; i += 2)
        if (0 == commonD%i) {
            get(i);
            if (i*i != commonD)
                get(commonD/i);
        }
    printf("%I64d\n", ans);
}
int main() {
    load();
    work();
    return 0;
}
