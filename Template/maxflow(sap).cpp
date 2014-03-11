#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
string fname = "shut";
const int fnum = 10;
ifstream fin;
ofstream fout;

const int INF = 1<<28;
const int MAXN = 55;

const int MAXV = MAXN*2;
const int MAXE = MAXV*MAXV;
int vs, vt, vtot;
struct Edge
{
    int vtx, cap;
    Edge *nxt, *rev;
    Edge() {}
    Edge(int iv, int ic, Edge *in, Edge *ir):
        vtx(iv), cap(ic), nxt(in), rev(ir) {}
} epool[MAXE], *adj[MAXV], *eptr;

void add(int u, int v, int cap)
{
    adj[u] = new (eptr++) Edge(v,cap,adj[u],eptr);
    adj[v] = new (eptr++) Edge(u,0,adj[v],eptr-2);
}

int ht[MAXV], hct[MAXV];
int aug(int u, int augc)
{
    if (u == vt)
    {
        return augc;
    }
    int minht = vtot-1;
    int rem = augc;
    for (Edge *t = adj[u]; t; t = t->nxt)
        if (t->cap)
        {
            int v = t->vtx;
            if (ht[v]+1 == ht[u])
            {
                int d = aug(v,min(t->cap,rem));
                rem -= d;
                t->cap -= d;
                t->rev->cap += d;
                if (!rem)
                    return augc;
                if (ht[vs] >= vtot)
                    return augc-rem;
            }
            minht = min(minht,ht[v]);
        }
    if (augc == rem)
    {
        --hct[ht[u]];
        if (!hct[ht[u]])
            ht[vs] = vtot;
        ht[u] = minht+1;
        ++hct[ht[u]];
    }
    return augc-rem;
}
int sap()
{
    int ret = 0;
    hct[0] = vtot;
    while (ht[vs] < vtot)
        ret += aug(vs,INF);
    return ret;
}

void init()
{
    vs = vt = vtot = 0;
    eptr = epool;
    memset(adj,0,sizeof(adj));
    memset(ht,0,sizeof(ht));
    memset(hct,0,sizeof(hct));
}

int n, m;
int ans;
void load()
{
    fin >> n >> m;
    ans = 0;
    vs = 0;
    vt = n+m+1;
    vtot = n+m+2;
    for (int i = 1; i <= n; ++i)
    {
        int t;
        fin >> t;
        add(vs,i,t);
        ans += t;
        while (fin.get() != '\n')
        {
            fin >> t;
            add(i,t+n,INF);
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        int t;
        fin >> t;
        add(i+n,vt,t);
    }
}
void work()
{
    fout << ans-sap() << endl;
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

