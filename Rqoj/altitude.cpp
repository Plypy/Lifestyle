#include <iostream>
#include <cstdio>
#include <climits>
#include <cfloat>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <list>
#include <set>
#include <map>
#include <cassert>
#include <vector>
#include <string>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <bitset>
#include <cmath>
#include <new>
#include <cerrno>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <ctime>
#include <cwchar>
#include <cwctype>
#include <ciso646>
#include <iterator>
#include <numeric>
#include <memory>
#include <typeinfo>
#include <functional>
#include <exception>
#include <stdexcept>
#include <utility>
#include <queue>
#include <stack>
#include <complex>
#include <clocale>
#include <ios>
#include <iosfwd>
#include <istream>
#include <locale>
#include <ostream>
#include <streambuf>
#include <valarray>
#include <ext/hash_set>
#include <ext/hash_map>
/*------------------------------Ballache Cut Line-----------------------------*/

using namespace std;
const int MAXN = 505;
const int UP = 0;
const int DOWN = 1;
const int LEFT = 2;
const int RIGHT = 3;
const int INF = 52111425;
const int FLAG = MAXN-1;
struct pos
{
    int x, y;
    int dis;
} heap[MAXN*MAXN];
int cost[MAXN][MAXN][4];
int handle[MAXN][MAXN];
int n;
int size;
void exch(int a, int b)
{
    swap(handle[heap[a].x][heap[a].y], handle[heap[b].x][heap[b].y]);
    swap(heap[a],heap[b]);
}
void heapfy(int i)
{
    int l, r;
    int mi;
    while (1)
    {
        l = i << 1;
        r = l+1;
        mi = i;
        if (l <= size && heap[mi].dis > heap[l].dis)
            mi = l;
        if (r <= size && heap[mi].dis > heap[r].dis)
            mi = r;
        if (mi != i)
        {
            exch(mi,i);
            i = mi;
        }
        else
            break;
    }
}
void dec(int x, int y, int amt)
{
    int id = handle[x][y];
    heap[id].dis = amt;
    while (id > 1 && heap[id].dis < heap[id>>1].dis)
    {
        exch(id, id>>1);
        id >>= 1;
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            heap[++size].x = i;
            heap[size].y = j;
            heap[size].dis = INF;
            handle[i][j] = size;
        }
    ++size;
    heap[size].x = FLAG;
    heap[size].y = FLAG;
    heap[size].dis = INF;
    handle[FLAG][FLAG] = size;
    
    int tmp;
    for (int i = 0; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &tmp);
            cost[i][j][DOWN] = tmp;
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n+1; j++)
        {
            scanf("%d", &tmp);
            cost[i][j][LEFT] = tmp;
        }
    for (int i = 1; i <= n+1; i++)
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &tmp);
            cost[i][j][UP] = tmp;
        }
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= n; j++)
        {
            scanf("%d", &tmp);
            cost[i][j][RIGHT] = tmp;
        }
    for (int i = 1; i <= n; i++)
        if (heap[handle[1][i]].dis > (tmp = cost[0][i][DOWN]))
            dec(1,i,tmp);
    for (int i = 1; i <= n; i++)
        if (heap[handle[i][n]].dis > (tmp = cost[i][n+1][LEFT]))
            dec(i,n,tmp);
    int dis;
    int posx;
    int posy;
    while (1)
    {
        if (FLAG == heap[1].x)
            break;
        posx = heap[1].x;
        posy = heap[1].y;
        dis = heap[1].dis;
        exch(1, size--);
        heapfy(1);
        if (1 != posx && heap[handle[posx-1][posy]].dis > (tmp = dis+cost[posx][posy][UP]))
            dec(posx-1, posy, tmp);
        if (n == posx && heap[handle[FLAG][FLAG]].dis > (tmp = dis+cost[posx][posy][DOWN]))
            dec(FLAG,FLAG,tmp);
        else if (heap[handle[posx+1][posy]].dis > (tmp = dis+cost[posx][posy][DOWN]))
            dec(posx+1,posy,tmp);
        if (n != posy && heap[handle[posx][posy+1]].dis > (tmp = dis+cost[posx][posy][RIGHT]))
            dec(posx,posy+1,tmp);
        if (1 == posy && heap[handle[FLAG][FLAG]].dis > (tmp = dis+cost[posx][posy][LEFT]))
            dec(FLAG,FLAG,tmp);
        else if (heap[handle[posx][posy-1]].dis > (tmp = dis+cost[posx][posy][LEFT]))
            dec(posx,posy-1,tmp);
    }
    printf("%d", heap[1].dis);
    return 0;
}
