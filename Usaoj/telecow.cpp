/*
    ID : jake1994
    PROG : telecow
    LANG : C++
*/
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
ifstream fin("telecow.in");
ofstream fout("telecow.out");
const int MAXN = 210;
const int INF = 100000;
int n, m, s, t;
int n2;
int f[MAXN][MAXN];
void load()
{
    fin >> n >> m >> s >> t;
    int a, b;
    for (int i = 1; i <= n; i++)
        f[i][i+n] = 1;
    for (int i = 1; i <= m; i++)
    {
        fin >> a >> b;
        f[a+n][b] = INF;
        f[b+n][a] = INF;
    }
    n2 = n<<1;
}
int g[MAXN][MAXN];
bool found;
int ht[MAXN];
int hct[MAXN];
int flow;
int min(int a, int b)
{
    return a<b?a:b;
}
void aug(int u)
{
    if (u == t)
    {
        found = true;
        flow += 1;
        return;
    }
    int v;
    int minh = n2-1;
    if (u <= n)
    {
        v = u+n;
        if (g[u][v])
        {
            if (ht[v]+1 == ht[u])
            {
                aug(v);
                if (ht[s+n]>=n2)
                    return;
            }
            minh = min(minh,ht[v]);
        }
    }
    else
    {
        for (v = 1; v <= n; v++)
        {
            if (g[u][v]>0)
            {
                if (ht[v]+1 == ht[u])
                {
                    aug(v);
                    if (ht[s+n] >= n2)
                        return;
                    if (found)
                        break;
                }
                minh = min(minh,ht[v]);
            }
        }
    }
    if (found)
    {
        g[u][v] -= 1;
        g[v][u] += 1;
    }
    else
    {
        hct[ht[u]]--;
        if (hct[ht[u]==0])
            ht[s+n] == n2;
        ht[u] = minh+1;
        hct[ht[u]]++;
    }
}
void show()
{
    for (int i = 1; i <= n2; i++)
    {
        for (int j = 1; j <= n2; j++)
            fout << f[i][j] << ' ';
        fout << endl;
    }
}
int sap()
{
    memset(hct,0,sizeof(hct));
    memset(ht,0,sizeof(ht));
    memcpy(g,f,sizeof(f));
    flow = 0;
    hct[0] = n2;
    while (ht[s+n] < n2)
    {
        found = false;
        aug(s+n);
    }
    //show();
    return flow;
}
void work()
{
    int num = sap();
    fout << num << endl;
    int ct = 0;
    bool flag = false;
    for (int i = 1; num && i <= n; i++)
    {
        if (i == s || i == t)
            continue;
        f[i][i+n] = 0;
        int t = sap();
        if (t < num)
        {
            num = t;
            if (flag)
                fout << ' ';
            fout << i;
            flag = true;
        }
        else
            f[i][i+n] = 1;
    }
    fout << endl;
}
int main()
{
    load();
    work();
    return 0;
}
