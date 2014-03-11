#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 10005;
const int MAXM = 100005;

struct Edge {
    int u, v;
    int len;
    friend bool operator<(const Edge &a, const Edge &b) {
        return a.len < b.len;
    }
} e[MAXM];
int n, m;
void load() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].len);
}
int f[MAXN];
inline int find(const int u) {
    int a = u;
    while (f[a] > 0)
        a = f[a];
    int b = u;
    int c;
    while (b != a) {
        c = f[b];
        f[b] = a;
        b = c;
    }
    return a;
}
bool merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b)
        return false;
    if (f[a] > f[b])
        f[a] = b;
    else {
        if (f[a] == f[b])
            --f[a];
        f[b] = a;
    }
    return true;
}
void work() {
    unsigned long long ans = 0;
    sort(e+1,e+m+1);
    for (int i = 1; i <= m; ++i)
        if (merge(e[i].u, e[i].v))
            ans += e[i].len;
    printf("%llu\n", ans);
//    system("pause");
}
    
int main() {
    load();
    work();
    return 0;
}
