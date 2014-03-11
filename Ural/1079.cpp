#include <iostream>
using namespace std;
const int MAXN = 100000;
int a[MAXN], f[MAXN];
inline int max(int a, int b)
{
    return a>b?a:b;
}
int main()
{
    a[1] = f[1] = 1;
    for (int i = 2; i < MAXN; i++)
    {
        if (i&1)
            a[i] = a[i>>1]+a[(i>>1)+1];
        else
            a[i] = a[i>>1];
        f[i] = max(f[i-1],a[i]);
    }
    int n;
    while (1)
    {
        cin >> n;
        if (!n)
            break;
        cout << f[n] << endl;
    }
    return 0;
}
