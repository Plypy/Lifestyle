//这个spfa我调试了好几天...
//原来只是因为队列不够大...  
/*
#include <stdio.h>
using namespace std;
const int dx[8] = {1,1, 1,-1,-1,-1,0, 0};
const int dy[8] = {0,1,-1, 1, 0,-1,1,-1};
const int MAXN = 505;
const int INF = 19940306;
int n, m;
int x1, y1;
int x2, y2;
int hit[MAXN][MAXN];
int dis[MAXN][MAXN];
struct pos
{
    int x;
    int y;
} que[10000000];
bool in[MAXN][MAXN];
int main()
{
    scanf("%d%d", &n, &m);
    scanf("%d%d", &x1, &y1);
    scanf("%d%d", &x2, &y2);
    getchar();
    char ch;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            ch = getchar();
            hit[i][j] = ch-'0';
            dis[i][j] = INF;
        }
        getchar();
    }
    dis[x1][y1] = 1;
    int bg = 0;
    int ed = 0;
    int posx, posy;
    int nxtx, nxty;
    int nowhit, nxthit;
    const int BIG = 25000;
    que[bg].x = x1;
    que[bg].y = y1;
    int flag;
    while (bg <= ed)
    {
        posx = que[bg].x;
        posy = que[bg++].y;
        in[posx][posy] = false;
        nowhit = hit[posx][posy];
        for (int i = 0; i < 8; i++)
        {
            nxtx = posx+dx[i];
            nxty = posy+dy[i];
            nxthit = hit[nxtx][nxty];
            if (nxthit)
            {
                flag = nxthit;
                if (nxthit != nowhit && dis[nxtx][nxty] > dis[posx][posy]+BIG+1)
                {
                    dis[nxtx][nxty] = dis[posx][posy]+BIG+1;
                    if (!in[nxtx][nxty])
                    {
                        que[++ed].x = nxtx;
                        que[ed].y = nxty;
                        in[nxtx][nxty] = true;
                    }
                }
                else if (nxthit == nowhit)
                {
                    if (dis[nxtx][nxty] > dis[posx][posy]+1)
                    {
                        dis[nxtx][nxty] = dis[posx][posy]+1;
                        if (!in[nxtx][nxty])
                        {
                            que[++ed].x = nxtx;
                            que[ed].y = nxty;
                            in[nxtx][nxty] = true;
                        }
                    }
                }
            }
        }
    }
    if (dis[x2][y2] != INF)
        printf("%d %d", dis[x2][y2] % BIG, dis[x2][y2]/ BIG);
    else
        printf("0 0");
    return 0;
}
*/
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 505;
const int INF = 19940306;
const int BIG = 25000;
const int dx[8] = {1,1, 1,-1,-1,-1,0, 0};
const int dy[8] = {0,1,-1, 1, 0,-1,1,-1};
int dis[MAXN][MAXN];
int hit[MAXN][MAXN];
int handle[MAXN][MAXN];

struct point
{
    int x;
    int y;
} heap[MAXN*MAXN];
int size = 1;
inline void exchange(int a, int b)
{
    int tmp;
    tmp = handle[heap[a].x][heap[a].y];
    handle[heap[a].x][heap[a].y] = handle[heap[b].x][heap[b].y];
    handle[heap[b].x][heap[b].y] = tmp;
    swap(heap[a],heap[b]);
}
inline void heapfy(int index)
{
    int left = index<<1;
    int right = left+1;
    int mini = index;
    if (left <= size && dis[heap[left].x][heap[left].y] < dis[heap[mini].x][heap[mini].y])
        mini = left;
    if (right <= size && dis[heap[right].x][heap[right].y] < dis[heap[mini].x][heap[mini].y])
        mini = right;
    if (mini != index)
    {
        exchange(mini, index);
        heapfy(mini);
    }
}
inline point extract()
{
    point res = heap[1];
    exchange(1, size--);
    heapfy(1);
    return res;
}
inline void decrease(int x, int y, int num)
{
    dis[x][y] = num;
    int id = handle[x][y];
    int fa = id >> 1;
    while (id > 1 && dis[heap[fa].x][heap[fa].y] > dis[heap[id].x][heap[id].y])
    {
        exchange(id, fa);
        id = fa;
        fa = id >> 1;
    }
}
int n, m;
int x1, y1;
int x2, y2;
int main()
{
    cin >> n >> m;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin.get();
    char ch;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin.get(ch);
            hit[i][j] = ch-'0';
            dis[i][j] = INF;
            if (hit[i][j] && (i != x1 || j !=  y1))
            {
                heap[++size].x = i;
                heap[size].y = j;
                handle[i][j] = size;
            }
        }
        cin.get();
    }
    heap[1].x = x1;
    heap[1].y = y1;
    dis[x1][y1] = 1;
    handle[x1][y1] = 1;
    point now;
    int nowx, nowy;
    int nxtx, nxty;
    int nowhit;
    int nxthit;
    int tmp;
    while (size)
    {
        now = extract();
        if (now.x == x2 && now.y == y2)
            break;
        nowx = now.x;
        nowy = now.y;
        nowhit = hit[nowx][nowy];
        for (int i = 0; i < 8; ++i)
        {
            nxtx = nowx+dx[i];
            nxty = nowy+dy[i];
            nxthit = hit[nxtx][nxty];
            if (nxthit)
            {
                if (nxthit != nowhit && dis[nxtx][nxty] > (tmp = dis[nowx][nowy]+BIG+1))
                    decrease(nxtx, nxty, tmp);
                else if (nxthit == nowhit && dis[nxtx][nxty] > (tmp = dis[nowx][nowy]+1))
                    decrease(nxtx, nxty, tmp);
            }
        }
    }
    if (dis[x2][y2] == INF)
        cout << "0 0";
    else
        cout << dis[x2][y2]%BIG << ' ' << dis[x2][y2]/BIG;
    return 0;
}
/*
sample input
3 7
1 1
3 7
2100212
2121010
2221012

sample output
8 4
*/
