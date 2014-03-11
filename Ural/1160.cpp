#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 1005;
const int MAXM = 15005;

struct Edge {
    int u, v, l;
    bool operator<(const Edge &b) const {
        return l<b.l;
    }
} e[MAXM];
int n, m;
int fa[MAXN];
int find(int a) {
    int tmp = a;
    while (fa[tmp] > 0)
        tmp = fa[tmp];
    int c;
    while (fa[a] > 0) {
        c = fa[a];
        fa[a] = tmp;
        a = c;
    }
    return tmp;
}
bool merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b)
        return false;
    if (fa[a] > fa[b]) {
        fa[a] = b;
    } else {
        if (fa[a] == fa[b])
            --fa[a];
        fa[b] = a;
    }
    return true;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].l);
    sort(e+1,e+1+m);
    int part = n;
    int ans1 = 0, ans2 = 0;
    for (int i = 1; i <= m; ++i) {
        if (merge(e[i].u, e[i].v)) {
            --part;
            if (1 == part) {
                ans1 = e[i].l;
                ans2 = i;
                break;
            }
        }
    }
    printf("%d\n%d\n", ans1, ans2);
    for (int i = ans2; i ; --i)
        printf("%d %d\n", e[i].u, e[i].v);
}
