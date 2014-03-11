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

const int MAXN = 105;
struct Edge {
    int a, b, c;
    bool operator<(const Edge &t) const {
        return c<t.c;
    }
} edge[MAXN];
int n, m;

int f[MAXN];
void init() {
    for (int i = 1; i <= n; ++i)
        f[i] = i;
}
int find(int a) {
    if (f[a] != a)
        return f[a] = find(f[a]);
    return a;
}
bool merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b)
        return false;
    f[a] = b;
    return true;
}
void work() {
    sort(edge,edge+m);
    int ans = 0;
    init();
    for (int i = 0; i < m; ++i) {
        int u = edge[i].a;
        int v = edge[i].b;
        int w = edge[i].c;
        if (merge(u,v))
            ans += w;
    }
    cout << ans << endl;
}
void load() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> edge[i].a >> edge[i].b >> edge[i].c;
    }
}
int main() {
    load();
    work();
}