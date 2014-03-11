//Â©ÁË¡£¡£¡£ 
#include <iostream>
using namespace std;
int n, t;
int f[1080010];
int main()
{
    cin >> n >> t;
    int a, b, c, d, bound;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b >> c >> d;
        bound = min(b,d);
        for (int j = t; j >= bound; j--)
        {
            if (j-b>=0 && f[j-b]+a>f[j])
                f[j] = f[j-b]+a;
            if (j-d>=0 && f[j-d]+c>f[j])
                f[j] = f[j-d]+c;
        }
    }
    cout << f[t];
    return 0;
}
/*
4 10800
18 3600 3 1800
22 4000 12 3000
28 6000 0 3000
32 8000 24 6000
*/
