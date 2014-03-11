//貌似评测机有问题 
#include <iostream>
#include <cctype>
#include <cmath>
using namespace std;
typedef long long lld;
inline lld gcd(lld a, lld b)
{
    lld c;
    while (b)
    {
        c = a;
        a = b;
        b = c%b;
    }
    return a;
}
inline void read(lld &t)
{
    t = 0;
    char ch;
    do
    {
        cin.get(ch);
    } while(ch == ' ' || ch == '\n');
    lld sign = 1;
    if (ch == '-')
    {
        sign = -1;
        cin.get(ch);
    }
    while (isdigit(ch))
    {
        t = t*10+(ch-'0');
        cin.get(ch);
    }
    t *= sign;
}
inline void cal()
{
    lld a, b, c, d;
    read(a);
    read(b);
    read(c);
    read(d);
    lld son = a*d-c*b;
    lld mom = b*d;
    bool nega = false;
    if (son*mom<0)
    {
        nega = true;
    }
    son = abs(son);
    mom = abs(mom);
    lld div = gcd(son,mom);
    son /= div;
    mom /= div;
    if (nega)
    {
        cout << '-';
    }
    if (son != mom && son)
        cout << son << '/' << mom;
    else
        cout << son;
}
int main()
{
    lld t;
    cin >> t;
    for (lld i = 1; i < t; i++)
    {
        cal();
        cout << endl;
    }
    cal();
    return 0;
}
