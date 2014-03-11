// binary search tree
#include <stdio.h>
#include <string.h>
const int MAXN=100,inf=0x3f3f3f3f;
int n,KK,ans;int a[MAXN],v[MAXN],p[MAXN],sum[MAXN][MAXN],vk[MAXN];
int d[MAXN][MAXN][MAXN];
#define swap(a,b) { int tmp=a; a=b; b=tmp; }
int MIN(int a,int b){ return a<b?a:b; }
void qsort(int s,int t)
{
    int i=s,j=t,x=a[i+j>>1]; 
    while(i<=j)
    {  
        while(a[i]<x) 
            ++i;  
        while(a[j]>x) 
            --j;  
        if(i<=j)
        {   
            swap(a[i],a[j]); 
            swap(v[i],v[j]); 
            swap(p[i],p[j]);   
            ++i; 
            --j;  
        } 
    } 
    if(s<j) 
        qsort(s,j); 
    if(i<t)    
        qsort(i,t);
}
void qsort_vk(int s,int t)
{ 
    int i=s,j=t,x=vk[i+j>>1]; 
    while(i<=j)
    {  
        while(vk[i]<x) 
            ++i;  
        while(vk[j]>x) 
            --j;  
        if(i<=j)
        {   
            swap(vk[i],vk[j]);   
            ++i; 
            --j;  
        } 
    } 
    if(s<j) 
    qsort_vk(s,j); 
    if(i<t) qsort_vk(i,t);
}
void ini()
{ 
    scanf("%d%d",&n,&KK); 
        for(int i=1;i<=n;++i) 
        scanf("%d",&a[i]); 
    for(int i=1;i<=n;++i) 
        scanf("%d",&v[i]); 
    for(int i=1;i<=n;++i) 
        scanf("%d",&p[i]); 
    for(int i=1;i<=n;++i) 
        vk[i]=v[i]; 
    qsort_vk(1,n); 
    for(int i=1;i<=n;++i)  
        for(int j=1;j<=n;++j)   
            if(v[i]==vk[j]) 
                v[i]=j; 
    qsort(1,n); 
    for(int j=1;j<=n;++j) 
        sum[1][j]=sum[1][j-1]+p[j]; 
    for(int i=2;i<=n;++i) 
        for(int j=i;j<=n;++j) 
            sum[i][j]=sum[1][j]-sum[1][i-1];
}
void solve()
{ 
    memset(d,0x3f,sizeof(d)); 
    for(int i=0;i<=n;++i)  
        for(int k=0;k<=n;++k)   
            d[i+1][i][k]=0; 
    for(int len=0;len<n;++len)  
        for(int i=1;i<=n-len;++i)
        {   
            int j=i+len;   
            for(int m=i;m<=j;++m)
            {    
                for(int k=0;k<=v[m];++k)     
                    d[i][j][k]=MIN(d[i][j][k],d[i][m-1][v[m]]+d[m+1][j][v[m]]+sum[i][j]);    
                for(int k=0;k<=n;++k)     
                    d[i][j][k]=MIN(d[i][j][k],d[i][m-1][k]+d[m+1][j][k]+KK+sum[i][j]);   
            }  
        } 
    ans=inf; 
    for(int k=0;k<=n;++k) 
        ans=MIN(ans,d[1][n][k]);
}
int main()
{
    ini(); 
    solve(); 
    printf("%d\n",ans);
    return 0;
}
