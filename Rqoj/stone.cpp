#include <iostream>
#include <cstdlib>
#include <climits>
using namespace std;
const int L=101,P=10001;
int stone[L],f[P];
int n,s,t,m,p,ans;
int cmp(const void *a,const void *b)
{
    return *(int *)a < *(int *)b ? -1 : 1;
}

void solve()
{
    p=s*t,stone[++m]=n;
    for (int i=1,k;i<=m;i++)
    {
        if (stone[i]-stone[i-1]>p)
        {
            k=stone[i]-stone[i-1]-p;
            for (int j=i;j<=m;j++)
                stone[j]-=k;
            stone[i]=stone[i-1]+p;
        }
        f[stone[i]]=1;
    }
    n=stone[m];
    for (int i=1,minn;i<n+t;i++)
    {
        minn=INT_MAX;
        for (int j=s;j<=t;j++)
             if (i-j>=0&&f[i-j]<minn)
                minn=f[i-j];
        f[i]+=minn;
        }
    }

int main()
{
    cin >> n >> s >> t >> m;
    for (int i=1;i<=m;i++)
        cin >> stone[i];
    qsort(stone+1,m,sizeof(int),cmp);
    if (s==t)
    {
        for (int i=1;i<=m;i++)
            if (stone[i]%s==0)
                ans++;
    }
    else
    {
         solve();
         ans=INT_MAX;
         for (int i=n+1; i < n+t; i++)
             if (f[i]<ans)
                ans=f[i];
    }
    cout << ans;
    return 0;
}
