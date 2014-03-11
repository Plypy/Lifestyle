/**
 * Description:
 * Source:
 * Author: Ply_py
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
using namespace std;

const int MAXN = 100005;

int c[MAXN];
int mn;
inline int lowbit(int a) {
    return a&(-a);
}
void modify(int a, int d) {
    while (a <= mn) {
        c[a] += d;
        a += lowbit(a);
    }

}
int get(int l) {
    int ret = 0;
    while (l) {
        ret += c[l];
        l -= lowbit(l);
    }
    return ret;
}
int query(int l, int r) {
    return get(r)-get(l-1);
}
void init() {
    memset(c,0,sizeof(c));
}
struct Query{
    int l, r;
    int id;
    bool operator<(const Query &t) const {
        return r<t.r;
    }
} qu[MAXN];
int ar[MAXN];
int pos[MAXN];
int ans[MAXN];
int n, m;
void work() {
    mn = n;
    sort(qu+1,qu+m+1);
    int j = 1;
    for (int i = 1; i <= n; ++i) {
        modify(i,1);
        if (ar[i] != 1 && pos[ar[i]-1] < i)
            modify(pos[ar[i]-1], -1);
        if (ar[i] != n && pos[ar[i]+1] < i)
            modify(pos[ar[i]+1], -1);
        while (j <= m && qu[j].r == i) {
            ans[qu[j].id] = query(qu[j].l, qu[j].r);
            ++j;
        }
    }
    for (int i = 1; i <= m; ++i) {
        printf("%d\n", ans[i]);
    }
}
void load() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", ar+i);
        pos[ar[i]] = i;
    }
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &qu[i].l, &qu[i].r);
        qu[i].id = i;
    }
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        load();
        work();
        init();
    }
}