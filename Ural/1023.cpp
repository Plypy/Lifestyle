//如果有K个东西 
//每次最多能取L个 
//那么对于任意连续的两次取东西
//无论第一个人取多少
//第二个人总能取一个数,使得这两次取数的总和为L+1
//那么如果K是（L+1）的倍数，第一个人必然是会输的
//否则第一个人必然是能赢得 
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
int main()
{
    int k;
    cin >> k;
    int bound = int(sqrt(double(k)));
    for (int i = 3; i <= bound; ++i)
        if (k%i == 0)
        {
            cout << i-1 << endl;
            return 0;
        }
    if (k&1)
        cout << k-1 << endl;
    else
    {
        int t = (k>>1)-1;
        if (t < 2)
            t = k-1;
        cout << t << endl;
    }
    return 0; 
}
