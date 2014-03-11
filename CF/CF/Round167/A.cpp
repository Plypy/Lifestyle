#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 100005;
LL ht[MAXN];
LL n, a[MAXN];
LL m;
LL lowbit(LL a) {
    return a&-a;
}
void add(LL a, LL b) {
    LL t = ht[a] = b;
    while (a <= n) {
        ht[a] = max(ht[a],t);
        a += lowbit(a);
    }
}
LL get(LL a) {
    LL ret = 0;
    while (a) {
        ret = max(ret,ht[a]);
        a -= lowbit(a);
    }
    return ret;
}
void load() {
    scanf("%I64d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%I64d", a+i);
        add(i,a[i]);
    }
}
void work() {
    scanf("%I64d", &m);
    for (int i = 1; i <= m; ++i) {
        int th, tw;
        scanf("%d%d", &tw, &th);
        LL bot = get(tw);
        printf("%I64d\n", bot);
        add(1,bot+th);
    }
}
int main() {
    load();
    work();
    return 0;
}
