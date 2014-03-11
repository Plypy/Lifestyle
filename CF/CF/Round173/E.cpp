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
using namespace std;
typedef long long LL;
const int MAXN = 100005;
const int MAXDEP = 50;
LL n;
LL a[MAXN];
LL pre[MAXN], suf[MAXN];

struct Node {
    int l, r;
} node[MAXDEP*MAXN*2];
int root;
int ct = 0;
int getNode() {
    return ++ct;
}
void init() {
    root = getNode();
}
LL lson(LL a) {
    return 2*a;
}
LL rson(LL a) {
    return 2*a+1;
}
void add(LL a) {
    int pos = root;
    for (int i = MAXDEP; i >= 0; --i) {
        LL t = a&(1LL<<i);
        if (t) {
            if (!node[pos].r)
                node[pos].r = getNode();
            pos = node[pos].r;
        } else {
            if (!node[pos].l)
                node[pos].l = getNode();
            pos = node[pos].l;
        }
    }
}
LL cal(LL a) {
    LL pos = root;
    LL ret = 0;
    for (int i = MAXDEP; i >= 0; --i) {
        LL t = a&(1LL<<i);
        if (t && node[pos].l) {
            ret = rson(ret);
            pos = node[pos].l;
        } else if (!t && node[pos].r) {
            ret = rson(ret);
            pos = node[pos].r;
        } else {
            ret = lson(ret);
            if (node[pos].l)
                pos = node[pos].l;
            else
                pos = node[pos].r;
        }
    }
    return ret;
}
int main() {
    init();
    cin >> n;
    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[i] = pre[i-1]^a[i];
        ans = max(ans,pre[i]);
    }
    for (int i = n; i; --i) {
        suf[i] = suf[i+1]^a[i];
        ans = max(ans,suf[i]);
    }
    for (int i = 1; i <= n; ++i) {
        ans = max(ans,cal(suf[i]));
        add(pre[i]);
    }
    cout << ans << endl;
    return 0;
}
