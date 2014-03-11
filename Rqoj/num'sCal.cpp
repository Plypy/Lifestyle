#include <iostream>
using namespace std;
const int MAXN = 1001;
int f[MAXN];
int main()
{
    int n;
    cin >> n;
    f[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        f[i] = 1;
        for (int j = 1; j <= (i>>1); j++)
            f[i] += f[j];
    }
    cout << f[n];
    return 0;
}
