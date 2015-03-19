// #pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
#define ll int
#define point Point
const double eps = 1e-8;
const double PI = acos(-1.0);
double ABS(double x){return x>0?x:-x;}
int sgn(double x){
    if(fabs(x) < eps)return 0;
    if(x<0)return -1;
    return 1;
}
struct Point
{
    double x, y;
    void put(){printf("%.0f,%.0f\n",x,y);}
    Point(){}
    Point(double _x, double _y){
        x = _x; y = _y;
    }
    Point operator - (const Point & b)const{
        return Point(x-b.x, y-b.y);
    }
    double operator ^ (const Point &b) const{
        return x*b.y - y*b.x;
    }
    double operator *(const Point &b) const{
        return x*b.x + y*b.y;
    }
    void transXY(double B){
        double tx = x, ty = y;
        x = tx*cos(B) - ty*sin(B);
        y = tx*sin(B) + ty*cos(B);
    }
};
double dist(point a,point b){    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
struct Line
{
    Point s,e;
    double len(){return dist(s,e);}
    Line(){}
    Line(Point _s, Point _e)
    {
        s = _s; e = _e;
    }
    pair<int,Point> operator & (const Line &b) const{
        Point res = s;
        if(sgn((s-e) ^ (b.s-b.e)) == 0)
        {
            if(sgn((s-b.e) ^ (b.s-b.e)) == 0)
                return make_pair(0,res);
            else return make_pair(1,res);
        }
        double t = ((s-b.s) ^ (b.s-b.e)) / ((s-e)^(b.s-b.e));
        res.x += (e.x - s.x) *t;
        res.y += (e.y - s.y) *t;
        return make_pair(2, res);
    }
};
double cross(point a, point b, point c) {
    return (a.x - c.x) * (b.y - c.y) - (a.y - c.y) * (b.x - c.x);
}
bool intersect(Line l1, Line l2) {
    return
        max(l1.s.x, l1.e.x) > (min(l2.s.x, l2.e.x)-eps) &&
        max(l2.s.x, l2.e.x) > (min(l1.s.x, l1.e.x)-eps) &&
        max(l1.s.y, l1.e.y) > (min(l2.s.y, l2.e.y)-eps) &&
        max(l2.s.y, l2.e.y) > (min(l1.s.y, l1.e.y)-eps) &&
        (cross(l2.s, l1.e, l1.s) * cross(l1.e, l2.e, l1.s) > -eps) &&
        (cross(l1.s, l2.e, l2.s) * cross(l2.e, l1.e, l2.s) > -eps);
}
bool online(Line l, point P) {
    return (fabs(cross(l.e, P, l.s)) < eps) &&
        ((((P.x > l.s.x - eps) && (P.x < l.e.x + eps)) || ((P.x > l.e.x - eps) && (P.x < l.s.x+eps)))&&
        (((P.y > l.s.y - eps) && (P.y < l.e.y + eps)) || ((P.y > l.e.y - eps) && (P.y < l.s.y +eps))));
}
bool inter(Line u, Line v){
    return ((intersect(u, v)) && (!online(u, v.s)) && (!online(u, v.e)) && (!online(v, u.s)) && (!online(v, u.e)));
}
point S, T, A, B, C;
Line AB, BC, ST, AC, SA, SB, SC, TA, TB, TC;
double ans;
bool ok(Line x){
    if(inter(x, AB))return false;
    if(inter(x, BC))return false;
    return true;
}
double d[5][5];
void addedge()
{
    for (int i=0;i<5;i++)
        for (int j=0;j<5;j++)
        {
            if (i==j) d[i][j]=0;
            else d[i][j]=1e8;
        }

        if (!inter(SA, BC))
        {
            d[0][1]=d[1][0]=min(d[0][1],dist(S,A));
        }
        //d[0][2]=d[2][0]=min(d[0][2],dis(S,B));

        d[1][2]=d[2][1]=min(d[1][2],dist(A,B));
        d[1][3]=d[3][1]=min(d[1][3],dist(A,C));
        d[2][3]=d[3][2]=min(d[2][3],dist(B,C));

        if (!inter(SC,AB))
        {
            d[0][3]=d[3][0]=min(d[0][3],dist(S,C));
        }

        if (!intersect(ST,AB) && !intersect(ST,BC))
        {
            d[0][4]=d[4][0]=min(d[0][4],dist(S,T));
        }
        //printf("1->4 %d\n",is_inter(A,T,B,C));
        if (!inter(TA,BC))
        {
            d[1][4]=d[4][1]=min(d[1][4],dist(A,T));
        }

        if (cross(B,A,T)*cross(B,C,T)>-eps)
        {
            d[2][4]=d[4][2]=min(d[2][4],dist(B,T));
        }

        if (cross(S,A,B)*cross(S,C,B)>-eps)
        {
            d[0][2]=d[2][0]=min(d[0][2],dist(S,B));
        }

        if (!inter(TC,AB))
        {
            d[3][4]=d[4][3]=min(d[3][4],dist(C,T));
        }

}
int main(){
    int i, j, k, cas;scanf("%d",&cas);
    while(cas--) {
        scanf("%lf %lf", &S.x, &S.y);
        scanf("%lf %lf", &T.x, &T.y);
        scanf("%lf %lf", &A.x, &A.y);
        scanf("%lf %lf", &B.x, &B.y);
        scanf("%lf %lf", &C.x, &C.y);
        AB = Line(A,B); BC = Line(B,C); ST = Line(S,T); AC = Line(A,C);
        SA = Line(S,A); SB = Line(S,B); SC = Line(S,C);
        TA = Line(T,A); TB = Line(T,B); TC = Line(T,C);
        addedge();
        for(i = 0; i < 5; i++)
            for(j = 0; j < 5; j++)
                for(k = 0; k < 5; k++)
                    d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
        printf("%.8f\n", d[0][4]);
    }
    return 0;
}
/*


*/
