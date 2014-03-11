#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int y, k, n;
int main() {
    scanf("%d%d%d", &y, &k, &n);
    n = n-y;
    int r = y%k;
    int ans = (n+r)/k;
    if (ans > 0) {
        int i = k-r;
        if (!i)
            i += k;
        printf("%d", i);
        i += k;
        for (; i <= n; i += k)
            printf(" %d", i);
        puts("");

    } else {
        printf("-1\n");
    }
    return 0;
}
