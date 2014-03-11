/**
 * Description: 2011 ChengDu Regional Online Contest
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

const int MAXN = 20005;

int c[MAXN];
int n, q, t;
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
struct Atk {
    int l, r;
} atk[MAXN];
int suc[MAXN], last[MAXN];
int cnt = 0;
int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        scanf("%d%d%d", &n, &q, &t);
        cnt = 0;
        memset(c,0,sizeof(c));
        memset(suc,0,sizeof(suc));
        memset(last,0,sizeof(last));
        printf("Case %d:\n", i);
        while (q--) {
            char s[20];
            scanf("%s", s);
            if ('A' == s[0]) {
                int a, b;
                scanf("%d%d", &a, &b);
                atk[++cnt].l = a;
                atk[cnt].r = b;
                add(a,1);
                add(b+1,-1);
            } else {
                int a;
                scanf("%d", &a);
                for (int j = last[a]; j <= cnt;) {
                    if (a >= atk[j].l && a <= atk[j].r) {
                        ++suc[a];
                        last[a] = j+t;
                        j += t;
                    } else
                        ++j;
                }
                printf("%d\n", get(a)-suc[a]);
            }
        }
    }
    return 0;
}
