/*
    ID : jake1994
    PROG : fc
    LANG : C++
*/
//Note：重载一下输入还是很方便的，易于调试
//这是我第一次写凸包，HOHO，总体感觉还不错，没有查阅太多的资料
//用的是Graham-scan，具体思路就是先选出一个最下最左的点记为p0。
//然后根据p0对其他点进行极角排序，排序的时候使用叉积来判断，我使用的是逆时针排序 
//排序的时候应注意让p0对应的点处于最前的位置
//因为仅仅用叉积排序无法保证p0对应的点处于最前的位置
//所以再排序时应加入一个特判，判断当前节点是否为p0对应的点 
//然后建立一个栈将排序后的第一个和第二个点依次压入栈中
//然后对剩余的n-2个点根据排序判断是否入栈
//对于当前结点i，判断它与栈顶的两个元素构成的两条线段
//如果是左转，就将其压入栈顶并考虑下一个节点
//否则就将栈顶元素弹出并继续判断该节点
//具体代码如下，洋洋洒洒百余行 
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cmath>
using namespace std;
ifstream fin("fc.in");
ofstream fout("fc.out");
const int MAXN = 10001;
struct point
{
    double x, y;
    friend ostream &operator<<(ostream &os, point tp)
    {
        os << tp.x << ' ' << tp.y;
        return os;
    }
}pt[MAXN];
int ord[MAXN];
point p0 = {1e10,1e11};
int n;
double det(double x1, double y1, double x2, double y2)
{
    return x1*y2-x2*y1;
}
double cross(point a, point b, point c)
{
    return det(b.x-a.x,b.y-a.y,c.x-a.x,c.y-a.y);
}
int tid;
int cmp(const void *pa, const void *pb)
{
    int a = *((int *)pa);
    int b = *((int *)pb);
    if (b == tid || cross(p0,pt[a],pt[b])<0)
        return 1;
    return -1;
}
void load()
{
    fin >> n;
    double tx, ty;
    for (int i = 1; i <= n; i++)
    {
        fin >> tx >> ty;
        pt[i].x = tx;
        pt[i].y = ty;
        ord[i] = i;
        if (ty < p0.y || (ty==p0.y&&tx<p0.x))
        {
            p0.x = tx;
            p0.y = ty;
            tid = i;
        }
    }
    qsort(ord+1,n,sizeof(int),cmp);
}
double sqr(double a)
{
    return a*a;
}
double dist(point p1, point p2)
{
    return sqrt(sqr(p1.x-p2.x)+sqr(p1.y-p2.y));
}
void work()
{
    //Graham-Scan-Algorithm
    int stack[MAXN];
    int size=0;
    stack[++size] = ord[1];
    stack[++size] = ord[2];
    for (int i = 3; i <= n;)
    {
        if (cross(pt[stack[size-1]],pt[stack[size]],pt[ord[i]])>0)
            stack[++size] = ord[i++];
        else
            --size;
    }
    double ans = 0;
    for (int i = 2; i <= size; i++)
        ans += dist(pt[stack[i]],pt[stack[i-1]]);
    ans += dist(pt[stack[1]],pt[stack[size]]);
    fout << setprecision(2) << setiosflags(ios::fixed|ios::showpoint);
    fout << ans << endl;
}
int main()
{
    load();
    work();
    return 0;
}
