#include <iostream>
using namespace std;
int main()
{
    typedef unsigned long long ull;
    ull n;
    ull i;
    cin >> n;
    ull bound = n >>1;
    for (int i = 2; i <= bound; i++)
    {
        if (n == 1)
            break;
        while (n % i == 0)
        {
            cout << i << ' ';
            n /= i;
        }
    }
    return 0;
}
