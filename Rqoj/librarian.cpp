#include <iostream>
#include <cmath>
using namespace std;
bool check(int num)
{
    int bound = int(sqrt(num));
    for (int i = 2; i <= bound; i++)
        if (num % i == 0)
            return false;
    return true;
}
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int a = 0, b = n;
    int tmp;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &tmp);
        if (tmp < k && tmp > a)
            a = tmp;
        if (tmp > k && tmp < b)
            b = tmp;
    }
    cout << a+b << endl;
    if (check(a+b))
        cout << 'Y';
    else
        cout << 'F';
    return 0;
}
