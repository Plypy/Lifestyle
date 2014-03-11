// 统计一定区间内
// 二进制表示中0的个数大于1的个数的数的个数
//  
#include <iostream>
#include <cstdlib>
using namespace std;
typedef unsigned long long ull;
class Problem
{
private:
    static const int MAXN = 35;
    ull st, ed;
    ull f[MAXN][MAXN];
public:
    void init()
    {
        f[0][0] = 1;
        for (int i = 1; i < MAXN; ++i)
        {
            f[i][0] = 1;
            for (int j = 1; j <= i; ++j)
                f[i][j] = f[i-1][j-1]+f[i-1][j];
        }
    }
    ull get(ull num)
    {
        ull dig = 0;
        for (ull t = num; t>0; t>>=1)
            ++dig;
        ull ret = 1;
        for (int i = dig-1; i>0; --i)
            for (int j = 0; j+j+2 <= i; ++j)
                ret += f[i-1][j];
        ull ct = 0;
        for (int i = dig-1; i>=0; --i)
        {
            if (num & (1ULL<<i))
            {
                if (ct>0)
                {
                    for (int j = 1; j <= i && j+ct+j+ct <= dig; ++j)
                        ret += f[i][j];
                }
                ++ct;
                if (ct+ct>dig)
                    break;
                ++ret;
            }
        }
        return ret;
    }
    int run()
    {
        init();
        cin >> st >> ed;
        cout << get(ed)-get(st-1) << endl;
        return 0;
    }
} prob;
int main()
{
    return prob.run();
}
