/*
    ID : jake1994
    PROG : tour
    LANG : C++
*/
//Note: 所谓回路，即为两条不相交的从起点到终点的路径
//可以使用DP来做
//用f[i][j],表示当两条路径分别到了i点与j点时最多能经过多少个城市
//显然f[i][j] = max(f[i][p],f[q][j])+1 
//考虑到若存在两条相交的从1到n路径
//则其必然存在一交点，则当一条路径通过了该交点后
//则当另一条路径向后退时必然不能使其的前驱在另一条路径的前面
//符合条件的两条路径则可以向走路一样左前进一次右前进一次
//对于结点1要特判一次
//DP2 方程依然同上,只不过才用不同的方法避免相交路径
//用迭代的方法，压根就不对形如f[i][i]的状态进行判断，则除f[1][1]外
//其余的这类状态将始终保持初始值，并且不会对判断进行影响
//其实也可以将f[i][i]提前初始化为负无穷

/*1   设f[i][j] 为i城市与j城市分别在两条路线最前方所能经过的最大城市数目 
 *2   算法2伪代码如下
 *3   for i = 1 to n
 *4      do for j = 1 to n
 *5            do f[i][j] = INF;(infinity)
 *6   f[1][1] = 1
 *7   for i = 1 to n-1
 *8      do for j = i+1 to n
 *9            do for each node u in adj[j]      adj[i]代表的是与i城市相连的且序号比i小的城市的列表 
 *10                 do
 *11                   if (f[i][u] > max)
 *12                       then max = f[i][u]
 *13                   f[i][j] = f[j][i] = max+1
 *14  for each node u in adj[n]
 *15     do if (f[n][u] > ans)
 *16         ans = f[n][u]
 *17  return ans
 *
 *      只要该算法在运行中不使两条路径相交，那么就是正确的 
 *      正确性证明
 *      实际上第11到第13行就相当于在一条路径中插入j元素
 *      首先由于图的特殊性j不可能与该条路径中的原有元素重复
 *      其次在另一条路径中的元素序号均小于等于i，而i又小于j
 *      则若在原有路径不含有交叉点的情况下加入j时不会制造交叉点
 *      则因为所有的状态均是由f[1][1]推得，所以该算法会保证两条路径总不相交 
 */ 
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("tour.in");
ofstream fout("tour.out");
const int MAXN = 105;
int n, m;
string city[MAXN];
int f[MAXN][MAXN];
bool used[MAXN][MAXN];
int find(string &t)
{
    for (int i = 1; i <= n; i++)
        if (t == city[i])
            return i;
}
int adj[MAXN][MAXN];
int d[MAXN];
void load()
{
    fin >> n >> m;
    string a, b;
    for (int i = 1; i <= n; i++)
        fin >> city[i];
    int u, v;
    for (int i = 1; i <= m; i++)
    {
        fin >> a >> b;
        u = find(a);
        v = find(b);
        if (u>v)//因为只能从后往前找路径，所以把双向边做成单向边 
            adj[u][++d[u]] = v; 
        else
            adj[v][++d[v]] = u;
    }
}
const int NINF = -1000000;
inline int max(int a, int b)
{
    return a>b?a:b;
}
int dp(int a, int b)
{
    if (used[a][b]||used[b][a])
        return f[a][b];
    used[a][b] = used[b][a] =  true;
    int pre;
    for (int i = 1; i <= d[a]; i++)
    {
        pre = adj[a][i];
        if (pre == 1 || (pre < b))//过滤环 
        {
            f[a][b] = max(f[a][b],dp(pre,b)+1);
        }
    }
    for (int i = 1; i <= d[b]; i++)
    {
        pre = adj[b][i];
        if (pre == 1 || (pre < a))//过滤环 
        {
            f[a][b] = max(f[a][b],dp(a,pre)+1);
        }
    }
    return f[b][a] = f[a][b];
}
void work()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            f[i][j] = NINF;
    used[1][1] = true;
    f[1][1] = 0;
    int ans = dp(n,n);
    if (ans>0)
        fout << ans << endl;
    else
        fout << 1 << endl;
}
void work2()
{
    f[1][1] = 1;
    for (int i = 1; i < n; i++)
        for (int j = i+1; j <= n; j++)
        {
            int tmp = 0;
            for (int k = 1; k <= d[j]; k++)
            {
                if (tmp < f[i][adj[j][k]])
                    tmp = f[i][adj[j][k]];
            }
            if (tmp)
                f[i][j] = f[j][i] = tmp+1;
        }
    int ans = 0;
    for (int i = 1; i <= d[n]; i++)
        ans = max(ans,f[adj[n][i]][n]);
    if (ans)
        fout << ans << endl;
    else
        fout << 1 << endl;
}
int main()
{
    load();
//    work();
    work2();
    return 0;
}
