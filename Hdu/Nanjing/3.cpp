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

const int MAXN = 10005;
const int MAXE = 500005;
const int MAXP = 600005;
int fa[MAXN];
int num[MAXN];
int find(int a) {
    if (fa[a] == a)
        return a;
    return fa[a] = find(fa[a]);
}
void merge(int a, int b) {
    a = find(a), b = find(b);
    fa[a] = b;
    num[b] += num[a];
}

int c[MAXP];
int maxn;
int tot;
int lowbit(int a) {
    return a&-a;
}
void ins(int a, int d) {
    tot += d;
    while (a<maxn) {
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
int getL(int a) {
    return tot-get(a-1);
}
struct Edge {
    int u, v, l;
    int id;
    bool operator<(const Edge &t) const {
        if (l == t.l) {
            return id!=0;
        }
        return l<t.l;
    }
} e[MAXP];
int ect;
const int MAXQ = 100005;
vector<int> aid;
int ans[MAXQ];
int n, m, p;

void work() {
    sort(e+1,e+ect+1);
    for (int i = 1; i <= ect; ++i) {
        if (e[i].id) {
            aid.push_back(e[i].id);
        } else {
            int u = e[i].u , v = e[i].v;
            u = find(u), v = find(v);
            if (u != v) {
                int dans = num[u]*num[v]*2;
                int len = aid.size();
                for (int i = 0; i < len; ++i) {
                    ans[e[i].id] += dans;
                }
                merge(u,v);
            }
        }
    }
    for (int i = 1; i <= p; ++i) {
        printf("%d\n", ans[i]);
    }
}
void init() {
    for (int i = 1; i < MAXN; ++i)
        fa[i] = i, num[i] = 1;
    memset(e,0,sizeof(e));
    memset(c,0,sizeof(c));
    aid.clear();
    tot = 0;
}
bool load() {
    if (EOF == scanf("%d%d", &n, &m))
        return false;
    init();
    for (int i = 1; i <= m; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        ++a, ++b;
        e[i].u = a, e[i].v = b, e[i].l = c;
    }
    scanf("%d", &p);
    ect = m+p;
    for (int i = 1; i <= p; ++i) {
        int t;
        scanf("%d", &t);
        e[m+i].l = t;
        e[m+i].id = i;
    }
    return true;
}
int main(int argc, char const *argv[]) {
    while (load()) {
        work();
    }
    return 0;
}