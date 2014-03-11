#include <iostream>
using namespace std;
int main()
{
    int n, m, t;
    int a[1001] = {0};
    int b[1001] = {0};
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++)
        scanf("%d", a+i);
    int ct;
    for (ct = 1; ct <= n; ct++)
        if (m == a[ct])
            break;
    for (int i = 1; i < ct; i++)
        a[n+i] = a[i];
    for (int i = 1; i <= n; i++)
    {
        if (t >= i)
            b[a[i]] = a[ct+t-i];
        else
            b[a[i]] = a[ct+t+n-i];
    }
    for (int i = 1; i < n; i++)
        printf("%d ", b[i]);
    printf("%d", b[n]);
    return 0;
}
