#include <iostream>
#include <cmath>
using namespace std;
const double SMALL = 1e-6;
bool check(double val)
{
    if (abs(val-int(val))<SMALL)
        return true;
    return false;
}
int main()
{
    int n;
    cin >> n;
    bool first = true;
    for (int i = 1; i <= n; ++i)
    {
        double t;
        cin >> t;
        if (first)
            first = false;
        else
            cout << ' ';
        if (check(sqrt(8*t-7)))
            cout << 1;
        else
            cout << 0;
    }
    cout << endl;
    return 0;
}
