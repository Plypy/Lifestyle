#include <iostream>
#include <cstdlib>
#include <queue>
#include <cctype>
using namespace std;
const int MAXN = 110;
const int INF = 52111425;
struct Portal {
    int r1, c1;
    int r2, c2;
} portal[30];
char map[MAXN][MAXN];
int n, m;
void load() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            cin >> map[i][j];
            if (isalpha(map[i][j])) {
                int pos = map[i][j] - 'A';
                if (portal[pos].r1 == 0) {
                    portal[pos].r1 = i;
                    portal[pos].c1 = j;
                } else {
                    portal[pos].r2 = i;
                    portal[pos].c2 = j;
                }
            }
        }
}
int dis[MAXN][MAXN];
const int move[4][2] = {
    {0,1},
    {0,-1},
    {1,0},
    {-1,0}
};
struct Point {
    int x, y;
    Point(int _x, int _y):
        x(_x), y(_y) { }
};
void work() {
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            dis[i][j] = INF;
    dis[1][1] = 0;
    queue<Point> que;
    que.push(Point(1,1));
    while (!que.empty()) {
        Point cur = que.front();
        que.pop();
        int cx = cur.x;
        int cy = cur.y;
        int cdis = dis[cx][cy];
        
        for (int i = 0; i < 4; ++i) {
            int dx = cx+move[i][0];
            int dy = cy+move[i][1];
            if (dis[dx][dy] == 0 || map[dx][dy] == '1')
                continue;
            if (isalpha(map[dx][dy])) {
                int pos = map[dx][dy]-'A';
                if (dx == portal[pos].r1 && dy == portal[pos].c1) {
                    dx = portal[pos].r2;
                    dy = portal[pos].c2;
                } else {
                    dx = portal[pos].r1;
                    dy = portal[pos].c1;
                }
            }
            if (dis[dx][dy] > cdis+1) {
                dis[dx][dy] = cdis+1;
                que.push(Point(dx,dy));
            }
        }
        if (dis[n][m] != INF)
            break;
    }
    if (dis[n][m] != INF)
        cout << dis[n][m] << endl;
    else
        cout << "No Solution." << endl;
//    system("pause");
}
int main() {
    load();
    work();
    return 0;
}
/*
3 4
0000
00A0
A000

ans
4
*/
