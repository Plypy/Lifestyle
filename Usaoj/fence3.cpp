/*
    ID : jake1994
    PROG : fence3
    LANG : C++
*/
//Note
//此题是一道搜索题，他的状态空间是二维的。
//我选用了一种随机算法：模拟退火 
//由于是第一次写该算法，再加上荒废了一周》。。所以用了大约2个半小时
//真正竞赛的时候肯定不敢这么搞。
//另外写一下模拟退火的流程 
//首先选定一个初始温度（在这里就是搜索半径），与一个随机生成的初始解
//然后逐渐减少温度
//每减少一次温度就连续产生L个随机解
//并对每个随机解估价（在这里就是与所有线段的距离），如果此估价比当前最优解更优
//就将其选取为新的扩散点，否则用exp（-p/t)的概率将其选为扩散点，p为当前估价与最优估价的增量。
//这样就可以逐渐逼近最优解啦 
#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;
ifstream fin("fence3.in");
ofstream fout("fence3.out");
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
    double t = 100;//初始温度，可以看作是搜索半径 
    double ix = rand()%100, iy = rand()%100;
    double ans = cal(ix,iy);
    int d = 31;
    double tmp, tx, ty;
    while (t > 0.01)//搜索半径逐渐减少至0， 因为题目要求精度为0.1，所以这样做 
    {
        for (int i = 1; i <= 500; i++)
        {
            double dx = t*(double(rand())/double(RAND_MAX))*(2*(rand()%2)-1);
                      //这部分决定dx是多少分之t            这部分随机决定正负
            double dy = sqrt(sqr(t)-sqr(dx))*(2*(rand()%2)-1)+iy;
                      //由于半径一定,根据dx算出dy 
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
    fout << fixed << setprecision(1);
    fout << tx << ' ' << ty << ' ' << ans << endl;
}
int main()
{
    load();
    work();
    return 0;
}
