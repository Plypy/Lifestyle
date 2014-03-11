#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
const int MAXN = 50;
int n;
double d1, c, d2;
double dis[MAXN];
double price[MAXN];
const double INF = 1e10;
double ans;
double maxdis;
void load()
{
    cin >> d1 >> c >> d2 >> price[0] >> n;
    maxdis = c*d2;
    for (int i = 1; i <= n; ++i)
        cin >> dis[i] >> price[i];
    dis[++n] = d1;
}
double min(double a, double b)
{
    return a<b?a:b;
}
bool success;
double rest;
void work()
{
    success = true;
    for (int i = 1; i <= n; ++i)
        if (dis[i]-dis[i-1] > maxdis)
        {
            success = false;
            break;
        }
    if (success)
    {
        double tmp;
        int nxt;
        for (int i = 0; i < n;)
        {
            int j;
            for (j = i+1; j <= n && dis[j]-dis[i] <= maxdis; ++j)
                if (price[j] < price[i])
                    break;
            if (j <= n && (tmp = dis[j]-dis[i]) <= maxdis)
            {
                nxt = j;
                if (rest >= tmp/d2)
                {
                    rest -= tmp/d2;
                }
                else
                {
                    ans += (tmp/d2-rest)*price[i];
                    rest = 0;
                }
            }
            else
            {
                nxt = i+1;
                ans += (c-rest)*price[i];
                rest = c-(dis[i+1]-dis[i])/d2;
            }
            i = nxt;
        }
    }
}
void output()
{
    if (!success)
        cout << "No Solution" << endl;
    else
    {
        cout << fixed << setprecision(2) << ans << endl;
    }
    //system("pause");
}
int main()
{
    load();
    work();
    output();
    return 0;
}
/*
275.6 11.9 27.4 2.8 2
102.0 2.9
220.0 2.2
*/
