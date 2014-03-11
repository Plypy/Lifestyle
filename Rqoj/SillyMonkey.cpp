#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
int ma = 0, mi = 200;
string t;
int ct[30];
bool check(int num)
{
    if (num == 0 || num == 1)
        return false;
    for (int i = 2; i <= sqrt(num); ++i)
        if (num%i == 0)
            return false;
    return true;
}
int main()
{
    cin >> t;
    for (int i = 0; i < t.size(); ++i)
        ++ct[t[i]-'a'];
    for (int i = 0; i < 26; ++i)
    {
        if (ct[i] > ma)
            ma = ct[i];
        if (ct[i] && ct[i] < mi)
            mi = ct[i];
    }
    if (check(ma-mi))
        cout << "Lucky Word" << endl << ma-mi << endl;
    else
        cout << "No Answer" << endl << 0 << endl;
    //system("pause");
    return 0;
}
