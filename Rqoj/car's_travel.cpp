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
        for(int k=1;k<=s; k++)//����ÿ�����еĻ������� 
        {
            cin >>g[++ct].x>>g[ct].y>>g[++ct].x>>g[ct].y>>g[++ct].x>>g[ct].y>>p[k];
            bool flag=false;
            for(int i=ct-2;i<=ct;i++)//������ĸ��� 
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
        //��ͼ�������ÿ����֮��Ļ���...����ֱ����floyd����....�е��˷�....�������ǵ���������ݹ�ģ
        //�Լ�������Ƶĸ����ԣ���ʧΪһ�ֺõĽ��ⷽ���� 
        double cost[Max][Max]={0};
        for(long i=1;i<=ct;i++)
            for(long j=1;j<=ct;j++)
                if(i!=j)//�ж��Ƿ�Ϊͬһ������ 
                {
                    if(ceil(double(i)/double(4))==ceil(double(j)/double(4)))//�ж��Ƿ���ͬһ������ 
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
        //һ��O(V^3)��Floyd���� 
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
    ��������ʱ����Ҫ�ǿ��ǵ�����Ŀ�����ݹ�ģ�����ر�����ǲ������ڽӱ�ʽ��ͼ
    Ȼ��ʹ�����˼·�򵥵�Floyd���м��㣬������֤������ȷ��
    ��������Ҳʹ���˽�ά��˼·������ԭ����ÿ�������е�һ�����������ά�����½� 
    ת������һ��һά����ֻ��¼������ţ�Ȼ��ͨ������������������ţ����˳���
    ��Ƶĸ����ԣ��Ժ�Ҫ��ס��ά������Ľ�ά�ĳ���������ж�̬�滮�еı��������
    ��Ʒ��������������
*/ 
