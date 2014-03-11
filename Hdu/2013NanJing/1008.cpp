/**
 * Description:
 * ProblemName: Cirno's Present
 * Source: 2013NanJing onsite
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
#define SET(f,v) memset(f,v,sizeof(f))
typedef long long ll;
const int MOD = 1000000000+7;
const int MAXN = 305;

const int MAXV = MAXN;
const int MAXE = MAXV*2;
struct Edge {
    int vtx;
    Edge *nxt;
    Edge() {}
    Edge(int a, Edge *b): vtx(a), nxt(b) {}
} epool[MAXE], *adj[MAXV], *eptr = epool;

void add(int u, int v) {
    adj[u] = new (eptr++) Edge(v,adj[u]);
    adj[v] = new (eptr++) Edge(u,adj[v]);
}
typedef ll* pll;
pll dp[MAXN][3];
ll pool[MAXN][3][2*MAXN];
ll npool[3][2*MAXN];
pll buf[3];
ll lbd[MAXN], rbd[MAXN];
int n;
void init() {
    for (int i = 0; i < 3; ++i)
        buf[i] = npool[i]+MAXN;
    for (int i = 0; i < MAXN; ++i)
        for (int j = 0; j < 3; ++j)
            dp[i][j] = pool[i][j]+MAXN;
}
void clear() {
    SET(pool,0);
    SET(adj,0);
    eptr = epool;
}
bool load() {
    if (scanf("%d", &n) == EOF)
        return false;
    clear();
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }
    return true;
}
int LBD, RBD;
void dfs(int u, int fa) {
    dp[u][0][0] = 2;
    dp[u][1][0] = 1;
    lbd[u] = rbd[u] = 0;
    for (Edge *t = adj[u]; t; t = t->nxt) {
        int v = t->vtx;
        if (v == fa)
            continue;
        dfs(v,u);
        SET(npool, 0);
        for (int i = lbd[u]; i <= rbd[u]; ++i)
            for (int j = lbd[v]-1; j <= rbd[v]+1; ++j) {
                if (i+j < LBD || i+j > RBD) continue;
                buf[0][i+j] += dp[u][0][i]*dp[v][0][j]+dp[u][0][i]*dp[v][1][j-1]+dp[u][0][i]*dp[v][2][j+1];
                buf[1][i+j] += dp[u][1][i]*dp[v][0][j]+dp[u][1][i]*dp[v][2][j]+dp[u][2][i]*dp[v][1][j];
                buf[2][i+j] += dp[u][2][i]*dp[v][0][j]+dp[u][1][i]*dp[v][1][j]+dp[u][2][i]*dp[v][2][j];
                for (int k = 0; k < 3; ++k) {
                    buf[k][i+j] %= MOD;
                    if (buf[k][i+j]) {
                        if (i+j > rbd[u])
                            rbd[u] = i+j;
                        if (i+j < lbd[u])
                            lbd[u] = i+j;
                    }
                }
            }
        for (int i = lbd[u]; i <= rbd[u]; ++i)
            for (int j = 0; j < 3; ++j)
                dp[u][j][i] = buf[j][i];
    }
}
void check(int u, int fa) {
    cout << u << ' ' << fa << endl;
    for (Edge *t = adj[u]; t; t = t->nxt) {
        cout << "son " << u << ' ' << t->vtx << endl;
        if (t->vtx != fa)
            check(t->vtx, u);
    }
}
void work() {
    LBD = -n;
    RBD = n;
    int rt = rand()%n+1;
    // check(rt,-1);
    dfs(rt,-1);
    ll ans = 0;
    for (int i = -1; i <= rbd[rt]; ++i) {
        ans += dp[rt][0][i]*max(i,0)+dp[rt][1][i]*max(i+1,0)+dp[rt][2][i]*max(i-1,0);
        ans %= MOD;
    }
    ans = ans*3%MOD;
    printf("%I64d\n", ans);
}
void test() {
    for (int i = 0; i < MAXN; ++i)
        for (int j = 0; j < 3; ++j)
            for (int k = -300; k <= 300; ++k) {
                // cout << i << ' ' << j << ' ' << k << endl;
                dp[i][j][k] += 1;
            }
    cout << "finished" << endl;
}

int main(int argc, char const *argv[]) {
    init();
    // test();
    while (load()) {
        work();
    }
    return 0;
}