// 标准的±1 RMQ问题， - -可惜我从来没写过
// 单调队列搞一搞 
#include <cstdio>
#include <cstdlib>
int n,m,a,l=1,r=1,Q[25001]={0},pos[25001]={0};
int main()
{
    scanf("%d",&m);
    for (int i=1;;++i)
    {
        scanf("%d",&a);
        if (a == -1)  break;
        while ((l <= r) && (i-pos[l] >= m))
            ++l;
        while ((r >= l) && (Q[r] < a))
            --r;
        Q[++r]=a;
        pos[r]=i;
        if (i >= m)
            printf("%d\n",Q[l]);
    }
    return 0;
} 
