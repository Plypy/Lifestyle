#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
double p, q;
const double om = 1e-7;
int main()
{
    cin >> p >> q;
    p /= 100;
    q /= 100;
    for (int i = 1; true; ++i)
    {
        int x = int(i*p);
        int y = int(i*q);
        if (x < y && fabs(x-i*p)>om && fabs(y-i*q)>om)
        {
            cout << i << endl;
            break;
        }
    }
    //system("pause");
    return 0;
}
