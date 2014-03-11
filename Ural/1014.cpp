#include <iostream>
#include <cstdlib>
using namespace std;
int list[1000];
int main()
{
    int n;
    cin >> n;
    if (0 == n)
    {
        cout << 10 << endl;
        return 0;
    }
    if (1 == n)
    {
        cout << 1 << endl;
        return 0;
    }
    bool flag = true;
    while (n!=1 && flag)
    {
        flag = false;
        for (int i = 9; i >= 2; i--)
        {
            if (n%i == 0)
            {
                n/=i;
                list[++list[0]] = i;
                flag = true;
                break;
            }
        }
    }
    if (!flag)
        cout << -1 << endl;
    else
    {
        for (int i = list[0]; i; i--)
            cout << list[i];
        cout << endl;
    }
    //system("pause");
    return 0;
}
