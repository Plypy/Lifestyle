/**
 * Pure range sum problems
 * Using Tarray
 * Author: Ply_py
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

const int MAXN = 50005;
int c[MAXN], a[MAXN], n;
inline int lowbit(int a) {
    return a&-a;
}
void add(int a, int b) {
    while (a <= n) {
        c[a] += b;
        a += lowbit(a);
    }
}
int get(int a) {
    int ret = 0;
    while (a) {
        ret += c[a];
        a -= lowbit(a);
    }
    return ret;
}
int query(int l, int r) {
    return get(r)-get(l-1);
}
int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        scanf("%d", &n);
        memset(c,0,sizeof(c));
        for (int j = 1; j <= n; ++j) {
            scanf("%d", a+j);
            a[j] += a[j-1];
        }
        for (int j = 1; j <= n; ++j) {
            c[j] = a[j]-a[j-lowbit(j)];
        }
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
