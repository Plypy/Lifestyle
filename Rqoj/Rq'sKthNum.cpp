// ������
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 10005;
struct data
{
    int num, id;
    
    data(int _num = 0, int _id = 0):
        num(_num), id(_id){ }
    friend bool operator<(const data &a, const data &b)
    {
        return a.num < b.num;
    }
} ar[MAXN];
int d[20][MAXN],lnum[20][MAXN];
// ����d��d[i][j]��ʾ�ڻ������е�i���еĵ�j��λ�õ������ڱ��ź����е������е�λ��
// ����lnum��lnum[i][j]��ʾԭ�����е�j�����ڻ������е�i���д������绮�ֵ��������е��������ж��ٸ��������ֵ���������
// ��ʵ����û������ �պϿ���
void build(int h, int l, int r)
{
    if (l == r)
        return;
    int mid = (l+r)>>1;
    int lsize = 0, rsize = 0;//��,�������Ĵ�С 
    for (int i = l; i <= r; ++i)
    {
        if (d[h][i] <= mid)//��Ϊ�Ѿ��������������С�ͱ�ʾ������С,�൱����ɢ�� 
        {                  //���ָ������� 
            d[h+1][l+(lsize)] = d[h][i];
            ++lsize;
            lnum[h][i] = lsize;
        }
        else               //���ָ������� 
        {
            lnum[h][i] = lsize;
            ++rsize;
            d[h+1][mid+rsize] = d[h][i];
        }// ע�⻮�ָ���������������ʱ����˳�������
    }
    build(h+1,l,mid);
    build(h+1,mid+1,r);
}

int find(int h, int st, int ed, int l, int r, int k)
{
    if (l == r)
        return d[h][l];
    int ls = 0, rs;
    if (l > st)
        ls = lnum[h][l-1];
    rs = lnum[h][r];
    int t = rs-ls;
    int mid;
    mid = (st+ed)>>1;
    if (t >= k)
        return find(h+1,st,mid,st+ls,st+rs-1,k);
    return find(h+1,mid+1,ed,mid+1 + l-st-ls,mid+1 + r-st-rs,k-t);
}
int n, m;
int main()
{
    int tmp;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> tmp;
        ar[i] = data(tmp,i);
    }
    sort(ar+1,ar+n+1);
    for (int i = 1; i <= n; ++i)
    {
        d[0][ar[i].id] = i;
    }
    build(0,1,n);
    int a, b, c;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b >> c;
        cout << ar[find(0,1,n,a,b,c)].num << endl;
    }
    return 0;
}

/*
4 3
4 1 2 3
1 3 1
2 4 3
1 4 4

1
3
4
*/
