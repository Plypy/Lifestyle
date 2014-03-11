// Rmq问题，我就练习zkw线段树吧 
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int MAXN = 100005;
const int INF = 52111425;
int tree[MAXN*2];
int n, m;
inline int min(int a, int b) {
    return a<b?a:b;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", tree+i+n);
    for (int i = n-1; i; --i)
        tree[i] = min(tree[i<<1],tree[(i<<1)+1]);
    int l, r;
    while (m--) {
        scanf("%d%d", &l, &r);
        int lpart = INF;
        int rpart = INF;
        int ans;
        for (l += n-1, r += n+1; l^r^1; l >>= 1, r >>= 1) {
            if (~l&1)
                lpart = min(lpart,tree[l+1]);
            if (r&1)
                rpart = min(tree[r-1],rpart);
        }
        ans = min(lpart,rpart);
        printf("%d\n", ans);
    }
    return 0;
}
