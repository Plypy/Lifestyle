/**
 * Description: Compute a polygon's centre
 * Caution: This problem's data size is very large. Don't use too many middle variables, which may cause MLE.
 * Source:
 * Author: Ply_py
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
using namespace std;

const int MAXN = 1000010;
struct Point {
    double x,y;
} ;
double area2(Point a,Point b,Point c) {
    return (c.x - a.x)*(b.y - a.y) - (b.x - a.x)*(c.y - a.y);
}
Point getCentre(Point pt[],int n)
{
    Point ret;
    double area = 0.0,t2;
    ret.x = 0.0; ret.y = 0.0;
    for(int i=1; i<n-1; i++)
    {
        t2 = area2(pt[i],pt[0],pt[i+1]);
        ret.x += (pt[0].x + pt[i].x + pt[i+1].x)*t2;
        ret.y += (pt[0].y + pt[i].y + pt[i+1].y)*t2;
        area += t2;
    }
    ret.x /= (3*area);
    ret.y /= (3*area);
    return ret;
}
Point pt[MAXN];
int main()
{
    int n,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            scanf("%lf%lf",&pt[i].x,&pt[i].y);
        Point ans = getCentre(pt,n);
        printf("%.2lf %.2lf\n",ans.x,ans.y);
    }
    return 0;
}