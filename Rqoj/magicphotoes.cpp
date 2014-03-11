#include <stdio.h>
#include <stdlib.h>
struct dat
{ 
    int h, w;
} W[50001];
long n, k, E[11], i;
int cmp(const void *p, const void *q) 
{
    return ((*(dat*)q).w-(*(dat*)p).w)==0? ((*(dat*)p).h-(*(dat*)q).h):
           ((*(dat*)q).w-(*(dat*)p).w);
}
int main()
{
    scanf("%ld %ld", &n, &k);
    for(i=1; i<=10; ++i) 
        scanf("%ld", &E[i]);
    for(i=1; i<=n; ++i) 
        W[i].h=i, scanf("%ld", &W[i].w);
    qsort(&W[1], n+1, sizeof(dat), cmp);
    for(i=1; i<=n; ++i) W[i].w+=E[(i-1)%10+1];
    qsort(&W[1], n+1, sizeof(dat), cmp);
    for(i=1; i<=k; ++i) 
        printf("%ld ", W[i].h);
    return 0;
}
