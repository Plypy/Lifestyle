#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int MODULO = 2011;
const int MAXN = 25;
int a[MAXN][MAXN], b[MAXN][MAXN];
int c[MAXN][MAXN];
int n, m;
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j) {
                scanf("%d", &a[i][j]);
                a[i][j] = (a[i][j]+MODULO)%MODULO;
                b[i][j] = a[i][j];
            }
        while (m-- > 1) {
            memset(c,0,sizeof(c));
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j)
                    for (int k = 1; k <= n; ++k) {
                        c[i][j] = (c[i][j]+a[i][k]*b[k][j])%MODULO;
                    }
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j)
                    a[i][j] = c[i][j];
        }
        
        for (int i = 1; i <= n; ++i) {
            printf("%d", a[i][1]);
            for (int j = 2; j <= n; ++j)
                printf(" %d", a[i][j]);
            putchar('\n');
        }
        if (t)
            putchar('\n');
    }
    return 0;
}
