/**
 * Description: FIND the largest sub-sequence sum of a given sequence
 * Source: SPOJ
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

const int MAXN = 50005;
const int SEGN = MAXN*4;

#define root 1,1,n
#define lx (x<<1)
#define rx (lx|1)
#define ml ((l+r)>>1)
#define mr (ml+1)
#define len (r-l+1)
#define xc x,l,r
#define lc lx,l,ml
#define rc rx,mr,r
inline int mmax(int a, int b, int c) {
    return max(a,max(b,c));
}
int ar[MAXN];
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
struct Seg {
    ll lsum, rsum, msum, all;
    Seg(ll x=0, ll y = 0):lsum(x), rsum(x), msum(x), all(y) { }
} node[SEGN];
bool slack[SEGN];

int tl, tr, tv;
void assign(int x, int l, int r, int v) {

}
void release(int x, int l, int r) {

}
void modify(int x, int l, int r) {

}

Seg merge(Seg l, Seg r) {
    Seg ret;
    ret.all = l.all+r.all;
    ret.lsum = max(l.lsum,l.all+r.lsum);
    ret.rsum = max(r.rsum,l.rsum+r.all);
    ret.msum = mmax(l.msum,r.msum,l.rsum+r.lsum);
    return ret;
}
Seg query(int x, int l, int r) {
    if (tr < l || r < tl)
        return Seg(-INF);
    if (tl <= l && r <= tr)
        return node[x];
    Seg ln(-INF), rn(-INF);
    if (tl <= ml)
        ln = query(lc);
    if (tr >= mr)
        rn = query(rc);
    return merge(ln,rn);
}
void build(int x, int l, int r) {
    slack[x] = false;
    if (l == r) {
        node[x] = Seg(ar[l],ar[l]);
    } else {
        build(lc), build(rc);
        node[x] = merge(node[lx],node[rx]);
    }
}
int n;
void work() {
    int m;
    scanf("%d", &m);
    build(root);
    while (m--) {
        scanf("%d%d", &tl, &tr);
        printf("%I64d\n", query(root).msum);
    }
}
void load() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", ar+i);
}
int main(int argc, char const *argv[]) {
    load();
    work();
    return 0;
}