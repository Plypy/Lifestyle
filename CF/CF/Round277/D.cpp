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
#include <bitset>
#include <stack>
using namespace std;

const int MAXM = 30005;
const int MAXN = 3005;

struct Edge {
    int vtx;
    Edge *nxt;
    Edge(int iv = 0, Edge *in = 0): vtx(iv), nxt(in) {}
} epool[MAXM], *adj[MAXN], *eptr = epool;

void add(int u, int v) {
    adj[u] = new (eptr++) Edge(v, adj[u]);
}

int cnt[MAXN];

void dfs(int u, int d) {
    if (3 == d) {
        return;
    }
    if (2 == d) {
        ++cnt[u];
        return ;
    }
    for (Edge *t = adj[u]; t; t = t->nxt) {
        int v = t->vtx;
        dfs(v, d+1);
    }
}

int N, M;

int f(int x) {
    return x*(x-1)/2;
}

int main() {
    cin >> N >> M;
    int ans = 0;
    for (int i = 1; i <= M; ++i) {
        int a, b;
        cin >> a >> b;
        add(a,b);
    }

    for (int i = 1; i <= N; ++i) {
        memset(cnt, 0, sizeof(cnt));
        dfs(i,0);
        for (int j = 1; j <= N; ++j) {
            if (j == i) {
                continue;
            }
            ans += f(cnt[j]);
        }
    }
    cout << ans << endl;
}
