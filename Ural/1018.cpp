#include <iostream>
#include <cstdlib>
using namespace std;
const int MAXN = 105;
int lson[MAXN], rson[MAXN];
int lapp[MAXN], rapp[MAXN];
int size[MAXN];
int n, q;
int edge[MAXN][4];
int eapp[MAXN][4];
bool used[MAXN];
bool leaf[MAXN];
void make_tree(int u)
{
    used[u] = true;
    int i;
    bool flag = false;
    for (i = 1; i <= edge[u][0]; ++i)
        if (!used[edge[u][i]])
        {
            lson[u] = edge[u][i];
            lapp[u] = eapp[u][i];
            make_tree(lson[u]);
            size[u] += size[lson[u]]+1;
            flag = true;
            break;
        }
    for (++i; i <= edge[u][0]; ++i)
        if (!used[edge[u][i]])
        {
            rson[u] = edge[u][i];
            rapp[u] = eapp[u][i];
            make_tree(rson[u]);
            size[u] += size[rson[u]]+1;
            flag = true;
            break;
        }
    if (!flag)
        leaf[u] = true;
}
void load()
{
    cin >> n >> q;
    int a, b, c;
    while (cin >> a >> b >> c)
    {
        edge[a][++edge[a][0]] = b;
        eapp[a][edge[a][0]] = c;
        edge[b][++edge[b][0]] = a;
        eapp[b][edge[b][0]] = c;
    }
    make_tree(1);
}
int mem[MAXN][MAXN];
// 你妹啊...真烦人，为了优化程序常数...浪费了2个小时在这么一道水题上
// 应该先写出程序的大框架和主题思路，成功之后再优化 
int dp(int u, int rest)
{
    if (u == 0 || rest == 0 || rest > size[u])
        return 0;
    if (mem[u][rest])
        return mem[u][rest];
    int ret = 0;
    // left
    ret = max(ret,lapp[u]+dp(lson[u],rest-1));
    // right
    ret = max(ret,rapp[u]+dp(rson[u],rest-1));
    // both
    for (int i = 0; i <= rest-2; ++i)
        ret = max(ret,rapp[u]+lapp[u]+dp(lson[u],i)+dp(rson[u],rest-2-i));
    return mem[u][rest] = ret;
}
void work()
{
    cout << dp(1,q) << endl;
}
int main()
{
    load();
    work();
    //system("pause");
    return 0;
}
/*
5 2
1 3 1
1 4 10
2 3 20
3 5 20
*/
