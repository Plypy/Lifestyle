#include <iostream>
using namespace std;
inline int gcd(int a, int b)
{
    while (b)
    {
        int tmp = b;
        b = a%b;
        a = tmp;
    }
    return a;
}
int main()
{
    int x, y;
    cin >> x >> y;
    int ans = 0;
    if (y % x)
        goto end;
    else
    {
        int k = y/x;
        int tmp;
        for (int i = 1; i <= k; i++)
        {
            if (k % i)
                continue;
            tmp = k/i;
            if (1 != gcd(i,tmp))
                continue;
            ans++;
        }
    }
end: 
    cout << ans;
    return 0;
}
