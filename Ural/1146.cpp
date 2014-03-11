#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;
const int Maxn = 101;
const int Inf = INT_MAX;
int sum[Maxn][Maxn];
int f[Maxn];

int n;
void load() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            int a;
            scanf("%d", &a);
            if (1 == i)
                sum[i][j] = a;
            else
                sum[i][j] = sum[i-1][j]+a;
        }
}

void work() {
    int ans = -Inf;
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                int a = sum[j][k]-sum[i-1][k];
                f[k] = max(f[k-1]+a,a);
                ans = max(ans,f[k]);
            }
        }
    printf("%d\n", ans);
//    system("pause");
}
    
int main() {
    load();
    work();
    return 0;
}
