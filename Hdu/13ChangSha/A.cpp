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

const int MAXK = 25;
const int MAXN = 205;

int g[MAXN][MAXN];
int loc[MAXK][2];
int n, m, k;
void clear() {
    memset(g,0,sizeof(g));
}
bool load() {
    scanf("%d%d", &n, &m);
    if (n == 0)
        return false;
    k = 0;
    char buf[MAXN];
    for (int i = 1; i <= n; ++i) {
        scanf("%s", buf);
        for (int j = 1; j <= m; ++j) {
            if (buf[j-1] == '#') {
                g[i][j] = 1;
            } else {
                g[i][j] = 0;
                loc[++k][0] = i;
                loc[k][1] = j;
            }
        }
    }
    return true;
}

int vis[MAXN][MAXN];
int move[5][2] = {
    {0,1},
    {-1,0},
    {0,-1},
    {1,0},
    {0,1}
};

bool used[MAXK];
bool check(int id, int dir) {
    if (used[id])
        return false;
    int x = loc[id][0], y = loc[id][1];
    for (int d = dir; d < dir+2; ++d) {
        int tx = x+move[d][0], ty = y+move[d][1];
        if (g[tx][ty] == 1)
            return false;
    }
    return true;
}
void in(int id, int dir) {
    int x = loc[id][0], y = loc[id][1];
    used[id] = true;
    ++vis[x][y];
    for (int d = dir; d < dir+2; ++d) {
        int tx = x+move[d][0], ty = y+move[d][1];
        ++vis[tx][ty];
    }
}
void out(int id, int dir) {
    int x = loc[id][0], y = loc[id][1];
    used[id] = false;
    --vis[x][y];
    for (int d = dir; d < dir+2; ++d) {
        int tx = x+move[d][0], ty = y+move[d][1];
        --vis[tx][ty];
    }
}
int ans;

void dfs(int dep, int num) {
    if (num >= ans)
        return;
    if (dep == k+1) {
        for (int i = 1; i <= k; ++i)
            if (vis[loc[i][0]][loc[i][1]] == 0)
                return;
        ans = min(ans,num);
        return;
    }
    dfs(dep+1,num);
    if (check(dep, 0)) {
        in(dep,0);
        dfs(dep+1,num+1);
        out(dep,0);
    }
}
void work() {
    if (k == 0) {
        puts("0");
        return;
    }

    ans = 1000;
    // in(1,0);
    // in(4,1);
    // for (int i = 1; i <= 4; ++i) {
    //     int x = loc[i][0], y = loc[i][1];
    //     cout << x << ' ' << y << endl;
    //     cout << vis[x][y] << endl;
    // }
    // dfs(5,2);
    // cout << ans << endl;
    for (int i = 1; i <= k; ++i)
        for (int d = 0; d < 4; ++d) {
            if (check(i, d)) {
                in(i,d);
                dfs(1,1);
                out(i,d);
            }
        }
    if (ans == 1000)
        puts("-1");
    else
        printf("%d\n", ans);
}
int main(int argc, char const *argv[]) {
    while (load()) {
        work();
        clear();
    }
    return 0;
}