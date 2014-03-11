#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int x[2], y[2], t;
inline int sqr(int a)
{
    return a*a;
}
int main()
{
    cin >> x[0] >> y[0] >> t >> x[1] >> y[1];
    cout << fixed << setprecision(6) << 2*sqrt(sqr(x[0]-x[1])+sqr(y[0]-y[1]));
    return 0;
}
