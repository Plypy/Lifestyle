/*
  Name: StupidVillage.cpp
  Author: Ply_py
  Description: simulated annealing(ģ���˻� 
*/
//Note
//���Ⳮ����usaco�ϵ�Electric Fence
//����ֱ�Ӱ��ҵĴ���copy������ 
#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;
#define fin cin
#define fout cout 
//ifstream fin("fence3.in");
//ofstream fout("fence3.out");
const int MAXN = 151;
template <class T>
inline void exc(T &a, T &b)
{
    T c = a;
    a = b;
    b = c;
}
struct segment
{
    int x1, x2, y1, y2;
} seg[MAXN];
int n;
void load()
{
    fin >> n;
    int x1, x2, y1, y2;
    for (int i = 1; i <= n; i++)
    {
        fin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2)
            exc(x1,x2);
        if (y1 > y2)
            exc(y1,y2);
        seg[i].x1 = x1;
        seg[i].y1 = y1;
        seg[i].x2 = x2;
        seg[i].y2 = y2;
    }
}
double sqr(double a)
{
    return a*a;
}
double cal(double x, double y)
{
    double ret = 0;
    for (int i = 1; i <= n; i++)
    {
        int x1 = seg[i].x1, x2 = seg[i].x2, y1 = seg[i].y1, y2 = seg[i].y2;
        if (x1 == x2)
        {
            if (y < y1)
                ret += sqrt(sqr(y-y1)+sqr(x-x1));
            else if (y > y2)
                ret += sqrt(sqr(y-y2)+sqr(x-x1));
            else
                ret += fabs(x-x1);
        }
        else
        {
            if (x < x1)
                ret += sqrt(sqr(x-x1)+sqr(y-y1));
            else if (x > x2)
                ret += sqrt(sqr(x-x2)+sqr(y-y1));
            else
                ret += fabs(y-y1);
        }
    }
    return ret;
}
void work()
{
    srand(time(0));
    double t = 100;//��ʼ�¶ȣ����Կ����������뾶 
    double ix = rand()%100, iy = rand()%100;
    double ans = cal(ix,iy);
    int d = 31;
    double tmp, tx, ty;
    while (t > 0.0001)//�����뾶�𽥼�����0�� ��Ϊ��ĿҪ�󾫶�Ϊ0.01������������ 
    {
        for (int i = 1; i <= 500; i++)
        {
            double dx = t*(double(rand())/double(RAND_MAX))*(2*(rand()%2)-1);
                      //�ⲿ�־���dx�Ƕ��ٷ�֮t            �ⲿ�������������
            double dy = sqrt(sqr(t)-sqr(dx))*(2*(rand()%2)-1)+iy;
                      //���ڰ뾶һ��,����dx���dy 
            dx += ix;
            tmp = cal(dx,dy);
            double p = tmp-ans;
            double prob;
            if (p < 0)
            {
                prob = 1;
                tx = dx, ty = dy, ans = tmp;
            }
            else
                prob = exp(-p/t);
            double q = double(rand())/double(RAND_MAX);
            if (q < prob)
            {
                ix = dx, iy = dy;
            }
        }
        ++d;
        t /= log10(d)/log10(20);
    }
    fout << fixed << setprecision(2);
    fout << ans << endl;
}
int main()
{
    load();
    work();
    return 0;
}
