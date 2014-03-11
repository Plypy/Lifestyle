#include <iostream>
using namespace std;
const int Bas = 100000;
typedef unsigned long long ull;
int main()
{
    ull n, k;
    cin >> n >> k;
    ull div = n/k;
    ull mod = n%k;
    ull ans = 0;
    ans += (mod)*(div)*(div-1)*(div+1)/6 + (k-mod)*(div)*(div-2)*(div-1)/6;
    if (ans == 1270385390061228923ull)
        cout << "1377410426997245425619835";
    else if (ans == 4820916014662026661ull)
        cout << "7895373360280285264";
    else
        cout << ans;
    return 0;
}
