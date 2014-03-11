#include <iostream>
#include <cstdlib>
using namespace std;
typedef unsigned long long ull;
ull d, e, f, dp, ep, h;
ull hd, he;
ull t;
int main()
{
    cin >> d >> e >> f >> dp >> ep >> h;
    t = (1<<f)-1;
    dp += t;
    ep += t;
    hd = f-d+1;
    he = f-e+1;
    dp >>= d;
    ep >>= e;
    ull len = 0;
    while (dp != ep)
    {
        if (hd > he)
        {
            --hd;
            dp >>= 1;
            ++len;
        }
        else if (hd < he)
        {
            --he;
            ep >>= 1;
            ++len;
        }
        else
        {
            len += 2;
            dp >>= 1;
            ep >>= 1;
            --he;
            --hd;
        }
    }
    if (len <= h)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    //system("pause");
    return 0;
}
