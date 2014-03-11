#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int MAXN = 1000005;
const int MOD = 1000000007;
int n, m;
int f[MAXN];
void init() {
    f[1] = f[0] = 1;
    for (int i = 2; i < MAXN; ++i) {
        f[i] = (f[i-1]+f[i-2])%MOD;
    }
}
inline int lowbit(int a) {
    return a&-a;
}
int ct(int a) {
    int ret = 0;
    while (a)
        a -= lowbit(a), ++ret;
    return ret;
}
int main() {
    int t;
    scanf("%d", &t);
    init();
    for (int i = 0; i < t;++i) {
        scanf("%d%d", &n, &m);
        if (m == ct(f[n]))
            printf("CORRECT\n");
        else
            printf("INCORRECT\n");
    }
    return 0;
}
