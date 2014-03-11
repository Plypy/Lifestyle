/**
 * Description:
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
const int MAXN = 600005;
int c[MAXN];
int n;
int lowbit(int a) {
    return a&-a;
}
void ins(int a) {
    while (a <= n) {
        ++c[a];
        a += lowbit(a);
    }
}
int sel(int k) {
    int ret = 0;
    int t = 1<<(int(log2(n)));
    for (int p = t; p; p >>= 1)
        if (ret+p<n && c[ret+p] < k)
            k -= c[ret+=p];
    return ret+1;
}
int get(int a) {
    int ret = 0;
    while (a) {
        ret += c[a];
        a -= lowbit(a);
    }
    return ret;
}
int rank(int a) {
    return get(a-1);
}

int ar[MAXN];

int l[MAXN], r[MAXN];
bool vis[MAXN];
char s[MAXN*2];
int ct;
int stk[MAXN], top;
void visit() {
    stk[top=1] = ar[1];
    while (top) {
        int u = stk[top];
        if (u&1)
            s[ct] = '1';
        else
            s[ct] = '0';
        ++ct;
        vis[u] = true;
        if (l[u] && !vis[l[u]]) {
            stk[++top] = l[u];
            continue;
        }
        if (r[u] && !vis[r[u]]) {
            stk[++top] = r[u];
            continue;
        }
        --top;
    }
}
char pat[MAXN];
void work() {
    for (int i = 1; i <= n; ++i) {
        int size = i-1;
        int lnum = rank(ar[i]);
        int rnum = size-lnum;
        if (lnum) {
            int tmp = sel(lnum);
            if (!r[tmp])
                r[tmp] = ar[i];
        }
        if (rnum) {
            int tmp = sel(lnum+1);
            if (!l[tmp])
                l[tmp] = ar[i];
        }
        ins(ar[i]);
    }
    visit();
    int ans = 0;
    char *p = s;
    while (p = strstr(p,pat)) {
        ++p;
        ++ans;
    }
    printf("%d\n", ans);
}
void load() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", ar+i);
    scanf("%s", pat);
}
void init() {
    memset(c,0,sizeof(c));
    memset(s,0,sizeof(s));
    memset(vis,0,sizeof(vis));
    memset(l,0,sizeof(l));
    memset(r,0,sizeof(r));
    ct = 0;
}
int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        init();
        load();
        printf("Case #%d: ", i);
        work();
    }
    return 0;
}
