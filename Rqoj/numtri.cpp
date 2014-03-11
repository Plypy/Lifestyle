/*
        ID: jake1994
        PROG: numtri
        LANG: C++
*/
#include<stdio.h>
long max(long a,long b)
{
     if(a>b)return a;else return b;
}
long a[1000][1000];
int main()
{
    long i,j,n;
    freopen("numtri.in","r",stdin);freopen("numtri.out","w",stdout);
    scanf("%ld",&n);
    for(i=0;i<n;i++)
       for(j=0;j<=i;j++)
           scanf("%ld",&a[i][j]);
    for(i=n-2;i>=0;i--)
        for(j=0;j<=i;j++)
            a[i][j]+=max(a[i+1][j],a[i+1][j+1]);
    printf("%ld\n",a[0][0]);
    return 0;
}
