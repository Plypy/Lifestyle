/*
    ID : jake1994
    PROG : fence4
    LANG : C++
*/
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
/* ���õĳ������� */
#define INF  1e200
#define EP  1e-10
#define MAXV  300
#define PI  3.14159265
const int M=100000+5;
 
/* �������νṹ */
struct POINT {
    double x;
    double y; POINT(double a=0, double b=0) { x=a; y=b;} //constructor
};
struct LINESEG {
    POINT s;
    POINT e;
    LINESEG(POINT a, POINT b) { s=a; e=b;}
    LINESEG() { }
};
double max(double a,double b) {
    if (a>b) return a;
    return b;
}
double min(double a,double b) {
    if (a>b) return b;
    return a;
}
double sqr(double x){
    return x * x;
}
/********************\
* *
* ��Ļ������� *
* *
\********************/
double dist(POINT p1,POINT p2) {// ��������֮��ŷ�Ͼ���
    return( sqrt( (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y) ) );
}
/******************************************************************************
r=multiply(sp,ep,op),�õ�(sp-op)*(ep-op)�Ĳ��
r>0:ep��ʸ��opsp����ʱ�뷽��
r=0��opspep���㹲�ߣ�
r<0:ep��ʸ��opsp��˳ʱ�뷽��
*******************************************************************************/
double multiply(POINT sp,POINT ep,POINT op) {
    return((sp.x-op.x)*(ep.y-op.y)-(ep.x-op.x)*(sp.y-op.y));
}
/* �жϵ�p�Ƿ����߶�l�ϣ�������(p���߶�l���ڵ�ֱ����)&& (��p�����߶�lΪ�Խ��ߵľ�����) */
bool online(LINESEG l,POINT p) {
    return((multiply(l.e,p,l.s)==0) &&( ( (p.x-l.s.x)*(p.x-l.e.x)<=0 )&&( (p.y-l.s.y)*(p.y-l.e.y)<=0 ) ) );
}
//����������е�
POINT midpoint(POINT a, POINT b)
{
    return POINT((a.x + b.x) / 2, (a.y + b.y) / 2);
}
// ����߶�u��v�ཻ(�����ཻ�ڶ˵㴦)ʱ������true
bool intersect(LINESEG u,LINESEG v) {
    return ( (max(u.s.x,u.e.x)>=min(v.s.x,v.e.x))&& //�ų�ʵ��
        (max(v.s.x,v.e.x)>=min(u.s.x,u.e.x))&&
        (max(u.s.y,u.e.y)>=min(v.s.y,v.e.y))&&
        (max(v.s.y,v.e.y)>=min(u.s.y,u.e.y))&&
        (multiply(v.s,u.e,u.s)*multiply(u.e,v.e,u.s)>=0)&& //����ʵ��
        (multiply(u.s,v.e,v.s)*multiply(v.e,u.e,v.s)>=0));
}
// (�߶�u��v�ཻ)&&(���㲻��˫���Ķ˵�) ʱ����true
bool intersect_A(LINESEG u,LINESEG v) {
    return ((intersect(u,v))&&
        (!online(u,v.s))&&
        (!online(u,v.e))&&
        (!online(v,u.e))&&
        (!online(v,u.s)));
}
const int MAXN = 201;
int n;
POINT p[MAXN], e;
LINESEG s[MAXN];
bool sv[MAXN];
bool save(int k, LINESEG a)
{
    if (dist(a.s, a.e) < 1e-5) return false;
    int flag = 0;
    for (int v = 1; v <= n; v++)
        if (v != k){
            if (intersect(LINESEG(e, a.s), s[v]) && intersect(LINESEG(e, a.e), s[v])){
                flag = 1;
                break;
            }
            if (intersect_A(LINESEG(e, a.s), s[v]) || intersect_A(LINESEG(e, a.e), s[v])) flag = 2;
        }
    if (flag == 0) return true;
    if (flag == 1) return false;
    else return save(k, LINESEG(a.s, midpoint(a.s, a.e))) || save(k, LINESEG(midpoint(a.s, a.e), a.e));
}
int main()
{
    freopen("fence4.in", "r", stdin);
    freopen("fence4.out", "w", stdout);
    scanf("%d", &n);
    scanf("%lf%lf", &e.x, &e.y);
    for (int i = 1; i <= n; i++)
        scanf("%lf%lf", &p[i].x, &p[i].y);
    for (int i = 1; i < n; i++)
        s[i] = LINESEG(p[i], p[i + 1]);
    s[n] = LINESEG(p[1], p[n]);
    int cnt = 0;
    memset(sv, false, sizeof(sv));
    for (int i = 1; i <= n; i++)
        if (save(i, s[i])) {
            cnt++;
            sv[i] = true;
        }
    printf("%d\n", cnt);
    for (int i = 1; i < n - 1; i++)
        if (sv[i]) printf("%d %d %d %d\n", (int)s[i].s.x, (int)s[i].s.y, (int)s[i].e.x, (int)s[i].e.y);
    if (sv[n]) printf("%d %d %d %d\n", (int)s[n].s.x, (int)s[n].s.y, (int)s[n].e.x, (int)s[n].e.y);
    if (sv[n - 1]) printf("%d %d %d %d\n", (int)s[n - 1].s.x, (int)s[n - 1].s.y, (int)s[n - 1].e.x, (int)s[n - 1].e.y);
    return 0;
}
