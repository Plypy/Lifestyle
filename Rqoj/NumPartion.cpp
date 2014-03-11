#include <iostream>
using namespace std;
const int MAXN = 100;
int f[MAXN];
int main()
{
    cin >> n;
    f[0] = 1;
    for (int i = 1; i < n; ++i)
        for (int j = i; j <= n; ++j)
            f[j] += f[j-i];
    cout << f[n] << endl;
    return 0;
}
