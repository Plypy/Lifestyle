#include <iostream>
using namespace std;
int main()
{
    string dat;
    cin >> dat;
    int sum = 0;
    int i = dat.size()-1;
    while (dat[i] == '0')
        i--;
    for (; i >= 0; i--)
    {
        cout << dat[i];
        sum += dat[i]-'0';
    }
    cout << endl << sum;
    return 0;
}
