#include <iostream>
#include <limits.h>
using namespace std;
int cost[11];
int f[110];
int main()
{
    for (int i = 1; i <= 10; i++)
        cin >> cost[i];
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        f[i] = INT_MAX;
    for (int i = 1; i <= 10; i++)
        for (int j = i; j <= n; j++)
            if (f[j-i]+cost[i] < f[j])
                f[j] = f[j-i]+cost[i];
    cout << f[n];
    return 0;
}
