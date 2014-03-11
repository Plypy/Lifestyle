#include <iostream>
using namespace std;
int main()
{
    int a, b;
    while (cin >> a)
    {
        cout << (a>>1) << ' ' << a/2;
    }
    return 0;
}
