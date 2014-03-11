#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int n,k;
string seq;
int g[41] = { 0 };
typedef unsigned long long ull;
ull f[41][31] = { 0 };

inline ull max(ull a, ull b)
{
    return a>b?a:b;
}

ull getnum(int b, int c)
{
    ull temp = 0;
    for(int i = b; i <= c; i++)
    {
        temp = (temp*10 + g[i]);
    }
    return temp;
}

int main()
{
    cin >> n >> k >> seq;
    k++;
    char buf[n];
    strcpy(buf,seq.c_str());
    for(int i = 0; i< n; i++)
    {
        g[i+1] = buf[i] - '0';
    }
    for(int i = 1; i <= n; i ++)
    {
        f[i][1] = getnum(1,i);
    }
    for(int j = 2; j <= k; j++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int k = 1; k < i; k++)
            {
                f[i][j] = max( f[i][j] , f[k][j-1]*getnum(k+1,i) );
            }
        }
    }
    cout << f[n][k];
    return 0;
}
