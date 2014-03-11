/*
    ID : jake1994
    PROG : milk4
    LANG : C++
*/
#include<stdio.h>
#include<string.h>
#include<cstdlib>
#include<iostream>
using namespace std;
const int maxn=10001;
const int maxm=101;
int a[maxm],b[maxm];
bool f[maxn],g[maxn];
int n,m,i,j,k;
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
bool work1(int x)//记忆化部分 
{
     if(g[x])
        return f[x];
     g[x]=1;
     for(int i=0;i<k;i++)
        if(x>=b[i]&&work1(x-b[i]))
            return f[x]=1;
     return f[x]=0;
}
void init()
{
     cin>>n>>m;
     for(i=0;i<m;i++)
        cin>>a[i];
     qsort(a,m,sizeof(a[0]),cmp);
}
void dfsid(int dep,int tot)
{
    if (tot==k)
    {
        memset(g,0,sizeof(g));
        f[0]=g[0]=1;
        if (work1(n))
        {
            printf("%d",k);
            for(i=0;i<k;i++)
                printf(" %d",b[i]);
            printf("\n");
            exit(0);
        }
        return;
    }
    if(dep>=m)
        return;
    b[tot]=a[dep];
    dfsid(dep+1,tot+1);
    dfsid(dep+1,tot);
}
void work()
{
    for(k=1;k<=m;k++)
        dfsid(0,0);
}
int main()
{
    freopen("milk4.in","r",stdin);
    freopen("milk4.out","w",stdout);
    init();
    work();
    return 0;
}
