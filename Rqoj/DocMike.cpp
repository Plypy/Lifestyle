#include <iostream>
using namespace std;
const int MAXN = 1000;
struct pos
{
    int x;
    int y;
} que[MAXN*MAXN], bg, ed;
bool vis[MAXN][MAXN];
int dis[MAXN][MAXN];
string line[MAXN];
int n;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> line[i];
    cin >> ed.x >> ed.y >> bg.x >> bg.y;
    ed.x--;
    ed.y--;
    bg.x--;
    bg.y--;
    int b, e;
    b = 0; e = 0;
    que[b].x = bg.x;
    que[b].y = bg.y;
    vis[bg.x][bg.y] = true;
    pos tmp;
    int x, y;
    while (b <= e)
    {
        tmp = que[b++];
        x = tmp.x+1;
        y = tmp.y;
        if (x < n && !vis[x][y] && line[x][y] == '0')
        {
            vis[x][y] = true;
            que[++e].x = x;
            que[e].y = y;
            dis[x][y] = dis[tmp.x][tmp.y]+1;
        }
        x = tmp.x-1;
        y = tmp.y;
        if (x >= 0 && !vis[x][y] && line[x][y] == '0')
        {
            vis[x][y] = true;
            que[++e].x = x;
            que[e].y = y;
            dis[x][y] = dis[tmp.x][tmp.y]+1;
        }
        x = tmp.x;
        y = tmp.y+1;
        if (y < n && !vis[x][y] && line[x][y] == '0')
        {
            vis[x][y] = true;
            que[++e].x = x;
            que[e].y = y;
            dis[x][y] = dis[tmp.x][tmp.y]+1;
        }
        x = tmp.x;
        y = tmp.y-1;
        if (y >= 0 && !vis[x][y] && line[x][y] == '0')
        {
            vis[x][y] = true;
            que[++e].x = x;
            que[e].y = y;
            dis[x][y] = dis[tmp.x][tmp.y]+1;
        }
        if (vis[ed.x][ed.y])
            break;
    }
    cout << dis[ed.x][ed.y];
    return 0;
}
