#include <cstdlib>
#include <iostream>
using namespace std;
const int MAXN = 1000001;
const int MAXM = 1001;
int n,m,r,f[MAXN],t;
struct p
{
    int bg,ed,v;
}a[MAXM];
int cmp(const void *a,const void *b)
{   return ((p*)a)->bg - ((p*)b)->bg;}
int main()
{
    scanf("%d%d%d",&n,&m,&r);
    t=0;
    for (int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&a[i].bg,&a[i].ed,&a[i].v);
        a[i].ed += r;
        if (t < a[i].ed)
            t = a[i].ed;
    }
    qsort(a+1, m, sizeof(p), cmp);
    int j = 1;
    for (int i=0;i<=t;i++)
    {
        while ((j<=m)&&(a[j].bg<i)) 
            j++;
        if ((i)&&(f[i]<f[i-1])) 
            f[i]=f[i-1];
        while ((j<=m)&&(a[j].bg==i))
        {
            if (f[a[j].ed]<f[a[j].bg]+a[j].v)
                f[a[j].ed]=f[a[j].bg]+a[j].v;
            j++;
        }
    }
    printf("%d", f[t]);
    return 0;
}

