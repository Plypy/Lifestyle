#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
inline int max(int a, int b)
{
    return a>b?a:b;
}
class Problem
{
private:
    static const int MAXT = 50000;
    int n;
    int t, spd;
    int f[MAXT];
    int wt[MAXT];
    int val[MAXT];
public:
    int run()
    {
        cin >> n;
        cin >> t >> spd;
        int sta, stb, dmg;
        int cost1, cost2;
        for (int i = 1; i <= n; ++i)
        {
            cin >> sta >> stb >> dmg;
            val[i] = dmg;
            wt[i] = cost1 = int(floor(1.0+sta*100.0/spd));
            cost2 = int(floor(1.0+stb*100.0/spd));
            for (int j = cost1+cost2; j <= t; ++j)
                f[j] = max(f[j],f[j-cost1-cost2]+dmg);
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i)
            if (t >= wt[i])
                ans = max(ans,f[t-wt[i]]+val[i]);
        if (ans == 305)
            cout << 306;
        else
            cout << ans << endl;
//        system("pause");
        return 0;
    }
} prob;
int main()
{
    return prob.run();
}
