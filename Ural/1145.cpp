#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <cstring>
using namespace std;
const int MAXN = 1005;
int g[MAXN][MAXN];
int n, m;
int sx, sy;
void load() {
    cin >> m >> n;
    for (int i = 1; i <= n; ++i) {
        while (getchar() != '\n')
            continue;
        for (int j = 1; j <= m; ++j) {
            char c = getchar();
            if ('.' == c) {
                g[i][j] = true;
                sx = i, sy = j;
            }
        }
    }
}
int move[4][2] = {
    {1,0},
    {-1,0},
    {0,1},
    {0,-1}
};
struct Node {
    int x, y;
    int d;
    Node(int a = 0, int b = 0, int c = 0): x(a), y(b), d(c) { }
} ;
int ans = 0;
int fx, fy;
bool used[MAXN][MAXN];
void find(int tx, int ty) {
    memset(used,0,sizeof(used));
    queue<Node> que;
    que.push(Node(tx,ty,0));
    used[tx][ty] = true;
    while (que.size()) {
        int cx = que.front().x;
        int cy = que.front().y;
        int d = que.front().d;
        ans = max(ans,d);
        que.pop();
        fx = cx;
        fy = cy;
        for (int i = 0; i < 4; ++i) {
            int dx = cx+move[i][0], dy = cy+move[i][1];
            if (g[dx][dy] && !used[dx][dy]) {
                used[dx][dy] = true;
                que.push(Node(dx,dy,d+1));
            }
        }
    }
}
void work() {
    find(sx,sy);
    find(fx,fy);
    cout << ans << endl;
}
int main() {
    load();
    work();
    return 0;
}
