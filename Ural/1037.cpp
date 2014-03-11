// ��������߶���
// ץס��һ���ؼ��㣬���ǲ���ʱֻ��Ҫһ���ڴ������ʱ��С�ڵ�ǰʱ�伴��
// �������߶�����¼�������ڵ���Сֵ�����Ȳ���������������������Ŀ�е�Ҫ�� 
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int MAXN = 30005;
const int RemainTime = 600;
int SegTree[MAXN<<2];
inline int min(int a, int b)
{
    return a<b?a:b;
}
inline int max(int a, int b)
{
    return a>b?a:b;
}
void insert(int pos, int Lbound, int Rbound, int nTime)
{
    if (Lbound == Rbound)
    {
        SegTree[pos] = nTime+RemainTime;
        cout << Lbound << endl;
        return;
    }
    int lson = pos<<1;
    int rson = lson+1;
    int mid = (Lbound+Rbound)>>1;
    if (SegTree[lson] <= nTime)
        insert(lson, Lbound, mid, nTime);
    else
        insert(rson, mid+1, Rbound, nTime);
    SegTree[pos] = min(SegTree[lson],SegTree[rson]);
}
void modify(int pos, int Lbound, int Rbound, int nTime, int location)
{
    if (Lbound == Rbound)
    {
        if (nTime >= SegTree[pos])
        {
            cout << "-" << endl;
        }
        else
        {
            cout << "+" << endl;
            SegTree[pos] = max(SegTree[pos],nTime+RemainTime);
        }
        return;
    }
    int lson = pos<<1;
    int rson = lson+1;
    int mid = (Lbound+Rbound)>>1;
    if (location <= mid)
        modify(lson, Lbound, mid, nTime, location);
    else
        modify(rson, mid+1, Rbound, nTime, location);
    SegTree[pos] = min(SegTree[lson],SegTree[rson]);
}
int main()
{
    int t;
    char type;
    int loc;
    while (cin >> t)
    {
        cin >> type;
        if ('+' == type)
            insert(1,1,30000,t);
        else
        {
            cin >> loc;
            modify(1,1,30000,t,loc);
        }
    }
    return 0;
}
