#include<cstdio>
#include<cstring>
#include<algorithm>
const int MOD=1000000007,N=100005;
int n,m,q,cnt,x,y,a[N],c[N],r[N],f[N],g[N];
bool b[N];
int main() {
    scanf("%d%d%d",&n,&q,&m),f[0]=1;
    for (int i=1; i<=n; i++) scanf("%d",a+i);
    for (int i=1; i<=q; i++) scanf("%d%d",&x,&y),c[x]=y,r[y]=1;

    for (int i=1; i<=n; i++)
        if (!b[i] && !r[i]) {
            int j=i,L=0;
            long long res=0;
            while (j && !b[j])
                b[j]=1,g[++L]=a[j],j=c[j];
            cnt+=L;
            for (j=1; j<L; j++)
                g[j+1]+=g[j],res+=g[j];
            if (res>m)
                return puts("0");
            for (j=m; j>m-res; j--)
                f[j]=0;
            for (j=m; j>=res; j--)
                f[j]=f[j-res];
            for (j=0; j<res; j++)
                f[j]=0;
            for (j=1; j<=L; j++)
                for (int k=g[j]; k<=m; k++)
                    f[k]=(f[k]+f[k-g[j]])%MOD;
        }
    printf("%d\n",cnt<n?0:f[m]);
    return 0;
}
