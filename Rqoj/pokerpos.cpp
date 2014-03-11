#include <iostream>
using namespace std;
int main ()
{
    unsigned long long n,m=2,ans;
    cin >> n;
    while (m<n)
        m<<=1;
    ans=m-(m-n)*2;
    cout << ans;
    return 0;
} 
