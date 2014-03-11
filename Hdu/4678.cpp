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


const int MAXN = 1005;
const int INF = 0x3f3f3f3f;
int board[MAXN][MAXN];
bool vis[MAXN][MAXN];

int n, m;
int bfs(int x, int y) {
    int ret = 0;
    int blank = false;
    queue<pair<int, int> > que;
    que.push(make_pair(x, y));
    vis[x][y] = true;
    while (que.size()) {
        pair<int, int> cur = que.front();
        que.pop();
        int cx = cur.first, cy = cur.second;
        if (0 == board[cx][cy])
            blank = true;
        else
            ++ret;
        for (int tx = cx-1; tx <= cx+1; ++tx)
            for (int ty = cy-1; ty <= cy+1; ++ty) {
                if (!vis[tx][ty]) {
                    if (0 == board[cx][cy] || 0 == board[tx][ty]) {
                        vis[tx][ty] = true;
                        que.push(make_pair(tx, ty));
                    }
                }
            }
    }
    if (blank)
        ++ret;
    return ret;
}
void clear() {
    memset(board,0,sizeof(board));
    memset(vis,0,sizeof(vis));
}
bool work() {
    for (int i = 0; i <= n+1; ++i)
        vis[i][0] = vis[i][m+1] = true;
    for (int i = 0; i <= m+1; ++i)
        vis[0][i] = vis[n+1][i] = true;
    int sg = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            if (!vis[i][j]) {
                int cnt = bfs(i,j);
                if (cnt&1)
                    sg ^= 1;
                else
                    sg ^= 2;
            }
    }
    return sg;
}
void load() {
    int k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= k; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        ++x, ++y;
        vis[x][y] = true;
        for (int tj = x-1; tj <= x+1; ++tj)
            for (int tk = y-1; tk <= y+1; ++tk)
                ++board[tj][tk];
    }
}
int main(int argc, char const *argv[]) {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        load();
        printf("Case #%d: %s\n", i, work()?"Xiemao":"Fanglaoshi");
        clear();
    }
    return 0;
}