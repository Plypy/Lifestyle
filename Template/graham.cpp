const int MAXN = 10001;
struct point
{
    double x, y;
}pt[MAXN];
int ord[MAXN];
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
}
