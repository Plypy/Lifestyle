#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
const int MAXN = 105;
double x[MAXN];
double y[MAXN];
int n;
bool load()
{
    if (cin >> n)
    {
        for (int i = 1; i <= n; ++i)
            cin >> x[i] >> y[i];
        return true;
    }
    return false;
}
double dis(int i, int j)
{
    return sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2));
}
const double INF = 1e10;
inline double min(double a, double b)
{
    return a<b?a:b;
}
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
            f[i][j] = min(f[i][j],f[i-1][j]+dis(i-1,i));
            f[i][i-1] = min(f[i][i-1],f[i-1][j]+dis(i,j));
        }
    double ans = INF;
    for (int i = n-1; i; --i)
        ans = min(ans,f[n][i]+dis(n,i));
    cout << ans << endl;
}
void init()
{
    cout << fixed << setprecision(2);
}
int main()
{
    init();
    while (load())
        work();
    return 0;
}
