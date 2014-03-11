#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    string tmp;
    cin >> tmp;
    int ct = 0;
    int tot = 0;
    int len = tmp.size();
    for (int i = 0; i < len-1; i++)
    {
        if (tmp[i] != '-')
        {
            ++ct;
            tot += (tmp[i]-'0')*ct;
        }
    }
    tot %= 11;
    if (tmp[len-1]-'0' == tot || (tot == 10 && tmp[len-1] == 'X'))
        cout << "Right" << endl;
    else
    {
        if (tot == 10)
            tmp[len-1] = 'X';
        else
            tmp[len-1] = tot+'0';
        cout << tmp << endl;
    }
    return 0;
}
