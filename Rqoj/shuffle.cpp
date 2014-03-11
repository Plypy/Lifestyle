#include <iostream>
using namespace std;
int main()
{
    unsigned long long n, ct = 0;
    cin >> n;
    int pos = 1;
    do
    {
        if (pos <= n)
            pos = pos*2;
        else
            pos = (pos-n)*2-1;
        ct++;
    } while (pos != 1);
    cout << ct;
    return 0;
}
