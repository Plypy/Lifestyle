#include <iostream>
using namespace std;
const int MAXT = 100000;
int mem[MAXT];
typedef unsigned long long ull;
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        ull a, b;
        cin >> a >> b;
        if (a > b)
        {
            a ^= b;
            b ^= a;
            a ^= b;
        }
        int max = 0;
        for (ull j = a; j <= b; ++j)
        {
            ull test = j;
            int ct = 0;
            while (test != 1)
            {
                if (test < MAXT && mem[test])
                {
                    ct += mem[test];
                    break;
                }
                if (test & 1)
                    test = test*3+1;
                else
                    test >>= 1;
                ++ct;
            }
            if (j < MAXT)
                mem[j] = ct;
            max >?= ct;
        }
        cout << max << endl;
    }
    return 0;
}

