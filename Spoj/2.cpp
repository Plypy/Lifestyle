// 这个题的思路是这样的
// 首先可以看出来数据量非常大，所以绝对不能用普通的方法
// 直接用筛法弄出所有的质数然后进行判断也是不行的
// 空间会不够用，所以考虑到对于任意一个数n
// 将其分解成n=a×b之后，a与b之间必然有一个小于等于sqrt(n)
// 则这就提示我们，只需做出一张sqrt(n)大小质数表
// 然后对每一个区间再使用这张表去筛每个给定区间就可以得解了 
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;

class Problem
{
private:
    static const int MAXN = 32000;
    static const int SLEN = 100010;
    bool parray[MAXN+100];
    int plist[MAXN+100];
    bool tmptable[SLEN+100];
    int t;
public:
    int run()
    {
        for (int i = 2; i < MAXN; ++i)
            if (!parray[i])
            {
                plist[++plist[0]] = i;
                for (int j = (i<<1); j < MAXN; j+=i)
                    parray[j] = true;
            }
        
        cin >> t;
        int lower, upper;
        for (int k = 1; k <= t; ++k)
        {
            cin >> lower >> upper;
            memset(tmptable,0,sizeof(tmptable));
            if (lower == 1)
                ++lower;
            for (int i = 1; i <= plist[0] && plist[i]*plist[i] <= upper; ++i)
            {
                int bg = lower/plist[i];
                int ed = upper/plist[i];
                for (int j = bg; j <= ed; ++j)
                    if (j != 1)
                        tmptable[j*plist[i]-lower] = true;
            }
            for (int i = 0; i <= upper-lower; ++i)
                if (!tmptable[i])
                    cout << i+lower << endl;
        }
//        system("pause");
        return 0;
    }
} prob;
int main()
{
    return prob.run();
}
