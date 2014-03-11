/**
 * Description:
 * Source:
 * Author: Ply_py
 */
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
// #define MAXN 222222
// #define MAXP 1111111
// #define BSIZE 500
const int MAXN = 222222;
const int MAXP = 1111111;
const int BSIZE = 500;
typedef long long ll;

struct Query {
    int l, r, d;
    int p;
    Query(int a = 0, int b = 0, int c = 0, int e = 0): l(a), r(b), d(c), p(e) {}
};
inline bool cmp(const Query &a, const Query &b) {
    if (a.p != b.p)
        return a.p<b.p;
    return a.r<b.r;
}
int ar[MAXN];
int cnt[MAXP];
ll ans[MAXN], sum;
int n, m, l, r;
Query query[MAXN];
inline void add(int pos) {
    sum += (ll)ar[pos]*(cnt[ar[pos]]*2+1);
    ++cnt[ar[pos]];
}
inline void del(int pos) {
    sum -= (ll)ar[pos]*(cnt[ar[pos]]*2-1);
    --cnt[ar[pos]];
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%d", ar+i);
    for (int i = 0, x, y; i < m; ++i) {
        scanf("%d%d", &x, &y);
        query[i] = Query(x-1,y,i,x/BSIZE);
    }
    sort(query,query+m,cmp);
    for (int i = 0; i < m; ++i) {
        Query t = query[i];
        while (l>t.l)
            add(--l);
        while (l<t.l)
            del(l++);
        while (r<t.r)
            add(r++);
        while (r>t.r)
            del(--r);
        ans[t.d] = sum;
    }
    for (int i = 0; i < m; ++i) {
        printf("%I64d\n", ans[i]);
    }
    return 0;
}