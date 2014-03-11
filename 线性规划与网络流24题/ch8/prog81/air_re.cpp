#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;
string fname = "air";
const int fnum = 10;
ifstream fin;
ofstream fout;

const int MAXN = 105;
int n, m;
bool g[MAXN][MAXN];
int match[MAXN], rmatch[MAXN];
void init()
{
    n = m = 0;
    memset(g,0,sizeof(g));
    memset(match,0,sizeof(match));
    memset(rmatch,0,sizeof(rmatch));
}
void load()
{
    fin >> n >> m;
    while (true)
    {
        int a, b;
        fin >> a >> b;
        if (a < 0)
            break;
        b -= n;
        g[a][b] = true;
    }
}
bool vis[MAXN];
bool find(int u)
{
    for (int v = 1; v <= m; ++v)
        if (g[u][v] && !vis[v])
        {
            vis[v] = true;
            if (!rmatch[v] || find(rmatch[v]))
            {
                rmatch[v] = u;
                match[u] = v;
                return true;
            }
        }
    return false;
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
