#include <iostream>
using namespace std;
typedef unsigned long long ull;
ull n, ans;
void check(ull col, ull row, ull r, ull l)
{
    if (col == n)
    {
        ans++;
        return;
    }
    for (int i=0,t=1; i < n; i++,t<<=1)
        if (t&(~row)&(~l)&(~r))
            check(col+1,row|t,(r|t)<<1,(l|t)>>1);
}
int main()
{
    while (cin >> n)
    {
        ans = 0;
        check(0,0,0,0);
        cout << ans << endl;
    }
    return 0;
}
