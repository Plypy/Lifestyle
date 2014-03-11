#include <iostream>
using namespace std;
const int MAXN = 4010;
int n;
unsigned int f[MAXN];
unsigned int MOD = 2<<30;
int main()
{
    cin >> n;
    f[0] = 1;
    for (int i = 1; i < n; ++i)
        for (int j = i; j <= n; ++j)
            f[j] = (f[j]+f[j-i])%MOD;
    cout << f[n] << endl;
    return 0;
}
