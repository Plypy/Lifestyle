// f[i][j] i>j表示当走得快的人走到了i走得慢的人走到了j的时候所走的最短路径 
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
using namespace std;
const int MAXN = 110;
double x[MAXN], y[MAXN];
int n;
void load()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> x[i] >> y[i];
}
double dis(int a, int b)
{
    return sqrt(pow(x[a]-x[b],2)+pow(y[a]-y[b],2));
}
double INF = 1e10;
double f[MAXN][MAXN];
void work()
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            f[i][j] = INF;
    f[1][1] = 0;
    for (int i = 2; i <= n; ++i)
        for (int j = 1; j < i; ++j)
        {
            f[i][j] = min(f[i][j], f[i-1][j]+dis(i-1,i));
            f[i][i-1] = min(f[i][i-1], f[i-1][j]+dis(i,j));
        }
    double ans;
    for (int i = n; i; --i)
        ans = min(ans,f[n][i]+dis(n,i));
    cout << fixed << setprecision(2) << ans << endl;
}
int main()
{
    load();
    work();
    return 0;
}

