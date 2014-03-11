#include <iostream>
#include <cstdlib>
using namespace std;
const int MAXT = 1001;
const int MAXN = 105;
int f[MAXT];
int val[MAXN];
int cost[MAXN];
int t, n;
int main()
{
    cin >> t >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i] >> val[i];
        for (int j = t; j >= cost[i]; j--)
            if (f[j] < f[j-cost[i]]+val[i])
                f[j] = f[j-cost[i]]+val[i];
    }
    cout << f[t] << endl;
    return 0;
}
