
/**
 * Author: Ply_py
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
    return (a<<1);
}
inline int rson(int a) {
    return (a<<1)+1;
}
const int MAXN = 50005;

struct Node {
    int sum;
} tr[MAXN<<2];
int M;
void update(int a) {
    tr[a].sum = tr[lson(a)].sum+tr[rson(a)].sum;
}
void add(int a, int b) {
    a = a+M;
    tr[a].sum += b;
    for (a >>= 1; a; a >>= 1)
        update(a);
}
int query(int l, int r) {
    int ret = 0;
    for (l = l-1+M, r = r+1+M; l^r^1; l >>= 1, r >>= 1) {
        if (~l&1)
            ret += tr[l^1].sum;
        if (r&1)
            ret += tr[r^1].sum;
    }
    return ret;
}
int n;
void build() {
    for (M = 1; M <= n; M <<= 1)
        continue;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &tr[i+M].sum);
    }
    for (int i = M-1; i; --i)
        update(i);
}
int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        scanf("%d", &n);
        memset(tr,0,sizeof(tr));
        build();
        printf("Case %d:\n", i);
        while (true) {
            char s[20];
            scanf("%s", s);
            int a, b;
            if ('Q' == s[0]) {
                scanf("%d%d", &a, &b);
                printf("%d\n", query(a,b));
            } else if ('A' == s[0]) {
                scanf("%d%d", &a, &b);
                add(a,b);
            } else if ('S' == s[0]) {
                scanf("%d%d", &a, &b);
                add(a,-b);
            } else
                break;
        }
    }
    return 0;
}
