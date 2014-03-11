#include <iostream>
using namespace std;
int main()
{
    const int bas = 100000000;
    long long t=1;
    long long n;
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        t*=i;
        while (t%10==0)
            t/=10;
        t%=bas;
    }
    cout << t%10;
    return 0;
}
