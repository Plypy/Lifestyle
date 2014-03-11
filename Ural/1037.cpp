// 很巧妙的线段树
// 抓住了一个关键点，就是插入时只需要一个内存块的最后时间小于当前时间即可
// 所以用线段树记录下区间内的最小值并优先插入左子树，便能满足题目中的要求 
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
