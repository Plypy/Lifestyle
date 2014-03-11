/*
    ID : jake1994
    PROG : milk6
    LANG : C++
*/
//Summary
//这是第一次写最小割 
//这个最小割问题比较特殊，要求出边数最小的最小割，如果边数相同序号还要尽可能小
//方法一 特殊方法，边权函数 
//则每个边相当于有三个关键字，第一个为容量，第二个为边数，第三个为边的序号
//可以设计一个边权函数，此函数可以使得边权大小根据以上的三个关键字递增
//即关键字越大的边权越大，具体的边权函数就像 
//跑一遍最大流就可以了
//通过此方式求出的最小割集，必然满足割的大小最小，边数最少，各个序号最小
//然后运行一遍floodfill，求出S集（即为源点所在的那个点集），
//再通过此判断割边即可。 
//方法二 使用枚举打开思路 
//也是先跑一遍最大流然后枚举从小到大枚举边数i 
//再在边集中搜索是否此时有i条满载边满足其容量之和等于割
//不过估计这样会超时
//改进，可以通过方法一中的边权函数，设边权函数为f(u,v) = (|e|+1)*c(u,v)+1
//求出最大流后可以算出num=maxflow mod (|e|+1)，num即为割集中的边数
//然后再进行枚举，不过既然已经设计出这样的边权函数了，还不如直接用方法一呢... 
//方法三 传统方法
//传统方法是求出最大流，然后枚举一个边删去再求一次最大流，如果此时的比原来求得
//减少的量刚好为此边的容量，则可以判断此边属于割集，直到求出的最大流为0为止。 
//对于此题的特殊要求，可以先根据边的容量大小为第一关键字（递减），边的序号为第二
//关键字（递增），先进行一次排序，然后根据排序依次枚举即可。
//具体实现在另一个文件milk6test.cpp
//经过实验验证，此方法错误，因为排序并不能保证割集边数最少
/***********************************CutLine************************************/ 
//我的代码使用方法一,113行吧。还行，不算长。 
#include <iostream>
#include <fstream>
#include <climits>
using namespace std;
ifstream fin("milk6.in");
ofstream fout("milk6.out");
typedef unsigned long long ull;
const ull MAXN = 35;
const ull MAXE = 1001;
const ull FAC = 500501;
const ull INF = ULONG_LONG_MAX;
ull f[MAXN][MAXN];
ull n, m;
inline ull min(ull a, ull b)
{
    return a<b?a:b;
}
struct edge
{
    ull bg;
    ull ed;
} edg[MAXE];
inline void load()
{
    fin >> n >> m;
    ull s,e,c;
    for (ull i = 1; i <= m; i++)
    {
        fin >> s >> e >> c;
        f[s][e] += c*MAXE*FAC+FAC+i;
        edg[i].bg = s;
        edg[i].ed = e;
    }
}
bool found;
ull delta;
ull hct[MAXN];
ull h[MAXN];
ull loss;
void aug(ull u)
{
    if (u == n)
    {
        loss += delta;
        found = true;
        return ;
    }
    ull backup = delta;
    ull minh = n-1;
    ull v;
    for (v = 1; v <= n; v++)
        if (f[u][v]>0)
        {
            if (h[v]+1 == h[u])
            {
                delta = min(delta,f[u][v]);
                aug(v);
                if (h[1] >= n)
                    return;
                if (found)
                    break;
                delta = backup;
            }
            minh = min(minh,h[v]);
        }
    if (found)
    {
        f[u][v] -= delta;
        f[v][u] += delta;
    }
    else
    {
        hct[h[u]]--;
        if (hct[h[u]] == 0)
            h[1] = n;
        h[u] = minh+1;
        hct[h[u]]++;
    }
}
inline void sap()
{
    hct[0] = n;
    while (h[1] < n)
    {
        found = false;
        delta = INF;
        aug(1);
    }
}
bool used[MAXN];
void dfs(ull u)
{
    used[u] = true;
    for (ull v = 1; v <= n; v++)
        if (f[u][v]&&!used[v])
            dfs(v);
}
void output()
{
    fout << loss/(MAXE*FAC) << ' ' << (loss%(MAXE*FAC))/FAC << endl;
    for (int i = 1; i <= m; i++)
    {
        int s = edg[i].bg;
        int e = edg[i].ed;
        if (used[s] && !used[e])
            fout << i << endl;
    }
}
int main()
{
    load();
    sap();
    dfs(1);
    output();
    return 0;
}
