/**
 * Author: Ply_py
 * RMQ problems with modification of one point
 * Using zkw SegTree
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iomanip>
#include <queue>
#include <cmath>
using namespace std;

inline int lson(int a) {
    return a<<1;
}
inline int rson(int a) {
    return (a<<1)+1;
}
const int MAXN = 200005;
int M;
struct Node {
    int m;
} tr[MAXN<<2];

int query(int l, int r) {
    int ret = 0;
    for (l = l-1+M, r = r+1+M; l^r^1; l >>= 1, r >>= 1) {
        if (~l&1)
            ret = max(ret,tr[l^1].m);
        if (r&1)
            ret = max(ret,tr[r^1].m);
    }
    return ret;
}
void update(int a) {
    tr[a].m = max(tr[lson(a)].m,tr[rson(a)].m);
}
void modify(int a, int b) {
    tr[a+=M].m = b;
    for (a >>= 1; a; a >>= 1)
        update(a);
}
int n, m;
void build() {
    for (M = 1; M <= n; M <<= 1)
        continue;
    for (int i = 1; i <= n; ++i)
        scanf("%d", &tr[i+M].m);
    for (int i = M-1; i; --i)
        update(i);
}

int main() {
    while (EOF != scanf("%d%d", &n, &m)) {
        build();
        for (int i = 1; i <= m; ++i) {
            char s[5];
            scanf("%s", s);
            int a, b;
            if ('Q' == s[0]) {
                scanf("%d%d", &a, &b);
                printf("%d\n", query(a,b));
            } else {
                scanf("%d%d", &a, &b);
                modify(a,b);
            }
        }
    }
    return 0;
}

