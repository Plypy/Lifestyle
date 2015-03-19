/**
 * Description:
 * ProblemName:
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
#include <vector>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
using namespace std;

const int MOD = 1000000000+7;
const int MAXN = 100005;
typedef long long ll;
ll ans[MAXN];
int dep[MAXN];
struct Edge {
    int v;
    Edge *nxt;
    Edge(int v = 0, Edge *nxt = 0): v(v), nxt(nxt) {}
} epool[MAXN], *adj[MAXN], *eptr;

void add(int fa, int son) {
    adj[fa] = new (eptr++) Edge(son,adj[fa]);
}
void dfs(int u, int d) {
    dep[u] = d;
    for (Edge *t = adj[u]; t; t = t->nxt) {
        int v = t->v;
        dfs(v,d+1);
    }
}
ll L, R, D;
void update(int u) {
    if (dep[u] > R)
        return;
    if (dep[u] >= L)
        ans[u] += D;
    for (Edge *t = adj[u]; t; t = t->nxt) {
        int v = t->v;
        update(v);
    }
}
void init() {
    eptr = epool;
    memset(dep,0,sizeof(dep));
    memset(adj,0,sizeof(adj));
    memset(ans,0,sizeof(ans));
}

int n;
int HASH() {
    long long magic = 12347;
    long long ret = 0;
    for (int i = 1; i <= n; ++i)
        ret = (ret*magic+ans[i])%MOD;
    return ret;
}
void load() {
    scanf("%d", &n);
    for (int i = 2; i <= n; ++i) {
        int a;
        scanf("%d", &a);
        add(a,i);
    }
}
int work() {
    dfs(1,1);
    int q;
    scanf("%d", &q);
    while (q--) {
        int u, l, r, d;
        scanf("%d%d%d%d", &u, &l, &r, &d);
        L = l, R = r, D = d;
        update(u);
    }
    // for (int i = 1; i <= n; ++i)
    //     cout << i << ' ' << ans[i] << endl;
    return HASH();
}

int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        init();
        load();
        int ans =  work();
        printf("Case %d: %d\n", t, ans);
    }
    return 0;
}