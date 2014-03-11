#include<stdio.h>
#include<math.h>
int ans;
int list[20001],sum, n;
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i) 
    {
        scanf("%d",list+i);
        sum += list[i];
    }
    for (int i=1;i<n;++i)
        if (list[i]+list[i+1]>ans) 
            ans=list[i]+list[i+1];
    double mm=sum,nn=n,tmp;
    tmp=ceil(mm/((int)(nn/2)));
    if ((int)tmp>ans) 
        ans=(int)tmp;
    printf("%d",ans);
    return 0;
}

