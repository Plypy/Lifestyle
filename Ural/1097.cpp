
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int MAXN = 105;
int ans;
int l, a, n;
int imp[MAXN], size[MAXN], x[MAXN], y[MAXN];
void check() {
    ans = 101;
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j) {
            int p = x[i]+size[i];
            int q = y[j]+size[j];
            if (p+a > l || q+a > l)
                continue;
            int tmp = 1;
            for (int k = 1; k <= n; ++k)
                if (imp[k] > tmp &&
                    p+a>x[k] && x[k]+size[k]>p &&
                    q+a>y[k] && y[k]+size[k]>q)
                    tmp = imp[k];
            if (ans > tmp)
                ans = tmp;
        }
}
int main() {
    scanf("%d%d%d", &l, &a, &n);
    ++l;
    for (int i = 1; i <= n; ++i)
        scanf("%d%d%d%d", imp+i, size+i, x+i, y+i);
    size[0] = 0;
    x[0] = y[0] = 1;
    
    check();
    
    if (ans > 100)
        printf("IMPOSSIBLE\n");
    else
        printf("%d\n", ans);
//    system("pause");
    return 0;
}
