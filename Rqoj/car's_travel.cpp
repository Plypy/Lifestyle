#include <iostream>
#include <limits.h> 
#include <math.h>
#include <stdlib.h>
const int Max = 410;
using namespace std;
double dist(double,double,double,double);
struct pos
{
    double x,y;
};
int main()
{
    int n;
    cin >>n;
    while(n)
    {
        --n;
        int s,t,a,b,p[Max];
        cin >>s>>t>>a>>b;
        pos g[Max];
        int ct = 0;
        for(int k=1;k<=s; k++)//读入每个城市的机场坐标 
        {
            cin >>g[++ct].x>>g[ct].y>>g[++ct].x>>g[ct].y>>g[++ct].x>>g[ct].y>>p[k];
            bool flag=false;
            for(int i=ct-2;i<=ct;i++)//算出第四个点 
            {
                for(int j=ct-2;j<=ct;j++)
                {
                    int mid=3*ct-3-i-j;
                    if(i!=j && (g[i].x-g[mid].x)*(g[j].x-g[mid].x) + (g[i].y-g[mid].y) * (g[j].y-g[mid].y) == 0)
                    {
                        g[++ct].x=g[i].x+g[j].x-g[mid].x;
                        g[ct].y=g[i].y+g[j].y-g[mid].y;
                        flag=true;
                        break;
                    }
                }
				if(flag)
					break;
            }
        }
        //建图，计算出每个点之间的花费...后面直接用floyd解了....有点浪费....不过考虑到此题的数据规模
        //以及程序设计的复杂性，不失为一种好的解题方法。 
        double cost[Max][Max]={0};
        for(long i=1;i<=ct;i++)
            for(long j=1;j<=ct;j++)
                if(i!=j)//判断是否为同一个机场 
                {
                    if(ceil(double(i)/double(4))==ceil(double(j)/double(4)))//判断是否在同一个城市 
                    {
                        cost[i][j]=dist(g[i].x,g[i].y,g[j].x,g[j].y)*p[(long)ceil(double(i)/double(4))];
                        cost[j][i]=cost[i][j];
                    }
                    else
                    {
                        cost[i][j]=dist(g[i].x,g[i].y,g[j].x,g[j].y)*t;
                        cost[j][i]=cost[i][j];
                    }
                }
        //一次O(V^3)的Floyd过程 
        for(long k=1;k<=ct;k++)
           for(long i=1;i<=ct;i++)
               for(long j=1;j<=ct;j++)
                   if(i!=j&&j!=k&&k!=i&&cost[i][k]+cost[k][j]<cost[i][j])
                       cost[i][j]=cost[i][k]+cost[k][j];
        //Calculate the cheapest cost between the two cities.
       double ans=LONG_MAX;
       for(long i=a*4-3;i<=a*4;i++)
           for(long j=b*4-3;j<=b*4;j++)
               ans=min(ans,cost[i][j]);
       printf("%.1f",ans);
    }
    return 0;
}
double dist(double x1,double y1,double x2,double y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
};
/*
1
3 10 1 3
1 1 1 3 3 1 30
2 5 7 4 5 2 1
8 6 8 8 11 6 3

47.55
*/
/*
Note
    解这道题的时候主要是考虑到了题目的数据规模不是特别大于是采用了邻接表方式建图
    然后使用设计思路简单的Floyd进行计算，尽量保证题解的正确性
    最后这道题也使用了降维的思路，即将原来的每个城市中的一个机场这个二维数据下降 
    转换成了一个一维数据只记录机场序号，然后通过机场序号算出城市序号，简化了程序
    设计的复杂性，以后要记住降维，其余的降维的常见情况还有动态规划中的背包问题把
    物品个数消掉的做法
*/ 
