#include <iostream>
using namespace std;
int n, i, j;
int a[101];
void ppp(int k)
{
    int i, j, w, s;
    a[1] = 1;
    w = 0;
    for (int i = 1; i <= k; i++)
        for (int j = 1; j <= 100; j++)
        {
            s = a[j]*2+w;
            a[j] = s%10;
            w = s/10;
        }
}
int main()
{
    cin >> n;
    ppp(n+1);
    if (a[1] >= 2)
        a[1] -= 2;
    else
    {
        a[1] = a[1]+8;
        a[2] = a[2]-1;
    }
    i = 100;
    while (a[i] == 0)
        i--;
    for (int j = i; j >= 1; j--)
        cout << a[j];
    return 0;
}
