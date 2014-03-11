#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int MAXN = 105;
ifstream fin("wire.in");
ofstream fout("wire.out");
/*Kruskal
struct cost
{
    int val;
    int i;
    int j;
} c[MAXN*MAXN];
int f[MAXN];
int ct;
int n;
int ans;
int cmp(const void *a, const void *b)
{
    return ((cost *)a)->val - ((cost *)b)->val;
}
int find(int a)
{
    if (f[a] != a)
        f[a] = find(f[a]);
    return f[a];
}
void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    f[a] = b;
}
int main()
{
    fin >> n;
    for (int i = 1; i <= n; i++)
    {
        f[i] = i;
        for (int j = 1; j <= n; j++)
        {
            fin >> c[++ct].val;
            c[ct].i = i;
            c[ct].j = j;
        }
    }
    qsort(c,n*n,sizeof(cost),cmp);
    ct = 1;
    for (int i = 1; i <= n*n; i++)
    {
        if (find(c[i].i) != find(c[i].j))
        {
            ans += c[i].val;
            merge(c[i].i, c[i].j);
            ++ct;
            if (n == ct)
                break;
        }
    }
    fout << ans;
    fin.close();
    fout.close();
    return 0;
}
running well!!
*/

// Prim
const int INF = 19940306;
int dis[MAXN];
int c[MAXN][MAXN];
int main()
{
    int n;
    fin >> n;
    for (int i = 2; i <= n; i++)
        dis[i] = INF;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            fin >> c[i][j];
    int ans = 0;
    int mi;
    int ad;
    for (int i = 1; i <= n; i++)
    {
        mi = INF;
        for (int j = 1; j <= n; j++)
        {
            if (dis[j] != -1 && mi > dis[j])
            {
                mi = dis[j];
                ad = j;
            }
        }
        ans += dis[ad];
        for (int j = 1; j <= n; j++)
            if (dis[j] > c[ad][j])
                dis[j] = c[ad][j];
        dis[ad] = -1;
    }
    fout << ans;
    fin.close();
    fout.close();
    return 0;
}
//running well!!
