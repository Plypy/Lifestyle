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

const int MAXN = 200005;
typedef long long ll;
int mex[MAXN];
int n;
int ar[MAXN];
bool used[MAXN];
int nxt[MAXN];
int fst[MAXN];

const int SEGN = MAXN*4;
ll sum[SEGN];
ll val[SEGN];
bool slack[SEGN];
int tl, tr, tv;

#define root 1,1,n
#define lx (x<<1)
#define rx (lx|1)
#define ml ((l+r)>>1)
#define mr (ml+1)
#define len (r-l+1)
#define xc x,l,r
#define lc lx,l,ml
#define rc rx,mr,r
inline void read(int &a) {
    a = 0;
    char ch;
    while (0 == isdigit(ch = getchar()))
        continue;
    do {
        a = a*10+(ch-'0');
        ch = getchar();
    } while (isdigit(ch));
}
inline void assign(int x, int l, int r, int v) {
    val[x] = v;
    sum[x] = (ll)len*v;
    slack[x] = true;
}
void release(int x, int l, int r) {
    if (slack[x]) {
        assign(lc, val[x]), assign(rc,val[x]);
        slack[x] = false;
    }
}
void update(int x) {
    val[x] = max(val[lx],val[rx]);
    sum[x] = sum[lx]+sum[rx];
}
void modify(int x, int l, int r) {
    if (tr < l || r < tl)
        return;
    if (tl <= l && r <= tr) {
        assign(xc,tv);
    } else {
        release(xc);
        modify(lc), modify(rc);
        update(x);
    }
}
int upper_bound(int x, int l, int r) {
    if (l == r)
        return l;
    else {
        release(xc);
        return val[lx]>tv?upper_bound(lc):upper_bound(rc);
    }
}
void build(int x, int l, int r) {
    slack[x] = false;
    if (l == r) {
        val[x] = sum[x] = mex[l];
    } else {
        build(lc), build(rc);
        update(x);
    }
}
void clear() {
    memset(used,0,sizeof(used));
    memset(fst,0,sizeof(fst));
}
void work() {
    int tmex = 0;
    for (int i = 1; i <= n; ++i) {
        used[ar[i]] = true;
        while (used[tmex]) {
            ++tmex;
        }
        mex[i] = tmex;
    }
    for (int i = n; i; --i) {
        if (fst[ar[i]]) {
            nxt[i] = fst[ar[i]];
        } else {
            nxt[i] = n+1;
        }
        fst[ar[i]] = i;
    }
    ll ans = 0;
    build(root);
    for (int i = 1; i <= n; ++i) {
        ans += sum[1];
        if (val[1] > ar[i]) {
            tv = ar[i], tl = upper_bound(root), tr = nxt[i]-1;
            if (tl <= tr)
                modify(root);
        }
        tl = tr = i, tv = 0, modify(root);
        if (0 == val[1])
            break;
    }
    printf("%I64d\n", ans);
}
bool load() {
    read(n);
    if (0 == n)
        return false;
    for (int i = 1; i <= n; ++i) {
        read(ar[i]);
        ar[i] = min(ar[i],n);
    }
    return true;
}
int main(int argc, char const *argv[]) {
    while (load()) {
        work();
        clear();
    }
    return 0;
}