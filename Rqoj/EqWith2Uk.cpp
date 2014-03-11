#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    int a, b, c, d, e, f;
    cin >> a >> b >> c;
    cin >> d >> e >> f;
    int d0 = a*e-d*b;
    int d1 = c*e-f*b;
    int d2 = a*f-c*d;
    if ((d1/d0)*d0 == d1 && (d2/d0)*d0 == d2)
        cout << d1/d0 << ' ' << d2/d0 << endl;
    else
        cout << "NO INTEGER ROOT" << endl;
//    system("pause");
    return 0;
}
