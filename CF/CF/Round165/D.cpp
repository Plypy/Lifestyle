#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int MAXN = 5005;
int a[MAXN];
int f[MAXN];
int ans = 0;
int get(int t) {
    int l = 0, r = ans+1;
    while (l+1 < r) {
        int mid = (l+r)/2;
        if (f[mid] <= t)
            l = mid;
        else
            r = mid;
    }
    return l;
}
int n, m;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        double t;
        scanf("%d%lf", a+i, &t);
    }
    for (int i = 1; i <= n; ++i) {
        int tmp = get(a[i]);
        f[tmp+1] = a[i];
        if (ans < tmp+1)
            ans = tmp+1;
    }
    ans = n-ans;
    printf("%d\n", ans);
    return 0;
}
