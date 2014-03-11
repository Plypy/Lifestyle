#include <iostream>
#include <cmath>
using namespace std;
int sub, sup;
int ct;
int facsum(int num)
{
    int bound = int(sqrt(num));
    int ret = 1;
    for (int i = 2; i < bound; i++)
        if (num%i == 0)
        {
            ret += i+num/i;
        }
    if (bound*bound == num)
        ret += bound;
    return ret;
}
int main()
{
    cin >> sub >> sup;
    for (int i = sub; i <= sup; i++)
    {
        int t1 = facsum(i);
        if (t1 > i)
            if (i == facsum(t1))
                ct++;
    }
    cout << ct;
    //system("pause");
    return 0;
}
