#include <iostream>
using namespace std;
const int MAXN = 501;
int f[MAXN];
int n, v;
int main()
{
    cin >> n >> v;
    int m, w, s, amt, mas, val;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d",&m,&w,&s);
        amt = 1;
        while (1)
        {
            if (amt >= m)
            {
                val = s*m;
                mas = w*m;
                for (int j = v; j >= mas; j--)
                    f[j] >?= f[j-mas]+val;
                break;
            }
            val = s*amt;
            mas = w*amt;
            for (int j = v; j >= mas; j--)
                f[j] >?= f[j-mas]+val;
            m = m-amt;
            amt <<= 1;
        }
    }
    cout << f[v];
    return 0;
}
