#include <iostream>
using namespace std;
int wtree[200];
int wit[2001];
int R_s[101];
int plot[2001];
int que[2001];
int n, m;
int find();
void fix(int s);
void init();
int bg, ed;
int main()
{
    scanf("%d%d",&n,&m);
    int i;
    for (i = 1; i <= n; i++)
        scanf("%d",R_s+i);
    for (i = 1; i <= m; i++)
        scanf("%d",wit+i);
    int num = 0, t, tmp;
    int ans = 0;
    init();
    while (num < m)
    {
        scanf("%d",&t);
        if (t>0)
        {
            if (tmp = wtree[1])
            {
                fix(tmp);
                plot[t] = tmp;
                ans += R_s[tmp]*wit[t];
                num++;
            }
            else
                que[++ed] = t;
        }
        else
        {
            t = -t;
            if (ed-bg>0)
            {
                tmp = que[++bg];
                plot[tmp] = plot[t];
                ans += R_s[plot[tmp]]*wit[tmp];
                num++;
            }
            else
                fix(plot[t]);
        }
    }
    cout << ans;
    return 0;
}
void fix(int s)
{
    int i = s+n-1;
    int f, m;
    if (wtree[i])
        wtree[i]=0;
    else
        wtree[i]=s;
    for (i>>=1; i > 0;i>>=1)
    {
        f = wtree[i<<1];
        m = wtree[(i<<1)+1];
        if (f&&m)
            wtree[i]=min(f,m);
        else if(f)
            wtree[i]=f;
        else if(m)
            wtree[i]=m;
        else
            wtree[i]=0;
    }
}
void init()
{
int j;
for (j = 1; j <= n; j++)
    fix(j);
}
