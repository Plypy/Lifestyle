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

const int MAXN = 20005;
const int MAXQ = 20005;

int phi[MAXN];
void prep() {
    phi[1] = 1;
    for (int i = 2; i < MAXN; ++i) {
        if (!phi[i]) {
            for (int j = i; j < MAXN; j += i) {
                if (!phi[j]) {
                    phi[j] = j;
                }
                phi[j] = phi[j]/i*(i-1);
            }
        }
    }
}

struct Query {
    int l, r;
    int id;
    int p;
    bool operator<(const Query &t) const {
        if (p != t.p)
            return p < t.p;
        return r < t.r;
    }
} query[MAXQ];
int ans[MAXQ];

int ar[MAXN];

int num[MAXN];
vector<int> dar[MAXN];
int sum;
int l, r;
int n, q;
void clear() {
    memset(num,0,sizeof(num));
    sum = l = r = 0;
}
void ins(int pos) {
    int len = dar[pos].size();
    for (int i = 0; i < len; ++i) {
        int d = dar[pos][i];
        sum += num[d]*phi[d];
        ++num[d];
    }
}
void del(int pos) {
    int len = dar[pos].size();
    for (int i = 0; i < len; ++i) {
        int d = dar[pos][i];
        --num[d];
        sum -= num[d]*phi[d];
    }
}
void getdiv() {
    for (int i = 0; i < n; ++i) {
        dar[i].clear();
        for (int j = 1; j*j <= ar[i]; ++j) {
            if (0 == ar[i]%j) {
                dar[i].push_back(j);
                if (j*j != ar[i])
                    dar[i].push_back(ar[i]/j);
            }
        }
    }
}

void work() {
    getdiv();
    sort(query,query+q);
    for (int i = 0; i < q; ++i) {
        Query t = query[i];
        while (l>t.l)
            ins(--l);
        while (l<t.l)
            del(l++);
        while (r<t.r)
            ins(r++);
        while (r>t.r)
            del(--r);
        ans[t.id] = sum;
    }
    for (int i = 0; i < q; ++i)
        printf("%d\n", ans[i]);
}
void load() {
    scanf("%d", &n);
    int bsize = sqrt(n+0.5);
    for (int i = 0; i < n; ++i) {
        scanf("%d", ar+i);
    }
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a;
        query[i].l = a, query[i].r = b;
        query[i].id = i;
        query[i].p = a/bsize;
    }
}
int main(int argc, char const *argv[]) {
    int T;
    scanf("%d", &T);
    prep();
    for (int i = 1; i <= T; ++i) {
        load();
        printf("Case #%d:\n", i);
        work();
        clear();
    }
    return 0;
}