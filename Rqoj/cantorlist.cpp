#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ct = 0;
    while (1)
    {
        ++ct;
        if (n > ct)
            n -= ct;
        else
            break;
    }
    if (ct%2 == 0)
        n = ct-n+1;
    int son = ct;
    int mom = 1;
    n--;
    while (n)
    {
        son--;
        mom++;
        n--;
    }
    cout << son << '/' << mom;
    return 0;
}
