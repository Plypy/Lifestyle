#include <iostream>
using namespace std;
void div(int a)
{
    int ct1 = 0;
    if (a == 2 || a == 0)
    {
        cout << a;
        return;
    }
    for (int i = 20; i >= 0; i--)
    {
        if (a&(1<<i))
            ct1++;
    }
    int ct2 = 0;
    for (int i = 20; i >= 0; i--)
    {
        if (a&(1<<i))
        {
            ct2++;
            if (i == 1)
            {
                cout << 2;
            }
            else
            {
                cout << "2(";
                div(i);
                cout << ")";
            }
            if (ct2 < ct1)
            {
                cout << "+";
            }
        }
    }
}
int main()
{
    int n;
    //while (1)
    //{
        cin >> n;
        div(n);
        //cout << endl;
        //system("pause");
        //cout << endl;
    //}
    return 0;
}
