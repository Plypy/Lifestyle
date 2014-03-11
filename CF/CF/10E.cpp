#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = 405;
int a[MAXN];
int n;
int ans = -1;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a+i);
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; ++j) {
            int s = a[i]-1;
            int t = 1;
            int m = a[j];
            for (int k = i+1; k <= j; ++k) {
                t += s/a[k];
                m += s/a[k]*a[k];;
                s %= a[k];
            }
            int p = m;
            for (int k = 1; k <= n; ++k) {
                t -= p/a[k];
                p %= a[k];
            }
            if (t < 0 && (-1 == ans || m < ans))
                ans = m;
        }
    printf("%d\n", ans);
    return 0;
}
