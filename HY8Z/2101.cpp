#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int MAXN = 5010;
int a[MAXN];
int s[MAXN];
int f[MAXN][2];
int n;
void load() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a+i);
        s[i] = s[i-1]+a[i];
        f[i][1] = a[i];
    }
}
inline int max(int a, int b) {
    return a>b?a:b;
}
void work() {
    int u, v;
    int tot;
    for (int p = 2; p <= n; ++p) {
        u = (p-1)&1;
        v = p&1;
        for (int i = 1; i+p-1 <= n; ++i) {
            tot = s[i+p-1]-s[i-1];
            f[i][v] = max(tot-f[i+1][u],tot-f[i][u]);
        }
//        for (int i = 1; i+p-1 <= n; ++i)
//            cout << f[i][v] << ' ';
//        cout << endl;
    }
    cout << f[1][n&1] << endl;
//    system("pause");
}
int main() {
    load();
    work();
    return 0;
}
