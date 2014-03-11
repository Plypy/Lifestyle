/**
 * Description: Find out a pair of points with maximum distance within given point set
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

struct Point {
    int x, y;
    Point() { }
    Point(int x, int y): x(x), y(y) { }
};
Point operator-(Point a, Point b) {
    return Point(a.x-b.x,a.y-b.y);
}
int cross(Point a, Point b) {
    return a.x*b.y-a.y*b.x;
}
int area2(Point a, Point b, Point p) {
    return cross(b-a,p-a);
}
int sqr(int a) {
    return a*a;
}
int dist(Point a, Point b) {
    return sqr(a.x-b.x)+sqr(a.y-b.y);
}
bool cmp(const Point &a, const Point &b) {
    if (a.x != b.x)
        return a.x < b.x;
    return a.y < b.y;
}
int andrew(Point *p, int n, Point *ch) {
    sort(p,p+n,cmp);
    int top = 0;
    for (int i = 0; i < n; ++i) {
        while (top > 1 && area2(ch[top-2],ch[top-1],p[i]) <= 0)
            --top;
        ch[top++] = p[i];
    }
    int k = top;
    for (int i = n-2; i >= 0; --i) {
        while (top > k && area2(ch[top-2],ch[top-1],p[i]) <= 0)
            --top;
        ch[top++] = p[i];
    }
    if (n > 1)
        --top;
    return top;
}
int diameter(Point *ch, int n) {
    int ret = 0;
    int j = 1;
    for (int i = 0; i < n; ++i) {
        while (area2(ch[i],ch[(i+1)%n],ch[(j+1)%n]) > area2(ch[i],ch[(i+1)%n],ch[j]))
            j = (j+1)%n;
        ret = max(ret,max(dist(ch[i],ch[j]),dist(ch[(i+1)%n],ch[(j+1)%n])));
    }
    return ret;
}
const int MAXN = 50005;
Point p[MAXN], ch[MAXN];
int n, m;
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d%d", &p[i].x, &p[i].y);

    m = andrew(p,n,ch);
    int ans = diameter(ch,m);
    printf("%d\n", ans);
}