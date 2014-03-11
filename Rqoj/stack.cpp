#include <iostream>
using namespace std;
int f[100];
int main()
{
    f[0] = 1;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < i; j++)
            f[i] = f[i]+f[j]*f[i-j-1];
    cout << f[n];
    return 0;
}
