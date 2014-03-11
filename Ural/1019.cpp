//离散化即可
//俺第一次写离散化 hoho 
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
const int MAXN = 5005;
struct point
{
    int x, type, id;
    point(int _x = 0, int _type = 0, int _id = 0):
        x(_x), type(_type), id(_id){ }
} pt[MAXN<<1];
bool color[MAXN];
int n;
void load()
{
    cin >> n;
    ++n;
    color[1] = false;
    pt[1] = point(0,0,1);
    pt[2] = point(1000000000,1,1);
    int st, ed;
    char col;
    for (int i = 2; i <= n; ++i)
    {
        cin >> st >> ed >> col;
        pt[(i<<1)-1] = point(st,0,i);
        pt[i<<1] = point(ed,1,i);
        color[i] = col == 'b';
    }
}
int cmp(const void *a, const void *b)
{
    return ((point *)a)->x - ((point *)b)->x;
}
bool vcol[MAXN<<1];
int seg[MAXN][2];
int cord[MAXN<<1];
int ct;
void work()
{
    qsort(pt+1, n*2, sizeof(point), cmp);
    cord[++ct] = pt[1].x;
    seg[pt[1].id][pt[1].type] = ct;
    for (int i = 2; i <= n*2; ++i)
    {
        if (pt[i].x != pt[i-1].x)
        {
            cord[++ct] = pt[i].x;
        }
        seg[pt[i].id][pt[i].type] = ct;
    }
    for (int i = 1; i <= n; ++i)
    {
        bool tcol = color[i];
        for (int j = seg[i][0]+1; j <= seg[i][1]; ++j)
            vcol[j] = tcol;
    }
    vcol[++ct] = true;
    int tlen = 0, mlen = 0, ed;
    for (int i = 1; i <= ct; ++i)
    {
        if (!vcol[i])
        {
            tlen += cord[i]-cord[i-1];
        }
        else
        {
            if (tlen > mlen)
            {
                mlen = tlen;
                ed = cord[i-1];
            }
            tlen = 0;
        }
    }
    cout << ed-mlen << ' ' << ed << endl;
}
int main()
{
    load();
    work();
    //system("pause");
    return 0;
}
