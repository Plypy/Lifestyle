#include <iostream>
#include <limits.h>
#include <string.h>
using namespace std;
const int MAXN = 100001;
struct edge
{
    edge *next;
    int key;
    edge():next(0),key(0){}
    edge(int _key, edge*_next):next(_next),key(_key){}
} v[MAXN], *p[MAXN], vt[MAXN], *pt[MAXN];
int n, m;
int val[MAXN];
int buy[MAXN];
int sell[MAXN];
int que[MAXN*10];
bool in[MAXN];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        buy[i] = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        p[i] = v+i;
        pt[i] = vt+i;
    }
    for (int i = 1; i <= n; i++)
        scanf("%d", val+i);
    int x, y, z;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &x, &y, &z);
        if (z==1)
        {
            p[x]->next = new edge(y,p[x]->next);
            pt[y]->next = new edge(x,pt[y]->next);
        }
        else
        {
            p[x]->next = new edge(y,p[x]->next);
            pt[x]->next = new edge(y,pt[x]->next);
            pt[y]->next = new edge(x,pt[y]->next);
            p[y]->next = new edge(x,p[y]->next);
        }
    }
    int bg, ed;
    bg = ed = 0;
    que[0] = 1;
    in[1] = true;
    buy[1] = val[1];
    int tmp;
    int num;
    while (bg <= ed)
    {
        tmp = que[bg++];
        in[tmp] = false;
        for (edge *t = p[tmp]->next; t; t = t->next)
        {
            num = min(buy[tmp],val[t->key]);
            if (buy[t->key] > num)
            {
                buy[t->key] = num;
                if (!in[t->key])
                {
                    que[++ed] = t->key;
                    in[t->key] = true;
                }
            }
        }
    }
    memset(que,0,sizeof(que));
    memset(in,0,sizeof(in));
    bg = ed = 0;
    que[0] = n;
    in[n] = true;
    sell[n] = val[n];
    while (bg <= ed)
    {
        tmp = que[bg++];
        in[tmp] = false;
        for (edge*t = pt[tmp]->next; t; t = t->next)
        {
            num = max(sell[tmp],val[t->key]);
            if (sell[t->key] < num)
            {
                sell[t->key] = num;
                if (!in[t->key])
                {
                    que[++ed] = t->key;
                    in[t->key] = true;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans >?= sell[i]-buy[i];
    cout << ans;
    return 0;
}
