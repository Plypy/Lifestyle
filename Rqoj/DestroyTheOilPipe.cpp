#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 140;
int net[MAXN][MAXN];
int bg[MAXN*MAXN];
int ed[MAXN*MAXN];
int n, m, s, t;
void load()
{
//    freopen("test.in", "r", stdin);
//    freopen("test.out", "w", stdout);
    cin >> n >> m >> s >> t;
    int a, b, c;
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b >> c;
        bg[i] = a, ed[i] = b;
        net[a][b] = net[b][a] = c;
    }
}
int anslist[MAXN*MAXN];
int ct=0;
int hct[MAXN];
int hit[MAXN];
int delta;
bool found;
const int INF = 0x7fffffff;
int min(int a, int b)
{
    return a<b?a:b;
}
int flow;
void aug(int u)
{
    if (u == t)
    {
        flow += delta;
        found = true;
        return;
    }
    int backup = delta;
    int minhit = n-1;
    int v;
    for (v = 1; v <= n; v++)
        if (net[u][v] > 0)
        {
            if (hit[v]+1 == hit[u])
            {
                delta = min(delta,net[u][v]);
                aug(v);
                if (hit[s] >= n)
                    return;
                if (found)
                    break;
                delta = backup;
            }
            minhit = min(minhit,hit[v]);
        }
    if (found)
    {
        net[u][v] -= delta;
        net[v][u] += delta;
    }
    else
    {
        hct[hit[u]]--;
        if (hct[hit[u]] == 0)
            hit[s] = n;
        hit[u] = minhit+1;
        hct[hit[u]]++;
    }
}
void sap()
{
    hct[0] = n;
    while (hit[s] < n)
    {
        found = false;
        delta = INF;
        aug(s);
    }
}
void floyd()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                net[i][j] = net[i][j] || (net[i][k]&&net[k][j]);
}
void getpipe()
{
    for (int i = 1; i <= m; i++)
        if (net[bg[i]][ed[i]] == 0 || net[ed[i]][bg[i]] == 0)
            anslist[++ct] = i;
//    cout << flow << endl;
    cout << ct << endl;
    for (int i = 1; i <= ct; i++)
        cout << anslist[i] << endl;
}
void work()
{
    sap();
    floyd();
    getpipe();
}
int main()
{
    load();
    work();
    return 0;
}
