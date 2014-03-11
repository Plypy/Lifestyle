#include <iostream>
#include <map>
#include <string>
#include <cstdlib>
using namespace std;
map<string, int> nameid;
const int MAXN = 110;
int n;
int ct;
string namelist[MAXN<<1];
const int TEMPORARY = 52111424;
const int PERMANENT = 52111425;
bool flag[MAXN][MAXN];
struct EDGE
{
    int st;
    int ed;
    int wt;
    EDGE(int _st = 0, int _ed = 0, int _wt = 0):
        st(_st), ed(_ed), wt(_wt){ }
} edge[MAXN];
int source;
void load()
{
    cin >> n;
    string na, nb;
    int a, b, c;
    for (int i = 1; i <= n; ++i)
    {
        cin >> na >> nb >> c;
        if (nameid.find(na) == nameid.end())
        {
            nameid[na] = ++ct;
            namelist[ct] = na;
        }
        if (nameid.find(nb) == nameid.end())
        {
            nameid[nb] = ++ct;
            namelist[ct] = nb;
        }
        a = nameid[na];
        b = nameid[nb];
        if (-1 == c)
            c = TEMPORARY;
        edge[i] = EDGE(b,a,c);
    }
    source = nameid[string("ZMC")];
}
string furthestman = "z";
int furthestdist = 0;
int dis[MAXN<<1];
void work()
{
    for (int i = 1; i <= ct; ++i)
        dis[i] = PERMANENT;
    dis[source] = 0;
    int ta, tb, tc;
    for (int t = 1; t <= ct; ++t)
    {
        bool flag = true;
            for (int i = 1; i <= n; ++i)
            {
                ta = edge[i].st;
                tb = edge[i].ed;
                tc = edge[i].wt;
                if (dis[tb] > dis[ta]+tc)
                {
                    flag = false;
                    dis[tb] = dis[ta]+tc;
                }
                if (dis[tb] == PERMANENT && (dis[ta] == TEMPORARY || tc == TEMPORARY))
                {
                    flag = false;
                    dis[tb] = TEMPORARY;
                }
            }
        if (flag)
            break;
    }
    for (int i = 1; i <= ct; ++i)
    {
        if (dis[i] > furthestdist)
        {
            furthestdist = dis[i];
            furthestman = namelist[i];
        }
        else if (dis[i] == furthestdist && furthestman > namelist[i])
        {
            furthestdist = dis[i];
            furthestman = namelist[i];
        }
    }
}
void output()
{
    
    cout << furthestman << ' ';
    if (furthestdist == PERMANENT)
        cout << -2;
    else if (furthestdist == TEMPORARY)
        cout << -1;
    else
        cout << furthestdist;
    cout << endl;
}
int main()
{
    load();
    work();
    output();
    //system("pause");
    return 0;
}
/*
4
TOM FX 3
FX TOM 2
TOM Q 4
Q ZMC 3

FX 9
*/
