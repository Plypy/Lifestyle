// NOTE
// 对于全局数组，如果不对其中的某个元素进行静态赋值，则编译器会自动为其赋零值
// 否则不会自动赋零值，即使你是在函数内做的静态赋值
// 注意对模型仔细分析，这道题中对于每个联通块中的双色之一必须选择一个，进而不能使用简单的背包
// 这样会对某些联通快不进行选择
/**
 * Author: Ply_py
 */

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
const int MAXN = 55;
const int MAXM = 105;
const int MAXV = MAXN*2;
void fail() {
    cout << "IMPOSSIBLE" << endl;
    exit(0);
}
bool g[MAXV][MAXV];
int n, m;
int vtot;
int deg[MAXV];
void load() {
    cin >> n >> m;
    vtot = 2*n;
    while (m--) {
        int a, b;
        cin >> a >> b;
        ++deg[a];
        ++deg[b];
        g[a][b] = g[b][a] = true;
    }
}
int col[MAXV];
int cct[MAXV];

int change(int c) {
    if (c&1)
        ++c;
    else
        --c;
    return c;
}
void dfs(int u, int c) {
    if (col[u] == c)
        return;
    if (change(c) == col[u])
        fail();
    col[u] = c;
    ++cct[c];
    for (int v = 1; v <= vtot; ++v)
        if (g[u][v])
            dfs(v,change(c));
}

int f[MAXV];
int bf[MAXV];
int use[MAXV][MAXV];
bool side[MAXV];
void init() {
    memset(f,0,sizeof(f));
    memset(bf,0,sizeof(bf));
    memset(use,0,sizeof(use));
    memset(side,0,sizeof(side));
    memset(col,0,sizeof(col));
    memset(cct,0,sizeof(cct));
    memset(g,0,sizeof(g));
    memset(deg,0,sizeof(deg));
}
void mark(int c) {
    for (int v = 1; v <= vtot; ++v)
        if (col[v] == c)
            side[v] = true;
}
void display(int c) {
    cout << "disping" << endl;
    for (int v = 1; v <= vtot; ++v)
        if (col[v] == c)
            cout << v << ' ';
    cout << endl << "end" << endl;
}
int mem[MAXV][MAXV];
bool check(int dep, int sum) {
    if (mem[dep][sum] != -1)
        return mem[dep][sum];
    if (sum > n || dep > vtot)
        return false;
    if (dep*2 == col[0] && sum == n)
        return true;
    bool ret = false;
    if (check(dep+1,sum+cct[dep*2+1])) {
        use[dep][sum] = dep*2+1;
        ret = true;
    } else if (check(dep+1,sum+cct[dep*2+2])) {
        use[dep][sum] = dep*2+2;
        ret = true;
    }
    return mem[dep][sum] = ret;
}
void dp() {
    memset(mem,-1,sizeof(mem));
    if (!check(0,0))
        fail();
    for (int i = 0, sum = 0; 2*i < col[0]; ++i) {
        int tmp = use[i][sum];
        sum += cct[use[i][sum]];
        mark(tmp);
    }
}

void answer() {
    bool first = true;
    for (int i = 1; i <= vtot; ++i)
        if (side[i]) {
            if (first)
                first = false;
            else
                cout << ' ';
            cout << i;
        }
    cout << endl;
    first = true;
    for (int i = 1; i <= vtot; ++i)
        if (!side[i]) {
            if (first)
                first = false;
            else
                cout << ' ';
            cout << i;
        }
    cout << endl;
}
void work() {
    for (int i = 1; i <= vtot; ++i) {
        int u = i;
        if (col[u])
            continue;
        ++col[0];
        dfs(u,col[0]);
        ++col[0];
    }
    dp();
    answer();
}
int main() {
    init();
    load();
    work();
    return 0;
}

