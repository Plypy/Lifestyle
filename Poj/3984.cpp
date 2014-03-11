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
#include <cmath>
using namespace std;
const int MAXN = 10;
bool g[MAXN][MAXN];
int n = 5;
void load() {
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            int t;
            cin >> t;
            if (!t)
                g[i][j] = true;
        }
}
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int apre[MAXN][MAXN];
int pre[MAXN][MAXN];
int ans = 10000;
bool used[MAXN][MAXN];
void dfs(int x, int y, int d) {
    if (x == n && y == n) {
        if (d < ans) {
            ans = d;
            memcpy(apre,pre,sizeof(pre));
        }
        return ;
    }
    for (int i = 0; i < 4; ++i) {
        int tx = x+dx[i];
        int ty = y+dy[i];
        if (g[tx][ty] && !used[tx][ty]) {
            pre[tx][ty] = i;
            used[tx][ty] = true;
            dfs(tx,ty,d+1);
            used[tx][ty] = false;
        }
    }
}
void print(int x, int y) {
    int t = apre[x][y];
    int tx = x-dx[t], ty = y-dy[t];
    if (x != 1 || y != 1)
        print(tx,ty);
    printf("(%d, %d)\n", x-1, y-1);
}
void work() {
    used[1][1] = true;
    dfs(1,1,0);
    print(n,n);
}
int main() {
    load();
    work();
    return 0;
}
