#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
const int MAXN = 1000005;
typedef long long LL;
char sb[MAXN], sn[MAXN];
LL c;
void load() {
    scanf("%s%s%I64d", sb, sn, &c);
}
LL euler_phi(LL a) {
    LL bd = LL(sqrt(a+0.5));
    LL ret = a;
    for (int i = 2; i <= bd; ++i) {
        if (0 == a%i) {
            while (0 == a%i)
                a /= i;
            ret = ret/i*(i-1);
        }
    }
    if (a > 1)
        ret = ret/a*(a-1);
    return ret;
}
LL mod(char ts[], LL m) {
    LL ret = 0;
    int len = strlen(ts);
    for (int i = 0; i < len; ++i) {
        ret = (ret*10+ts[i]-'0')%m;
    }
    return ret;
}
LL pow(LL base, LL p, LL m) {
    int ret = 1%m;
    LL tmp = base%m;
    for (; p; p>>=1) {
        if (p&1)
            ret = (ret*tmp)%m;
        tmp = (tmp*tmp)%m;
    }
    return ret;
}
void work() {
    LL b = mod(sb,c);
    LL ans;
    if (strlen(sn) <= 9) {
        LL n;
        sscanf(sn,"%I64d", &n);
        ans = (b-1)*pow(b,n-1,c)%c;
    } else {
        LL phi = euler_phi(c);
        LL delta = (30+phi-1)/phi * phi;
        ans = (b-1)*pow(b,(mod(sn,phi)+phi-1)%phi+delta,c)%c;
    }
    if (0 >= ans)
        ans += c;
    printf("%I64d\n", ans);
}
int main() {
    load();
    work();
    return 0;
}

