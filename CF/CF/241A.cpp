#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int MAXN = 1005;
int n, k;
int d[MAXN];
int s[MAXN];
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", d+i);
    for (int i = 1; i <= n; ++i)
        scanf("%d", s+i);
    int ans = 0;
    int res = 0;
    int ma = 0;
    for (int i = 1; i <= n; ++i) {
        res += s[i];
        if (ma < s[i])
            ma = s[i];
        while (res < d[i]) {
            res += ma;
            ans += k;
        }
        ans += d[i];
        res -= d[i];
    }
    printf("%d\n", ans);
    return 0;
}
