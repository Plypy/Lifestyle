// 划分树
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
// 数组d中d[i][j]表示在划分树中第i层中的第j个位置的数其在被排好序中的数组中的位置
// 数组lnum中lnum[i][j]表示原序列中第j个数在划分树中第i层中从他最早划分到左子树中的数到他有多少个数被划分到左子树中
// 呃实在是没表达清楚 凑合看吧
void build(int h, int l, int r)
{
    if (l == r)
        return;
    int mid = (l+r)>>1;
    int lsize = 0, rsize = 0;//左,右子树的大小 
    for (int i = l; i <= r; ++i)
    {
        if (d[h][i] <= mid)//因为已经排了序，所以序号小就表示着数字小,相当于离散化 
        {                  //划分给左子树 
            d[h+1][l+(lsize)] = d[h][i];
            ++lsize;
            lnum[h][i] = lsize;
        }
        else               //划分给右子树 
        {
            lnum[h][i] = lsize;
            ++rsize;
            d[h+1][mid+rsize] = d[h][i];
        }// 注意划分给左子树与右子树时操作顺序的区别
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
