//×ÐÏ¸¶ÁÌâ°¡...±¿µ° 
#include <iostream>
#include <cstdlib>
using namespace std;
const int MAXN = 45;
int f[MAXN];
int n, k;
void load()
{
    cin >> n >> k;
}
void work()
{
    f[0] = 1;
    f[1] = 2;
    for (int i = 2; i <= n; ++i)
        f[i] = f[i-1]+f[i-2];
    if (k > f[n])
        cout << -1 << endl;
    else
    {
        for (int i = n; i; --i)
        {
            if (k > f[i-1])
            {
                cout << 1;
                k -= f[i-1];
            }
            else
            {
                cout << 0;
            }
        }
    }
    cout << endl;
    //system("pause");
}
int main()
{
    load();
    work();
    return 0;
}
