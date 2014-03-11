/**
 * Description: CF Round#35 C
 * Author: Ply_py
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iomanip>
#include <queue>
#include <cmath>
using namespace std;
using namespace std;
int n,m,p,x[20],y[20],ax,ay,ans=-1;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    while (cin >> n >> m >> p) {
//        scanf("%d%d%d",&n,&m,&p);
        ans = -1;
        for(int i=0;i<p;i++)scanf("%d%d",x+i,y+i);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                int T=n+m;
                for(int k=0;k<p;k++)T=min(T,abs(i-x[k])+abs(j-y[k]));
                if(T>ans)
                    ans=T,ax=i,ay=j;
            }
        printf("%d %d\n",ax,ay);
    }
    return 0;
}
