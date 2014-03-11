#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
const int MAXN = 101;
const int INF = 1000000;
struct point
{
    int x;
    int y;
    friend istream &operator>>(istream &is, point &t)
    {
        is >> t.x >> t.y;
        return is;
    }
    friend ostream &operator<<(ostream &os, point &t)
    {
        os << t.x << ' ' << t.y;
        return os;
    }
} pt[MAXN], dstpt;
int det(int x1, int y1, int x2, int y2)
{
    return x1*y2-x2*y1;
}
int cross(point &a, point &b, point &c)
{
    return det(b.x-a.x,b.y-a.y,c.x-a.x,c.y-a.y);
}
int sqr(int a)
{
    return a*a;
}
double dist(point &a, point &b)
{
    return sqrt(sqr(a.x-b.x)+sqr(b.y-a.y));
}
int ord[MAXN];
int stack[MAXN];
int top;
int n, m;
int cmp(const void *pa, const void *pb)
{
    int a = *(int *)pa;
    int b = *(int *)pb;
    int tmp = cross(pt[ord[1]],pt[a],pt[b]);
    if (tmp < 0 || (tmp == 0 && dist(pt[ord[1]],pt[a])>dist(pt[ord[1]],pt[b])))
        return 1;
    return -1;
}
void cv()
{
    int minid, minx = INF, miny = INF;
    for (int i = 1; i <= n; i++)
    {
        ord[i] = i;
        if (pt[i].y < miny || (pt[i].y==miny && pt[i].x < minx))
        {
            minx = pt[i].x;
            miny = pt[i].y;
            minid = i;
        }
    }
    swap(ord[1],ord[minid]);
    qsort(ord+2,n-1,sizeof(int),cmp);
    stack[++top] = ord[1];
    for (int i = 2; i <= n; i++)
    {
        while (top>1 && cross(pt[stack[top-1]],pt[stack[top]],pt[ord[i]])<=0)
            top--;
        stack[++top] = ord[i];
    }
}
bool on(point &end1, point &end2, point &dpt)
{
    if ((dpt.x-end1.x)*(dpt.x-end2.x)>0)
        return false;
    if ((dpt.y-end1.y)*(dpt.y-end2.y)>0)
        return false;
    return true;
}
bool in(point &dpt)
{
    int judge = cross(pt[stack[top]],pt[stack[1]],dpt);
    if (judge < 0)
        return false;
    if (judge == 0 && on(pt[stack[top]],pt[stack[1]],dpt))
        return true;
    for (int i = 1; i < top; i++)
    {
        judge = cross(pt[stack[i]],pt[stack[i+1]],dpt);
        if (judge < 0)
            return false;
        if (judge == 0 && on(pt[stack[top]],pt[stack[1]],dpt))
            return true;
    }
    return true;
}
void show()
{
    for (int i = 1; i <= top; i++)
        cout << pt[stack[i]] << endl;
}
int main()
{
//    freopen("test.in","r",stdin);
//    freopen("test.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> pt[i];
    cv();
//    show();
    for (int i = 1; i <= m; i++)
    {
        cin >> dstpt;
        if (in(dstpt))
            cout << 1;
        else
            cout << 0;
        cout << endl;
    }
//    system("pause");
    return 0;
}
