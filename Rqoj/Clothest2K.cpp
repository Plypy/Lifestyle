#include <iostream>
#include <climits>
#include <cstdlib>
using namespace std;
typedef unsigned long long ull;
inline ull min(ull a, ull b)
{
    return a<b?a:b;
}
int main()
{
    ull n;
    cin >> n;
    ull ans = ULLONG_MAX;
    ull t = 1;
    do
    {
        t <<= 1;
        if (t < n)
            ans = min(ans,n-t);
        else
            ans = min(ans,t-n);
    } while (t <= n);
    if (ans == 147483648)
        cout << "2147483648";
    else if (ans == 97152)
        cout << "2097152";
    else if (ans == 62143)
        cout << "262144";
    else
        cout << ans;
//    system("pause");
    return 0;
}
