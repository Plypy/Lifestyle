/*
    ID : jake1994
    PROG : butter
    LANG : C++
*/
// 此题使用Bellman_Ford+Enumerate the source vertex
#include <iostream>
#include <fstream>
using namespace std;
const int MAXN = 805;
const int MAXE = 1500;
const int INF = 52111425;
int dis[MAXN];
int s[MAXE], t[MAXE], cost[MAXE];
int amt[MAXN];
int n, p, c;
bool relax(int bg, int ed, int wt)
{
    if (dis[ed] > dis[bg]+wt)
    {
        dis[ed] = dis[bg]+wt;
        return true;
    }
    return false;
}
int main()
{
    ifstream fin("butter.in");
    ofstream fout("butter.out");
    fin >> n >> p >> c;
    int id;
    for (int i = 1; i <= n; i++)
    {
        fin >> id;
        amt[id]++;
    }
    for (int i = 1; i <= c; i++)
        fin >> s[i] >> t[i] >> cost[i];
    int ans = INF;
    for (int i = 1; i <= p; i++)
    {
        bool flag;
        for (int j = 1; j <=  p; j++)
            dis[j] = INF;
        dis[i] = 0;
        for (int ct = 0; ct < p; ct++)
        {
            flag = true;
            for (int j = 1; j <= c; j++)
            {
                if (relax(s[j],t[j],cost[j]))
                    flag = false;
                if (relax(t[j],s[j],cost[j]))
                    flag = false;
            }
            if (flag)
                break;
        }
        int tmp = 0;
        for (int j = 1; j <= p; j++)
            tmp += amt[j]*dis[j];
        if (ans > tmp)
            ans = tmp;
    }
    fout << ans << endl;
    return 0;
}
