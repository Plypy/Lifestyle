#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
const int MAXN = 901;
int list[MAXN];
int energy(int a, int b)
{
    int c[20] = {0}, d[20] = {0};
    int i = 0;
    while (a)
    {
        c[i++] = a%7;
        a /= 7;
    }
    int dig = i;
    i = 0;
    while (b)
    {
        d[i++] = b%7;
        b /= 7;
    }
    dig >?= i;
    int res = 0;
    for (i = 0; i < dig; i++)
        if (c[i] != d[i])
            res += 1<<i;
    return res;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> list[i];
    int ans = 0;
    int tmp;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j)
            {
                if (abs((tmp = energy(list[i],list[j]))-123) < abs(ans-123))
                    ans = tmp;
                if (123 == ans)
                    goto label;
            }
    label:
    cout << ans;
    return 0;
}
