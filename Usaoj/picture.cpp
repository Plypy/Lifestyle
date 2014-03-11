/*
    ID : jake1994
    PROG : picture
    LANG : C++
*/
// 啊啊啊 我好菜啊，暴力枚举的都不知道该怎么写
// 设level[i]表示坐标i覆盖的层数
// 则在对线段进行排序后，依序扫描时，遇到下面的边就将该边覆盖的部分层数+1
// 如果是上面的层数就-1 
// 当层数由0变为1或由1变为0时都可以确定该段在边缘上
// 问题是如果问的不是矩形而是任意的多边形或者更狠一点是圆怎么办...
// 化圆为方?...... I do not know, really. 
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
ifstream fin("picture.in");
ofstream fout("picture.out");
const int MAX = 10010;
int axis[MAX<<1];
int *level = axis+MAX;
struct segment
{
    int st, ed, ht;
    bool lab;
    segment(int _st = 0, int _ed = 0, int _ht = 0, bool _lab = false):
        st(_st), ed(_ed), ht(_ht), lab(_lab){ }
} hor[MAX], ver[MAX];
int n;
int cmp(const void *a, const void *b)
{
    segment *pa = (segment *)(a);
    segment *pb = (segment *)(b);
    if (pa->ht > pb->ht)
        return 1;
    if (pa->ht == pb->ht && pb->lab)
        return 1;
    return -1;
}
void load()
{
    fin >> n;
    int lx, ly, rx, ry;
    for (int i = 1; i <= n; ++i)
    {
        fin >> lx >> ly >> rx >> ry;
        hor[(i<<1)-1] = segment(lx,rx,ly,true);
        hor[i<<1] = segment(lx,rx,ry,false);
        ver[(i<<1)-1] = segment(ly,ry,lx,true);
        ver[i<<1] = segment(ly,ry,rx,false);
    }
    n <<= 1;
    qsort(hor+1,n,sizeof(segment),cmp);
    qsort(ver+1,n,sizeof(segment),cmp);
}
int ans;
void scan(segment *ar)
{
    memset(axis, 0, sizeof(axis));
    for (int i = 1; i <= n; ++i)
    {
        if (ar[i].lab)
        {
            for (int j = ar[i].st; j < ar[i].ed; ++j)
            {
                ++level[j];
                if (level[j] == 1)
                    ++ans;
            }
        }
        else
        {
            for (int j = ar[i].st; j < ar[i].ed; ++j)
            {
                --level[j];
                if (level[j] == 0)
                    ++ans;
            }
        }
    }
}
struct Tnode
{
    int st, ed,level,len;
    Tnode *l, *r;
    bool leaf;
    Tnode(int _st, int _ed):
        st(_st),ed(_ed),level(0),len(0)
    {
        if (st+1 == ed)
            leaf = true;
        else
        {
            int mid = (st+ed)>>1;
            l = new Tnode(st,mid);
            r = new Tnode(mid,ed);
            leaf = false;
        }
    }
};
void add(Tnode *rt, int st, int ed, int lab)
{
    if (st <= rt->st && rt->ed <= ed)
    {
        rt->level += lab;
        rt->len = rt->ed-rt->st;
    }
    else
    {
        int mid = (rt->st+rt->ed)>>1;
        if (st < mid)
            add(rt->l,st,ed,lab);
        if (ed > mid)
            add(rt->r,st,ed,lab);
    }
    if (rt->level == 0)
    {
        if (rt->leaf)
            rt->len = 0;
        else
            rt->len = rt->l->len+rt->r->len;
    }
}
void work()
{
    Tnode *root = new Tnode(-10000,10000);
    int old;
    for (int i = 1; i <= n; ++i)
    {
        old = root->len;
        add(root,hor[i].st,hor[i].ed,(hor[i].lab?1:-1));
        ans += abs(old-root->len);
    }
    for (int i = 1; i <= n; ++i)
    {
        old = root->len;
        add(root,ver[i].st,ver[i].ed,(ver[i].lab?1:-1));
        ans += abs(old-root->len);
    }
}
void output()
{
    fout << ans << endl;
}
int main()
{
    load();
    work();
    output();
    return 0;
} 
