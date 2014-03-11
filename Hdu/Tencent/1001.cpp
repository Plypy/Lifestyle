#include <iostream>
#include <cstdio>
#include <climits>
#include <cstring>
using namespace std;
const int MAXN = 500;
int pre[MAXN][MAXN];
int n, m;

bool load() {
    memset(pre,0,sizeof(pre));
    scanf("%d%d", &n, &m);
    if (n == 0 || m == 0)
        return false;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", &pre[i][j]);
    return true;
}
void work() {
    int ans = INT_MIN;
    int ansx = 0, ansy = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int t  = pre[i][j];
            int sum = 0;
            int mult = 1;
            if (t > 0)
                mult = -1;
            if (t == 0)
                mult = 0;
            sum += pre[i-1][j];
            sum += pre[i+1][j];
            sum += pre[i][j-1];
            sum += pre[i][j+1];
            sum *= mult;
            if (sum > ans) {
                ans = sum;
                ansx = i, ansy = j;
            }
        }
    }
    printf("%d %d %d\n", ansx, ansy, ans);
}
int main() {
    while (load()) {
        work();
    }
    return 0;
}
