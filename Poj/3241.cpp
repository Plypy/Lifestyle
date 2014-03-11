/**
 * Description: Minimum Manhattan Spaning Tree
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
const int INF = 0X3FFFFFFF;
const int MAXE = MAXN*4;
const int MAXV = MAXN;

struct Node {
    int key, id;
    Node(int a = 0, int b = 0): key(a), id(b) {}
    bool operator<(const Node &t) const {
        return key<t.key;
    }
} tree[MAXV];

inline int lowbit(int x) {
    return x&(-x);
}
inline int get_min(const int &pos) {
    Node ret = Node(INF);
    for (int i = pos; i; i ^= lowbit(i)) if (tree[i].id != -1) {
        ret = min(ret,tree[i]);
    }
    return ret.key == INF?-1:ret.id;
}
inline void insert(const int &n, const int &p, const Node &node) {
    for (int i = p; i <= n; i += lowbit(i))
        if (tree[i].id == -1 || node<tree[i])
            tree[i] = node;
}
inline void clearTree(const int &n) {
    for (int i = 1; i <= n; ++i)
        tree[i].id = -1;
}
int bak[MAXN];
void discrete(int x[], int idx[], int n) {
    for (int i = 0; i < n; ++i)
        bak[i] = x[i];
    sort(bak, bak+n,greater<int>());
    int p = unique(bak,bak+n)-bak;
    for (int i = 0; i < n; ++i)
        idx[i] = lower_bound(bak, bak+p, x[i], greater<int>())-bak+1;
}
int x[MAXN], y[MAXN], n;
inline bool cmp(const int &i, const int &j) {
    int a = x[i]-y[i], b = x[j]-y[j];
    return a<b || (a==b && y[i]>y[j]);
}
struct Edge {
    int u, v, len;
    Edge(int a = 0, int b = 0, int c = 0): u(a), v(b), len(c) {}
    bool operator<(const Edge &t) const {
        return len<t.len;
    }
} edge[MAXE];
int ect;
void add(int u, int v) {
    edge[ect++] = Edge(u,v,abs(x[u]-x[v])+abs(y[u]-y[v]));
}
int fa[MAXN];
int find(int a) {
    if (fa[a] == a)
        return a;
    return fa[a] = find(fa[a]);
}
bool merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v)
        return false;
    fa[u] = v;
    return true;
}
void init() {
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
}
int idx[MAXN], id[MAXN];
int solve(int k) {
    for (int dir = 0; dir < 4; ++dir) {
        if (1 == dir || 3 == dir) {
            for (int i = 0; i < n; ++i)
                swap(x[i],y[i]);
        } else if (2 == dir) {
            for (int i = 0; i < n; ++i)
                x[i] = -x[i];
        }
        for (int i = 0; i < n; ++i)
            id[i] = i;
        sort(id,id+n,cmp);
        discrete(x, idx, n);
        clearTree(n);

        for (int i = 0; i < n; ++i) {
            int u = id[i], v = get_min(idx[u]);
            if (v != -1) {
                add(u, v);
                // cout << u << " connects " << v << endl;
            }
            insert(n, idx[u], Node(x[u]+y[u],u));
        }
    }

    k = n-k;
    sort(edge, edge+ect);
    init();
    for (int i = 0; i < ect; ++i) {
        int u = edge[i].u, v = edge[i].v;
        if (merge(u,v)) {
            --k;
            if (0 == k)
                return edge[i].len;
        }
    }
    return INF;
}
int k;
int main(int argc, char const *argv[]) {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
        scanf("%d%d", x+i, y+i);
    printf("%d\n", solve(k));
    return 0;
}