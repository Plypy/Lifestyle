#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#define inf INT_MAX
using namespace std;

const int max = 30005;

int wtree[max*2], n;

inline int min(int a, int b)
{   return a<b?a:b;}

inline void wt_init()
{
    for (int i = n; i >0 ; i--)
        wtree[i] = min(wtree[i<<1],wtree[(i<<1)+1]);
}

inline int wt_top()
{
    int i;
    for (i = 1; i < n;)
        if (wtree[i] == wtree[i<<1])
            i <<= 1;
        else
            i = (i << 1)+1;
    return i-n+1;
}
inline void wt_fix(int id, int value)
{
    int i;
    wtree[i = id +n -1] = value;
    for (i >>= 1; i >0; i>>=1)
        wtree[i] = min(wtree[i<<1],wtree[(i<<1)+1]);
}

inline int wt_get(int id)
{
    return wtree[id+n-1];
}

int r[max], matr;
int g[max][11],
    l[max][11],
    d[max][11];

int queue[max],
    used[max],
    total;

int in();
void play();
void init();
void process();

int main()
{
    freopen(stdin,"servers.in");
    freopen(stdout,"servers.out");
    while (in())
        play();
    sysytem("pause");
    return 0;
}

int in()
{
    int m, i;
    cin >> n >> m;
    if (cin.fail())
        return false;
    
    for (maxr = 0, i = 1; i <= n; i++)
    {
        cin >> r[i];
        maxr >?= r[i];
        g[i][0] = l[i][0] = used[i] = 0;
        wt_fix(i, inf);
    }
    
    for (int i = 1; i <= m ; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;
        g[x][++g[x][0]] = y, l[x][++l[x][0]] = c;
        g[y][++g[y][0]] = x, l[y][++l[y][0]] = c;
    }
    
    return true;
}

void play()
{
    init();
    process();
}

void init()
{
    int i, j, k;
    for (i = 1; i <= 10; i++)
    {
        for (queue[0] = 0, j = 1; j <= n; d[j++][i] = inf)
            if (r[j] == i)
            {
                wt_fix(j,0);
                queue[++queue[0]] = j;
            }
        while (1)
        {
            int id = wt_top();
            if (used[id] || wt_get(id) == inf)
                break;
            uesd[id]=1;
            d[id][i] = wt_get(id);
            queue[++queue[0]] = id;
            for (j = 1; j <= g[id][0]; j++)
                if (!used[k]=g[id][j] && wt_get(k) > d[id][i] + l[id][j])
                    wt_fix(k, d[id][i]+l[id][j]);
            wt_fix(id, inf);
        }
        
        for (j = 1; j <= queue[0]; j++)
            used[queue[j]] = 0;
    }
    
    for (i = 1; i <= n; i++)
        for (j = 9; j >= 1; j--)
            d[i][j] >?= d[i][j+1];
}

void proess()
{
    int i, j, k;
    for (total = 0, i = 1; i <= n; i++)
        if (r[i] == maxr)
            total += n;
        else
        {
            queue[queue[0] = 1] = i;
            wt_fix(i,0);
            
            while (1)
            {
                int id = wt_top();
                if (used[id] || wt_get(id) == inf)
                    break;
                used[id] = 1, queue[++queue[0]] = id;
                if (d[id][r[i]+1] <= wt_get(id))
                {
                    wt_fix(id, inf)
                    continue;
                }
                total++;
                for (j = 1; j <= g[id][0];j++)
                    if (!used[k=g[id][j]] && wt_get(k) > wt_get(id)+l[id][j])
                        wt_fix(k, wt_get(id)+l[id][j]);
                wt_fix(id, inf);
            }
            for (j = 1; j <= queue[0]; j++)
                used[queue[j]] = 0;
        }
    cout << total << endl;
}
