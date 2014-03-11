#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
string fname = "ball";
const int fnum = 10;
ifstream fin;
ofstream fout;

const int MAXN = 2005;

const int MAXV = MAXN*2;
const int MAXE = MAXV*MAXV;
const int INF = 1<<28;
int vs, vt;
struct Edge {
    int vtx, cap;
    Edge *nxt, *rev;
    Edge() { }
    Edge(int iv, int ic, Edge *in, Edge *ir):
        vtx(iv), cap(ic), nxt(in), rev(ir) { }
} epool[MAXE], *adj[MAXV], *stae[MAXV], *p[MAXV], *eptr = epool;
inline void add(int u, int v, int cap) {
    adj[u] = new (eptr++) Edge(v,cap,adj[u],eptr);
    adj[v] = new (eptr++) Edge(u,0,adj[v],eptr-2);
}
int stap[MAXV], lv[MAXV];
bool label() {
    memset(lv,-1,sizeof(lv));
    lv[vs] = 0;
    int head, tail;
    stap[head=tail=0] = vs;
    int u, v;
    while (head <= tail) {
        u = stap[head++];
        for (Edge *t = adj[u]; t; t = t->nxt)
            if (t->cap && -1 == lv[v=t->vtx]) {
                lv[v] = lv[u]+1;
                if (vt == v)
                    return true;
                stap[++tail] = v;
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
    memset(adj,0,sizeof(adj));
    eptr = epool;
}
int n;
void load()
{
    fin >> n;
    vs = 0;
    vt = MAXV-1;
}
void update(int t) {
    add(vs,t,1);
    add(t+MAXN,vt,1);
    for (int i = 1; i < t; ++i) {
        double tmp = sqrt(i+t);
        if (int(tmp) == tmp)
            add(i,t+MAXN,1);
    }
}
void work()
{
    int ans = 0, sum = 0;
    while (ans-sum <= n) {
        update(++ans);
        sum += dinic();
    }
    fout << --ans << endl;
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
