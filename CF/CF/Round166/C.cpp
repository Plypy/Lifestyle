#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = 1000005;
int n, k;
int keeper[MAXN];
int main() {
    scanf("%d%d", &n, &k);
    if (n / 3 < k) {
        printf("-1\n");
        return 0;
    }
    int ct = 0;
    for (int i = 1; i <= n; ++i) {
        int t = i%k;
        if (ct == 1)
            t = (t+1)%k;
        if (t <= 0)
            t += k;
        keeper[i] = t;
        if (i % k == 0)
            ++ct;
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d", keeper[i]);
        if (i == n)
            puts("");
        else
            putchar(' ');
    }
    return 0;
}
