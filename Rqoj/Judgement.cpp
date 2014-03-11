#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
const int MAXN = 100005;
const int INF = 1000000;
struct point
{
    int x;
    int y;
    friend ostream & operator<<(ostream &os, point t)
    {
        os << t.x << ' ' << t.y << endl;
        return os;
    }
}pt[MAXN];
int ord[MAXN];
int det(int x1, int y1, int x2, int y2)
{
    return x1*y2-x2*y1;
}
int cross(point &a, point &b, point &c)
{
    return det(b.x-a.x,b.y-a.y,c.x-a.x,c.y-a.y);
}
int minx = INF, miny = INF;
int minid;
int sqr(int a)
{
    return a*a;
}
double dist(int a, int b)
{
    return sqrt(sqr(pt[a].x-pt[b].x)+sqr(pt[a].y-pt[b].y));
}
int cmp(const void *pa, const void *pb)
{
    int a = *(int *)pa;
    int b = *(int *)pb;
    int t;
    if (b == minid || (t = cross(pt[minid],pt[a],pt[b]))<0)
        return 1;
    if (t == 0 && dist(ord[1],a) > dist(ord[1],b))
        return 1;
    return -1;
}
int stack[MAXN];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &pt[i].x, &pt[i].y);
        ord[i] = i;
        if (pt[i].y < miny || (pt[i].y == miny && pt[i].x < minx))
        {
            minx = pt[i].x;
            miny = pt[i].y;
            minid = i;
        }
    }
    swap(ord[1],ord[minid]);
    qsort(ord+2,n-1,sizeof(int),cmp);
    int top = 0;
    stack[++top] = ord[1];
    stack[++top] = ord[2];
    int tmp;
    for (int i = 3; i <= n; i++)
    {
        while (top > 1 && cross(pt[stack[top-1]],pt[stack[top]],pt[ord[i]]) <= 0)
            top--;
        stack[++top] = ord[i];
    }
    double ans = 0;
//    for (int i = 1; i <= top; i++)
//        cout << pt[stack[i]];
    for (int i = 2; i < top; i++)
        ans += cross(pt[stack[1]],pt[stack[i]],pt[stack[i+1]]);
    cout << fixed << setprecision(1);
    ans /= 2;
    cout << ans;
//    getchar();
//    getchar();
    return 0;
}
