#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
double val[2];
double ma;
double k;
int st, ed;
int n;
int main()
{
    cin >> n;
    cin >> val[1];
    for (int i = 2; i <= n; ++i)
    {
        cin >> val[i&1];
        k = fabs(val[i&1]-val[(i-1)&1]);
        if (k > ma)
        {
            ma = k;
            st = i-1;
            ed = i;
        }
    }
    cout << st << ' ' << ed << endl;
    //system("pause");
    return 0;
}
