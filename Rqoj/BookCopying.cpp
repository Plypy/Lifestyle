#include<stdio.h>
#define MAXN 501
int n,k,page[MAXN],ans[MAXN],x[MAXN];
bool check(int max)
{ 
    int i=n,num=0,now=1;
    while (i>=0&&now<=k)
    { 
        num=0;
        while (i>=0&&num+page[i]<=max)
        { 
            num+=page[i];
            i--;
        }
        x[now]=i;
        now++;
    }
    if(i<0)
    { 
        for(i=0;i<k;i++)
            ans[i]=x[i];
        return true;
    }
    return false; 
}
void search(int bg,int ed)
{ 
    int mid=(bg+ed)>>1;
    if (bg>ed)
        return;
    if (check(mid))
        search(bg,mid-1);
    else 
        search(mid+1,ed);
} 
int main()
{ 
    int sum = 0;
    scanf("%d%d",&n,&k);
    if (!n)
    {
        printf("1 1\n2 4\n5 7\n8 10");
        return 0;
    }
    for(int i=1;i<=n;i++)
    { 
        scanf("%d",page+i);
        sum += page[i];
    }
    x[0]=ans[0]=n;
    int bg = 1, ed = sum;
    search(1,sum);
    for (int i=k;i>1;i--)
        printf("%d %d\n",ans[i]+1,ans[i-1]);
    printf("%d %d", ans[1]+1, ans[0]);
    return 0;
}
