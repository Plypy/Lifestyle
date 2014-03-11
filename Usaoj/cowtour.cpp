/*
    ID : jake1994
    PROG : cowtour
    LANG : C++
*/
#include <cfloat>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
const int MAXN = 155;
double dis[MAXN][MAXN];
int x[MAXN], y[MAXN];
double mdis[MAXN];
const double flag = 1e50;
inline double cal(int a, int b)
{
    int c, d;
    c = x[a]-x[b];
    d = y[a]-y[b];
    return sqrt(c*c+d*d);
}
int main()
{
    ifstream fin("cowtour.in");
    ofstream fout("cowtour.out");
    int n;
    fin >> n;
    for (int i = 1; i <= n; i++)
        fin >> x[i] >> y[i];
    char ch;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            fin >> ch;
            if (ch == '1')
                dis[i][j] = cal(i,j);
            else if (i == j)
                dis[i][j] = 0;
            else
                dis[i][j] = flag;
        }
    double tmp;
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (dis[i][j] > (tmp=dis[i][k]+dis[k][j]))
                    dis[i][j] = tmp;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (dis[i][j] != flag && mdis[i] < dis[i][j])
                mdis[i] = dis[i][j];
    double ans = flag;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (dis[i][j] == flag)
                if (ans > (tmp=mdis[i]+mdis[j]+cal(i,j)))
                    ans = tmp;
    for (int i = 1; i <= n; i++)
        if (mdis[i] > ans)
            ans = mdis[i];
    fout << setprecision(6) << setiosflags(ios::fixed|ios::showpoint) << ans << endl;
    return 0;
}
