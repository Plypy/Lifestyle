#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
string fname = "path";
const int fnum = 10;
ifstream fin;
ofstream fout;

const int MAXN = 150;
int n, m;
bool g[MAXN][MAXN];
bool vis[MAXN];
int rmatch[MAXN];

bool find(int u)
{
    for (int v = 1; v <= n; ++v)
        if (g[u][v] && !vis[v])
        {
            vis[v] = true;
            if (!rmatch[v] || find(rmatch[v]))
            {
                rmatch[v] = u;
                return true;
            }
        }
    return false;
}
void init()
{
    n = 0;
    memset(g,0,sizeof(g));
    memset(vis,0,sizeof(vis));
    memset(rmatch,0,sizeof(rmatch));
}
void load()
{
    fin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int a, b;
        fin >> a >> b;
        g[a][b] = true;
    }
}
void work()
{
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        memset(vis,0,sizeof(vis));
        if (find(i))
            ++ans;
    }
    ans = n-ans;
    fout << ans << endl;
}

string modify(string iname, int id)
{
    const int BUFSIZE = 20;
    int buf[BUFSIZE] = {0};
    int bsize = 0;
    if (0 == id)
        return iname+'0';
    while (id)
    {
        buf[++bsize] = id%10;
        id /= 10;
    }
    for (int i = bsize; i; --i)
        iname += char('0'+buf[i]);
    return iname;
}

int main()
{
    for (int i = 0; i <= fnum; ++i)
    {
        string cur_name = modify(fname,i);
        fin.open((cur_name+".in").c_str());
        fout.open((cur_name+".ans").c_str());

        init();
        load();
        work();

        fin.close();
        fout.close();
    }
    return 0;
}
