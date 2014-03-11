#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int MAXN = 30001;
int ar[MAXN];
const int MAXM = 201;
int ct[MAXM];
int n,w;
void load()
{
    scanf("%d%d",&w,&n);
    int t;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &t);
        ++ct[t];
    }
    int pt = 5;
    for (int i = 1; i <= n; i++)
    {
        while (!ct[pt])
            ++pt;
        ar[i] = pt;
        --ct[pt];
    }
}
int ans;
void work()
{
    int bot = 1, top = n;
    //for (int i = 1; i <= n; i++)
    //    printf("%d ", ar[i]);
    //putchar('\n');
    while (bot < top)
    {
        ++ans;
        if (ar[bot]+ar[top]<=w)
        {
            ++bot;
            --top;
        }
        else
            --top;
    }
    if (bot == top)
        ++ans;
    printf("%d", ans);
    //system("pause");
}
int main()
{
    load();
    work();
    return 0;
}
