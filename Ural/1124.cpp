
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int MAXM = 505;
const int MAXN = 55;
int n, m;

int fa[MAXM];
int find(int a) {
    int t = a;
    while (fa[a] > 0)
        a = fa[a];
    int b = t;
    while (b != a) {
        t = fa[b];
        fa[b] = a;
        b = t;
    }
    return a;
}

bool merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b)
        return false;
    if (fa[a] > fa[b])
        fa[a] = b;
    else {
        if (fa[a] == fa[b])
            --fa[a];
        fa[b] = a;
    }
    return true;
}

int ans;
int main() {
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j) {
            int t;
            scanf("%d", &t);
            if (t != i) {
                merge(t,i);
                ++ans;
            }
        }
    for (int i = 1; i <= m; ++i)
        if (fa[i] < 0)
            ++ans;
    --ans;
    if (ans < 0)
        ans = 0;
    printf("%d\n", ans);
//    system("pause");
    return 0;
}
