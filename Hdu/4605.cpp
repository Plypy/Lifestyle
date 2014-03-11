/**
 * Description:
 * Source:
 * Author: Ply_py
 */
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
const int MAXQ = MAXN;
struct Tarray {
    int c[MAXN+MAXQ];
    int size;
    int n;
    int lowbit(int a) {
        return a&(-a);
    }
    void modify(int a, int d) {
        size += d;
        while (a <= n) {
            c[a] += d;
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
    int get(int l, int r) {
        return get(r)-get(l-1);
    }
}ltree,rtree;
typedef pair<int,int> pii;
map<int,int> table;
vector<pii> qvec[MAXN];
int n, m;
int weight[MAXN];
int lson[MAXN], rson[MAXN];
void init() {
    table.clear();
    for (int i = 1; i <= n; ++i)
        qvec[i].clear();
    memset(lson,0,sizeof(lson));
    memset(rson,0,sizeof(rson));
}
int lans[MAXQ], rans[MAXQ];
void dfs(int u) {
    int wt = table[weight[u]];
    for (int i = 0; i < qvec[u].size(); ++i) {
        pii tmp = qvec[u][i];
        int x = tmp.first;
        x = table[x];
        int index = tmp.second;
        if (ltree.get(x,x) || rtree.get(x,x)) {
            lans[index] = rans[index] = -1;
        } else {
            int l1 = ltree.get(x-1);
            int l2 = ltree.size-l1;
            int r1 = rtree.get(x-1);
            int r2 = rtree.size-r1;
            lans[index] = r1;
            rans[index] = 3*l1+l2+3*r1+r2;
        }
    }
    if (lson[u]) {
        ltree.modify(wt, 1);
        dfs(lson[u]);
        ltree.modify(wt, -1);

        rtree.modify(wt, 1);
        dfs(rson[u]);
        rtree.modify(wt, -1);
    }
}
int cnt;
void prepare() {
    cnt = 0;
    for (map<int,int>::iterator itr = table.begin(); itr != table.end(); ++itr) {
        itr->second = ++cnt;
    }
    ltree.n = rtree.n = cnt;
}

void work() {
    prepare();
    dfs(1);
    for (int i = 1; i <= m; ++i) {
        if (-1 == lans[i]) {
            printf("0\n");
            continue;
        }
        printf("%d %d\n", lans[i], rans[i]);
    }
}

void load() {
    scanf("%d", &n);
    init();
    for (int i = 1; i <= n; ++i) {
        scanf("%d", weight+i);
        table[weight[i]] = 0;
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) {
        int u, a, b;
        scanf("%d%d%d", &u, &a, &b);
        lson[u] = a;
        rson[u] = b;
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) {
        int v, x;
        scanf("%d%d", &v, &x);
        qvec[v].push_back(make_pair(x, i));
        table[x] = 0;
    }
}
int main(int argc, char const *argv[]) {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        load();
        work();
    }
    return 0;
}