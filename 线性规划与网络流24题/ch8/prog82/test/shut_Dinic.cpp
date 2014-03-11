#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;
string fname = "shut";
const int fnum = 10;
ifstream fin;
ofstream fout;

const int MAXN = 55;
const int INF = 1<<28;
const int MAXV = MAXN*2;
const int MAXE = MAXV*MAXV;
int vs, vt;
struct Edge {
    int vtx, cap;
    Edge *nxt, *rev;
    Edge() {}
    Edge(int iv, int ic, Edge *in, Edge *ir):
        vtx(iv), cap(ic), nxt(in), rev(ir) { }
} epool[MAXE], *adj[MAXV], *eptr = epool, *stae[MAXV], *p[MAXV];
// epool静态存储各边数据的内存池 adj各点的邻接表
// eptr用来标记内存池写入位置的变量
// stae非递归增广过程中需要用到的存储增光路经的栈
// p非递归增广过程中用来记录每个点用了哪些边
inline void add(int u, int v, int cap) {
    adj[u] = new (eptr++) Edge(v,cap,adj[u],eptr);
    adj[v] = new (eptr++) Edge(u,0,adj[v],eptr-2);
}

int lv[MAXV], stap[MAXV];
bool label() {
    int head, tail;
    stap[head=tail=0] = vs;
    memset(lv,-1,sizeof(lv));
    lv[vs] = 0;
    while (head<=tail) {
        int u = stap[head++];
        for (Edge *t = adj[u]; t; t = t->nxt) {
            int v = t->vtx;
            if (t->cap && -1 == lv[v]) {
                lv[v] = lv[u]+1;
                if (v == vt)
                    return true;
                stap[++tail] = v;
            }
        }
    }
    return false;
}
int aug() {
    int ret = 0;
    for (int i = vs; i <= vt; ++i)
        p[i] = adj[i];
    int stop = 1;
    stap[stop] = vs;
    int u, v;
    while (stop) {
        u = stap[stop];
        if (u != vt) {
            for (; p[u]; p[u] = p[u]->nxt)
                if (p[u]->cap && lv[u]+1 == lv[v=p[u]->vtx])
                    break;
            if (p[u]) {
                stap[++stop] = v;
                stae[stop] = p[u];
            } else
                --stop, lv[u] = -1;
        } else {
            int delta = INF;
            for (int i = stop; i >= 2; --i)
                if (stae[i]->cap < delta)
                    delta = stae[i]->cap;
            ret += delta;
            for (int i = stop; i >= 2; --i) {
                stae[i]->cap -= delta;
                stae[i]->rev->cap += delta;
                if (!stae[i]->cap)
                    stop = i-1;
            }
        }
    }
    return ret;
}
int dinic() {
    int ret = 0;
    while (label())
        ret += aug();
    return ret;
}

void init()
{
    eptr = epool;
    memset(adj,0,sizeof(adj));

}
int n, m, ans;
void load()
{
    fin >> n >> m;
    ans = 0;
    vs = 0;
    vt = n+m+1;
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
    fout << ans-dinic() << endl;
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
