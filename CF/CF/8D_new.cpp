//用三分解
//快多了！！
#include <cstdio>
#include <cmath>
#include <algorithm>
#define eps 1e-10
using namespace std;
struct Point
{
	double x,y;
}a,b,c;
double t1,t2;
double dist(Point u,Point v)
{
	return sqrt((u.x-v.x)*(u.x-v.x)+(u.y-v.y)*(u.y-v.y));
}
double calc(double k)
{
	Point p,p0; double mid,left,right; int times;
	p0.x = k*b.x+(1-k)*c.x; //定比分点
	p0.y = k*b.y+(1-k)*c.y;
	if(dist(a,p0)+dist(b,p0)<t1 && dist(a,p0)+dist(c,p0)<t2)
		return min(t1-dist(b,p0),t2-dist(c,p0));
	times = 100; left=0; right = 1;
	while(times--)
	{
		mid = (left+right)*0.5;
		p.x = mid*p0.x+(1-mid)*a.x; //定比分点
		p.y = mid*p0.y+(1-mid)*a.y;
		if(mid*dist(p0,a)+dist(p,b)<=t1+eps && mid*dist(p0,a)+dist(p,c)<=t2+eps)
			left = mid;
		else right = mid;
		//printf("%lf\n",mid);
	}
	//printf("%lf\n",right);
	return mid*dist(a,p0);
}
int main()
{
	//freopen("input.txt","r",stdin);
	scanf("%lf%lf",&t1,&t2);
	scanf("%lf%lf",&a.x,&a.y);
	scanf("%lf%lf",&c.x,&c.y);
	scanf("%lf%lf",&b.x,&b.y);
	double ab,bc,ac;
	ab = dist(a,b); ac = dist(a,c); bc = dist(b,c);
	t2 += ac; t1 += ab;
	if(t2+eps >= ab+bc)
	{
		printf("%.10lf",min(t2,t1+bc));
		return 0;
	}
	int times = 100; double left=0,right=1,m1,m2;
	while(times--)
	{
		m1 = 2*left+right; m1/=3;
		m2 = left+2*right; m2/=3;
		if(calc(m1) > calc(m2)) right = m2;
		else left = m1;
	}
	printf("%.10lf",calc((left+right)*0.5));
}
