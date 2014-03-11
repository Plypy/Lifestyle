#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int MAXN = 105;
int a[MAXN];
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; ++i)
            scanf("%d", a+i);
        sort(a,a+n);
        printf("%d\n", a[n-k]);
    }
    return 0;
}
