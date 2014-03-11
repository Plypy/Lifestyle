#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
const int MAXN = 100005;
const int BOUND = 1005;
bool notp[BOUND];
int plis[BOUND];
int pnum;
inline void init() {
    for (int i = 2; i < BOUND; ++i)
        if (!notp[i]) {
            plis[++pnum] = i;
            for (int j = i*2; j < BOUND; j += i)
                notp[j] = true;
        }
}
inline int ipow(int b, int p) {
    int ret = 1;
    int mult = b;
    for (; p; p >>= 1, mult *= mult)
        if (p&1)
            ret *= mult;
    return ret;
}
int main() {
    init();
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int ans = 1;
        for (int i = 1; i <= pnum; ++i) {
            int t = 0;
            while (0 == n%plis[i]) {
                ++t;
                n /= plis[i];
            }
            t = (ipow(plis[i],t+1)-1)/(plis[i]-1);
            ans *= t;
        }
        if (n > 1)
            ans *= n+1;
        printf("%d\n", ans);
    }
    return 0;
}
