#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        cout << a << ' ' << b;
        int maxop = 0;
        if (a > b)
            swap(a,b);
        for (int i = a; i <= b; ++i)
        {
            int t = i;
            int ct = 1;
            while (t != 1)
            {
                if (t & 1)
                    t = 3*t+1;
                else
                    t >>= 1;
                ++ct;
            }
            if (ct > maxop)
                maxop = ct;
        }
        cout << ' ' << maxop << endl;
    }
    //system("pause");
    return 0;
}
