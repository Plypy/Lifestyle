/*
    ID : jake1994
    PROG : fc
    LANG : C++
*/
//Note������һ�����뻹�Ǻܷ���ģ����ڵ���
//�����ҵ�һ��д͹����HOHO������о�������û�в���̫�������
//�õ���Graham-scan������˼·������ѡ��һ����������ĵ��Ϊp0��
//Ȼ�����p0����������м������������ʱ��ʹ�ò�����жϣ���ʹ�õ�����ʱ������ 
//�����ʱ��Ӧע����p0��Ӧ�ĵ㴦����ǰ��λ��
//��Ϊ�����ò�������޷���֤p0��Ӧ�ĵ㴦����ǰ��λ��
//����������ʱӦ����һ�����У��жϵ�ǰ�ڵ��Ƿ�Ϊp0��Ӧ�ĵ� 
//Ȼ����һ��ջ�������ĵ�һ���͵ڶ���������ѹ��ջ��
//Ȼ���ʣ���n-2������������ж��Ƿ���ջ
//���ڵ�ǰ���i���ж�����ջ��������Ԫ�ع��ɵ������߶�
//�������ת���ͽ���ѹ��ջ����������һ���ڵ�
//����ͽ�ջ��Ԫ�ص����������жϸýڵ�
//����������£��������������� 
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
