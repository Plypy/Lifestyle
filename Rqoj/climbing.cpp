//二维装箱问题 
#include <iostream>
#include <string.h>
using namespace std;
const int MAXL=21,MAXM=80;
int f[MAXM][MAXL],t,a,n;
int main()
{
    memset (f,0xff,sizeof (f));
    f[0][0]=0;
    scanf ("%d%d%d",&t,&a,&n);
    int ti,ai,wi,x,y;
    for (int i=1;i<=n;i++)
    {
        scanf ("%d%d%d",&ti,&ai,&wi);
        for (int i=a;i>=0;i--)
            for (int j=t;j>=0;j--)
            {
                x=min(i+ai,a),y=min(j+ti,t);
                if (f[i][j]!=-1)
                   if (f[x][y]==-1 || f[x][y]>f[i][j]+wi)
                      f[x][y]=f[i][j]+wi;
            }
        }
    printf ("%d",f[a][t]);
    return 0;
}
