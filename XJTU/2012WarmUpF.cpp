#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 55;
int a[MAXN];
int n;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a+i);
    sort(a+1,a+n+1);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int tmp = a[i]*(n-i+1);
        if (tmp > ans)
            ans = tmp;
    }
    printf("%d\n", ans);
    return 0;
}
