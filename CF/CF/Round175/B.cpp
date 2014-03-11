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
const int MAXN = 100005;
const int INF = 0xfffffff;
int n;
int to[MAXN];
int s, t;
bool vis[MAXN];
int dfs(int a) {
    if (a == t)
        return 0;
    int ret = INF;
    vis[a] = true;
    if (!vis[to[a]])
        ret = min(ret,1+dfs(to[a]));
    return ret;
}
int main() {
    scanf("%d%d%d", &n, &s, &t);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", to+i);
    }
    int ans = dfs(s);
    if (ans == INF) {
        puts("-1");
    }
    else {
        printf("%d\n", ans);
    }
    return 0;
}
