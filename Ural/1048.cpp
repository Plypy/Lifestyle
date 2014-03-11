#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int MAXN = 1000005;
int a[MAXN], b[MAXN];
int ans[MAXN];
int n;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", a+i, b+i);
    int t = 0;
    for (int i = n; i; --i) {
        ans[i] = a[i]+b[i]+t;
        if (ans[i] >= 10) {
            t = 1;
            ans[i] -= 10;
        } else
            t = 0;
    }
//    if (t)
//        putchar('1');
    for (int i = 1; i <= n; ++i)
        printf("%d", ans[i]);
//    system("pause");
    return 0;
}
