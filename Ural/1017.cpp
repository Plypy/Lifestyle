#include <iostream>
#include <cstdlib>
using namespace std;
typedef unsigned long long ull;
const int MAXN = 505;
ull f[MAXN];
int n;
int main()
{
    cin >> n;
    f[0] = 1;
    for (int i = 1; i < n; ++i)
        for (int j = n; j >= i; --j)
            f[j] += f[j-i];
    cout << f[n] << endl;
    //system("pause");
    return 0;
}
