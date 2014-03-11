/* Note:
 *      并查集实现
 *      标准模板～ 
 */
#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 5005;
int f[MAXN];
int d[MAXN];
inline int get(int n)
{ 
    int t;
    if(f[n]==n)
        return n;
    t=get(f[n]);
    d[n] += d[f[n]];
    f[n]=t;
    return t;
}
int main()
{ 
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        f[i]=i;
    int l,r,x,fl,fr;
    for(int i=1;i<=m;i++)
    { 
        scanf("%d%d%d",&l,&r,&x);
        fl=get(l-1);
        fr=get(r);
        if(fl!=fr)
        { 
            f[fr]=fl;
            d[fr]=d[l-1]+x-d[r];
        }
    }
    for(int i=1;i<=k;i++)
    { 
        scanf("%d%d",&l,&r);
        if(get(l-1)!=get(r))
            printf("UNKNOWN\n");
        else 
            printf("%d\n",d[r]-d[l-1]);
    }
    return 0;
}
/*
10 5 5
1 5 4
2 5 4
3 6 5
1 9 9
6 6 2
1 9
2 6
1 2
3 5
1 7

9
6
1
3
UNKNOWN
*/
