// 利用单调性 简化问题
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int MAXN = 505;
int a[MAXN], b[MAXN];
int f[MAXN], p[MAXN];
int ans[MAXN];
int n, m;
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    cin >> m;
    for (int i = 1; i <= m; ++i)
        cin >> b[i];
    int k;
    for (int i = 1; i <= n; ++i) {
        k = 0;
        for (int j = 1; j <= m; ++j) {
            if (a[i] == b[j] && f[k]+1 > f[j]) {
                f[j] = f[k]+1;
                p[j] = k;
            } else if (b[j] < a[i] && f[j] > f[k]) {
                k = j;
            }
        }
    }
    k = 0;
    for (int i = 1; i <= m; ++i)
        if (f[i] > f[k])
            k = i;
    for (int i = k; i; i = p[i])
        ans[++ans[0]] = b[i];
    cout << ans[0] << endl;
    for (int i = ans[0]; i ; --i)
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}
