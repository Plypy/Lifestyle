#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 100000*2+5;
const int SZ = MAXN*4;

struct Node {
    ll lval, rval, mval;
    Node(ll a=0, ll b=0, ll c=0): lval(a), rval(b), mval(c) {}
} tree[SZ];

ll d[MAXN];
ll h[MAXN];

Node combine(Node lson, Node rson)
{
    Node ret;
    ret.lval = max(lson.lval, rson.lval);
    ret.rval = max(lson.rval, rson.rval);
    ret.mval = max(max(lson.mval, rson.mval), lson.lval+rson.rval);
    return ret;
}

void build(int l, int r, int rt)
{
    if (l >= r) {
        tree[rt] = Node(h[l]-d[l-1], h[l]+d[l-1], 0);
        return;
    }
    int m = (l+r)>>1;
    int lson = rt<<1;
    int rson = lson+1;
    build(l,m,lson);
    build(m+1,r,rson);
    tree[rt] = combine(tree[lson], tree[rson]);
}

Node query(int ll, int rr, int l, int r, int rt)
{
    if (ll <= l && rr >= r) {
        return tree[rt];
    }
    int m = (l+r)>>1;
    int lson = rt<<1;
    int rson = lson+1;
    if (rr <= m) {
        return query(ll, rr, l, m, lson);
    }
    if (ll > m) {
        return query(ll, rr, m+1, r, rson);
    }
    return combine(query(ll, m, l, m, lson), query(m+1, rr, m+1, r, rson));
}

int n, m;
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> d[i];
        d[i+n] = d[i];
    }
    for (int i = 1; i <= 2*n; ++i) {
        d[i] += d[i-1];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
        h[i] <<= 1;
        h[i+n] = h[i];
    }
    build(1,2*n,1);
    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        int l, r;
        if (a <= b) {
            l = b+1, r = a+n-1;
        } else {
            l = b+1, r = a-1;
        }
        cout << query(l,r,1,2*n,1).mval << endl;
    }
}
