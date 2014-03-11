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
typedef pair<int,int> pi;
const int MAXN = 105;
int move[4][2] = {
    {0,1},
    {0,-1},
    {1,0},
    {-1,0}
};
int g[MAXN][MAXN];
int loc[10][2];
int n, m, k;
int dis[MAXN][MAXN];
void bfs(int sx, int sy) {
    memset(dis,-1,sizeof(dis));
    queue<pi> que;
    que.push(make_pair(sx, sy));
    dis[sx][sy] = 0;
    while (que.size()) {
        pi cur = que.front();
        que.pop();
        int cx = cur.first, cy = cur.second;
        for (int i = 0; i < 4; ++i) {
            int tx = cx+move[i][0], ty = cy+move[i][1];
            if (dis[tx][ty] == -1 && g[tx][ty] == 1) {
                dis[tx][ty] = dis[cx][cy]+1;
                que.push(make_pair(tx, ty));
            }
        }
    }
}
char buf[MAXN];
void clear() {
    memset(g,0,sizeof(g));
}
bool load() {
    scanf("%d%d", &n, &m);
    if (n == 0 && m == 0)
        return false;
    for (int i = 1; i <= n; ++i) {
        scanf("%s", buf);
        for (int j = 1; j <= m; ++j) {
            if (buf[j-1] == '@') {
                loc[0][0] = i, loc[0][1] = j;
                g[i][j] = 1;
            } else if (buf[j-1] == '.') {
                g[i][j] = 1;
            } else {
                g[i][j] = 0;
            }
        }
    }
    scanf("%d", &k);
    for (int i = 1; i <= k; ++i) {
        scanf("%d%d", &loc[i][0], &loc[i][1]);
    }
    return true;
}
const int MAXK = 15;
int dist[MAXK][MAXK];
void search(int x) {
    bfs(loc[x][0],loc[x][1]);
    for (int i = 0; i <= k; ++i)
        dist[x][i] = dis[loc[i][0]][loc[i][1]];
}
bool vis[MAXN];
int dfs(int dep, int u) {
    if (dep == k)
        return 0;
    int ret = 10000;
    for (int j = 1; j <= k; ++j) {
        if (!vis[j]) {
            vis[j] = true;
            ret = min(ret,dist[u][j]+dfs(dep+1,j));
            vis[j] = false;
        }
    }
    return ret;
}
void work() {
    for (int i = 0; i <= k; ++i)
        search(i);
    // for (int i = 0; i <= k; ++i) {
    //     for (int j = 0; j <= k; ++j) {
    //         cout << dist[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    for (int i = 1; i <= k; ++i) {
        if (dist[0][i] == -1) {
            puts("-1");
            return ;
        }
    }
    int ans = dfs(0,0);
    printf("%d\n", ans);
}
int main(int argc, char const *argv[]) {
    while (load()) {
        work();
        clear();
    }
    return 0;
}